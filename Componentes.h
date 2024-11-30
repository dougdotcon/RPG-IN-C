#include <stdio.h>
#include <string.h>  
#include <stdlib.h> 
#include <time.h>

#include "Classes.h" 
#include "Questionario.c" 
#include "Areas.h"  
           
#define MAX_ITENS_INV 500
  
void inventario(struct Item *itens, int tamanho){
  if(tamanho < 0 || tamanho > MAX_ITENS_INV){
    printf("Tamanho de inventario invalido!");
    return;
  }
  printf("Inventário:\n");
  for (int i = 0; i < tamanho; i++) {
    printf("%s - %d\n", itens[i].nome, itens[i].quantidade);
  }
}
 
/*A função hunt recebe um ponteiro para o struct item e tamanho, permitindo que ela modifique diretamente o conteúdo e o tamanho do inventário fora da função.
  • Se você passasse apenas o array (struct item items[]) ou o valor (int tamanho), a função operaria sobre uma cópia local do array, e as modificações não afetariam o array original.
  • Logo os ponteiros representa uma forma de passagem por referência, onde as modificações feitas dentro da função afetam diretamente os dados fora dela.  
  Então, struct item items[] representa um array de structs "item". Cada elemento do array possui os campos definidos no struct "item". Neste caso, cada elemento terá um campo nome do tipo char, um campo quantidade, def, atk, vida.*/   

void hunt(struct Item *itens, const struct Area *suaArea, int *tamanho, int progresso){

  int qntdrop = 0;
  double dropRate = 0.9; //10% de chance de drop

  //DropRate com base no progresso do jogador
  dropRate += (progresso / 3) * 0.05; //Aumenta 0.5% para cada 3 pontos de progresso

  if(*tamanho >= MAX_ITENS_INV) {
    printf("Inventário cheio!\n");
  } 
  else{
    if (rand() % 101 < dropRate){ 
      strcpy(itens[*tamanho].nome, suaArea->mob.itemDrop);
      itens[*tamanho].quantidade++;
      (*tamanho)++;  
      qntdrop = 1;
    } 
    else{ 
      qntdrop = 0;
    }
    printf("Você obteve %d %s do mob %s. \n", qntdrop, suaArea->mob.itemDrop, suaArea->mob.nome);
  }  
} 

void perfil(const char* classedef, struct Personagem personagem, char* nome){ 

  printf("\n***PERFIL***\n");
  printf("Nome: %s\n", nome); 
  printf("%s\n", classedef);
  printf("Vida: %d\n", personagem.vida);
  printf("Forca: %d\n", personagem.forca);
  printf("Defesa: %d\n", personagem.defesa);
  printf("Level: %d\n", personagem.level);
  
}

void helpmenu(){  
  printf("\nComandos:\n"); 
  printf(".  hunt \n.  help \n.  perfil \n.  inventario \n");
} 

/*Funcao que vai identificar a acao que o jogador quer realizar e mostrar o que aconteceu*/
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
