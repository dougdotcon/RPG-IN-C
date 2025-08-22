#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Classes.h"
#include "Areas.h"
#include "Questionario.h"

#define MAX_ITENS_INV 500

const char* primeiravez(){ //Função para verificar se o jogador já jogou ou é a primeira vez.
  const char* classeJogador; 
  FILE *arquivo1; 
  arquivo1 = fopen("config.txt", "r"); 

  if (arquivo1 == NULL){ //Não existe o arquivo, então cria ele e define como primeira vez, ou seja, 0.
    arquivo1 = fopen("config.txt", "w");  

    if (arquivo1 == NULL) {
      printf("Erro ao criar o arquivo de configuração.\n");
      return NULL;
    } 

    fprintf(arquivo1, "0");
    fclose(arquivo1);  

    classeJogador = quizclasse(); 
     
    arquivo1 = fopen("config.txt", "w+"); 

    if (arquivo1 == NULL) {
      printf("Erro ao atualizar o arquivo de configuração.\n");
      return NULL;
    } 

    fprintf(arquivo1, "1");
    fclose(arquivo1);
  } 
  else{ //Lê o arquivo existente para verificar o estado 
    int primeira_vez;
    fscanf(arquivo1, "%d", &primeira_vez); 
    fclose(arquivo1);

    if (primeira_vez == 0){ //O documento existe mas o quest não foi concluido então roda o questionário.
      printf("Bem-vindo novamente! Conclua o questionário.\n");
      classeJogador = quizclasse();

      // Atualiza o arquivo para indicar que não é mais a primeira vez
      arquivo1 = fopen("config.txt", "w+");
      if (arquivo1 == NULL) {
        printf("Erro ao atualizar o arquivo de configuração.\n");
        return NULL;
      }
      fprintf(arquivo1, "1");
      fclose(arquivo1);
    }  
    else {
      // Não é a primeira vez, então roda apenas o menu
      printf("Bem-vindo de volta!\n");
      helpmenu();
    }
  }
  return classeJogador; 
}

void inventario(struct Item *itens, int tamanho){
  if(tamanho < 0 || tamanho > MAX_ITENS_INV){
    printf("Tamanho de inventario invalido!");
    return;
  }
  printf("\n=== INVENTÁRIO ===\n");
  if (tamanho == 0) {
    printf("Seu inventário está vazio.\n");
    return;
  }
  
  for (int i = 0; i < tamanho; i++) {
    printf("%d. %s - Quantidade: %d\n", i+1, itens[i].nome, itens[i].quantidade);
    if (itens[i].atk > 0 || itens[i].def > 0 || itens[i].vida > 0) {
      printf("   Stats: ATK:%d DEF:%d VIDA:%d\n", itens[i].atk, itens[i].def, itens[i].vida);
    }
  }
  printf("==================\n");
}

void hunt(struct Item *itens, const struct Area *suaArea, int *tamanho, int progresso){
  int qntdrop = 0;
  double dropRate = 10.0; // 10% de chance de drop

  //DropRate com base no progresso do jogador
  dropRate += (progresso / 3) * 5.0; //Aumenta 5% para cada 3 pontos de progresso

  if(*tamanho >= MAX_ITENS_INV) {
    printf("Inventário cheio!\n");
  } 
  else{
    if ((rand() % 100) < (int)dropRate){ 
      strcpy(itens[*tamanho].nome, suaArea->mob.itemDrop);
      itens[*tamanho].quantidade = 1;
      itens[*tamanho].atk = rand() % 5 + 1; // Stats aleatórios básicos
      itens[*tamanho].def = rand() % 3 + 1;
      itens[*tamanho].vida = rand() % 10 + 1;
      (*tamanho)++;  
      qntdrop = 1;
    } 
    else{ 
      qntdrop = 0;
    }
    printf("Você caçou um %s e obteve %d %s.\n", suaArea->mob.nome, qntdrop, suaArea->mob.itemDrop);
  }  
}

void perfil(const char* classedef, struct Personagem personagem, char* nome){ 
  printf("\n***PERFIL***\n");
  printf("Nome: %s\n", nome); 
  printf("Classe: %s\n", classedef);
  printf("Vida: %d\n", personagem.vida);
  printf("Força: %d\n", personagem.forca);
  printf("Defesa: %d\n", personagem.defesa);
  printf("Level: %d\n", personagem.level);
  printf("Progresso: %d\n", personagem.progresso);
  printf("*************\n");
}

void helpmenu(){  
  printf("\n=== COMANDOS DISPONÍVEIS ===\n"); 
  printf("hunt      - Caçar monstros na área atual\n");
  printf("help      - Mostrar este menu de ajuda\n");
  printf("perfil    - Ver informações do personagem\n");
  printf("inventario - Ver itens no inventário\n");
  printf("============================\n");
} 

int identificar_acao(char *comando){
  if(strcmp(comando, "hunt")==0){
    return 1;
  } 
  else if(strcmp(comando, "help")==0){
    return 2;
  }  
  else if(strcmp(comando, "perfil")==0){ 
    return 3;
  } 
  else if(strcmp(comando, "inventario")==0){ 
    return 4;
  }
  return 0;
}
