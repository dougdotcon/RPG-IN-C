#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Componentes.h"
#include "Questionario.h"

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
  printf("Digite 'usar' para usar um item.\n");
}

void usar_item(struct Item *itens, int *tamanho, struct Personagem* personagem) {
  if (*tamanho == 0) {
    printf("Seu inventário está vazio!\n");
    return;
  }

  printf("Qual item você quer usar? (Digite o número): ");
  int escolha;
  scanf("%d", &escolha);

  if (escolha < 1 || escolha > *tamanho) {
    printf("Item inválido!\n");
    return;
  }

  int index = escolha - 1;
  struct Item item = itens[index];

  printf("Usando %s...\n", item.nome);

  // Aplicar efeitos do item
  if (item.vida > 0) {
    int vida_recuperada = item.vida;
    if (personagem->vida + vida_recuperada > personagem->vida_max) {
      vida_recuperada = personagem->vida_max - personagem->vida;
    }
    personagem->vida += vida_recuperada;
    printf("Você recuperou %d pontos de vida!\n", vida_recuperada);
  }

  if (item.atk > 0) {
    personagem->forca += item.atk;
    printf("Sua força aumentou em %d pontos!\n", item.atk);
  }

  if (item.def > 0) {
    personagem->defesa += item.def;
    printf("Sua defesa aumentou em %d pontos!\n", item.def);
  }

  // Remover item do inventário
  itens[index].quantidade--;
  if (itens[index].quantidade <= 0) {
    // Mover todos os itens uma posição para trás
    for (int i = index; i < *tamanho - 1; i++) {
      itens[i] = itens[i + 1];
    }
    (*tamanho)--;
  }
}

void hunt(struct Item *itens, const struct Area *suaArea, int *tamanho, struct Personagem* personagem){
  int qntdrop = 0;
  double dropRate = 10.0; // 10% de chance de drop
  int xp_ganho = 15 + (rand() % 10); // XP base + aleatório

  //DropRate com base no progresso do jogador
  dropRate += (personagem->progresso / 3) * 5.0; //Aumenta 5% para cada 3 pontos de progresso

  printf("Você caçou um %s!\n", suaArea->mob.nome);

  // Sempre ganha XP ao caçar
  ganharXP(personagem, xp_ganho);
  printf("Você ganhou %d XP!\n", xp_ganho);

  if(*tamanho >= MAX_ITENS_INV) {
    printf("Inventário cheio! Não foi possível coletar item.\n");
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
      printf("Você obteve: %s!\n", suaArea->mob.itemDrop);
    }
    else{
      qntdrop = 0;
      printf("Nenhum item foi dropado desta vez.\n");
    }
  }
}

void perfil(const char* classedef, struct Personagem personagem, char* nome){
  printf("\n=== PERFIL ===\n");
  printf("Nome: %s\n", nome);
  printf("Classe: %s\n", classedef);
  printf("Level: %d\n", personagem.level);
  printf("Vida: %d/%d\n", personagem.vida, personagem.vida_max);
  printf("Força: %d\n", personagem.forca);
  printf("Defesa: %d\n", personagem.defesa);
  printf("XP: %d/%d\n", personagem.xp, personagem.xp_proximo_level);
  printf("Progresso: %d\n", personagem.progresso);
  printf("==============\n");
}

void mostrar_area(const struct Area* area) {
  printf("\n=== ÁREA ATUAL ===\n");
  printf("Local: %s\n", area->nome);
  printf("Descrição: %s\n", area->descricao);
  printf("Monstro: %s\n", area->mob.nome);
  printf("Drop: %s\n", area->mob.itemDrop);
  printf("==================\n");
}

void salvar_jogo(const char* nome, const char* classe, struct Personagem personagem, struct Item* itens, int tamanho_inv) {
  FILE* arquivo = fopen("savegame.dat", "w");
  if (arquivo == NULL) {
    printf("Erro ao salvar o jogo!\n");
    return;
  }

  // Salvar dados do personagem
  fprintf(arquivo, "%s\n", nome);
  fprintf(arquivo, "%s\n", classe);
  fprintf(arquivo, "%d %d %d %d %d %d %d %d\n",
          personagem.vida, personagem.vida_max, personagem.forca,
          personagem.defesa, personagem.level, personagem.xp,
          personagem.xp_proximo_level, personagem.progresso);

  // Salvar inventário
  fprintf(arquivo, "%d\n", tamanho_inv);
  for (int i = 0; i < tamanho_inv; i++) {
    fprintf(arquivo, "%s %d %d %d %d\n",
            itens[i].nome, itens[i].quantidade,
            itens[i].atk, itens[i].def, itens[i].vida);
  }

  fclose(arquivo);
  printf("Jogo salvo com sucesso!\n");
}

int carregar_jogo(char* nome, char* classe, struct Personagem* personagem, struct Item* itens, int* tamanho_inv) {
  FILE* arquivo = fopen("savegame.dat", "r");
  if (arquivo == NULL) {
    return 0; // Arquivo não existe
  }

  // Carregar dados do personagem
  fgets(nome, 100, arquivo);
  nome[strcspn(nome, "\n")] = 0; // Remover quebra de linha

  fgets(classe, 50, arquivo);
  classe[strcspn(classe, "\n")] = 0; // Remover quebra de linha

  fscanf(arquivo, "%d %d %d %d %d %d %d %d\n",
         &personagem->vida, &personagem->vida_max, &personagem->forca,
         &personagem->defesa, &personagem->level, &personagem->xp,
         &personagem->xp_proximo_level, &personagem->progresso);

  // Carregar inventário
  fscanf(arquivo, "%d\n", tamanho_inv);
  for (int i = 0; i < *tamanho_inv; i++) {
    fscanf(arquivo, "%s %d %d %d %d\n",
           itens[i].nome, &itens[i].quantidade,
           &itens[i].atk, &itens[i].def, &itens[i].vida);
  }

  fclose(arquivo);
  return 1; // Sucesso
}

void helpmenu(){
  printf("\n=== COMANDOS DISPONÍVEIS ===\n");
  printf("hunt       - Caçar monstros na área atual\n");
  printf("help       - Mostrar este menu de ajuda\n");
  printf("perfil     - Ver informações do personagem\n");
  printf("inventario - Ver itens no inventário\n");
  printf("usar       - Usar um item do inventário\n");
  printf("area       - Ver informações da área atual\n");
  printf("salvar     - Salvar o jogo\n");
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
  else if(strcmp(comando, "usar")==0){
    return 5;
  }
  else if(strcmp(comando, "area")==0){
    return 6;
  }
  else if(strcmp(comando, "salvar")==0){
    return 7;
  }
  return 0;
}
