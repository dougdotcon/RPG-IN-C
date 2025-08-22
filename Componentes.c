#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Componentes.h"
#include "Questionario.h"
#include "CyberpunkStyle.h"

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
    printf(NEON_RED "[ERRO] Tamanho de inventário inválido!\n" RESET);
    return;
  }

  printf("\n");
  print_cyberpunk_border();
  printf(NEON_CYAN "|" NEON_MAGENTA "                      [ INVENTARIO NEURAL ]                       " NEON_CYAN "|\n");
  printf("|                                                                      |\n");

  if (tamanho == 0) {
    printf("|" BRIGHT_YELLOW "                    [ INVENTARIO VAZIO ]                          " NEON_CYAN "|\n");
    printf("|                                                                      |\n");
  } else {
    for (int i = 0; i < tamanho; i++) {
      printf("|" NEON_GREEN " [%02d] %-20s" NEON_YELLOW " QTD: %02d                        " NEON_CYAN "|\n",
             i+1, itens[i].nome, itens[i].quantidade);
      if (itens[i].atk > 0 || itens[i].def > 0 || itens[i].vida > 0) {
        printf("|" BRIGHT_CYAN "      ATK:%02d DEF:%02d VIDA:%02d                                  " NEON_CYAN "|\n",
               itens[i].atk, itens[i].def, itens[i].vida);
      }
      printf("|                                                                      |\n");
    }
  }

  printf("|" BRIGHT_YELLOW "                Digite 'usar' para ativar item                    " NEON_CYAN "|\n");
  print_cyberpunk_border_end();
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

  printf("\n");
  print_cyberpunk_border();
  printf(NEON_CYAN "|" NEON_MAGENTA "                      [ COMBATE NEURAL ]                          " NEON_CYAN "|\n");
  printf("|                                                                      |\n");
  printf("|" NEON_RED " TARGET ACQUIRED: " NEON_YELLOW "%-42s" NEON_CYAN "|\n", suaArea->mob.nome);
  printf("|" NEON_GREEN " COMBAT STATUS: " BRIGHT_GREEN "ENGAGED                                   " NEON_CYAN "|\n");
  printf("|                                                                      |\n");

  // Sempre ganha XP ao caçar
  ganharXP(personagem, xp_ganho);
  printf("|" NEON_CYAN " XP GAINED: " BRIGHT_YELLOW "+%02d                                          " NEON_CYAN "|\n", xp_ganho);
  printf("|                                                                      |\n");

  if(*tamanho >= MAX_ITENS_INV) {
    printf("|" NEON_RED " INVENTORY FULL: Cannot collect loot                           " NEON_CYAN "|\n");
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
      printf("|" NEON_GREEN " LOOT ACQUIRED: " BRIGHT_CYAN "%-38s" NEON_CYAN "|\n", suaArea->mob.itemDrop);
    }
    else{
      qntdrop = 0;
      printf("|" BRIGHT_YELLOW " NO LOOT DETECTED                                          " NEON_CYAN "|\n");
    }
  }

  printf("|                                                                      |\n");
  printf("|" BRIGHT_GREEN " COMBAT COMPLETE                                               " NEON_CYAN "|\n");
  print_cyberpunk_border_end();
}

void perfil(const char* classedef, struct Personagem personagem, char* nome){
  printf("\n");
  print_cyberpunk_border();
  printf(NEON_CYAN "|" NEON_MAGENTA "                      [ PERFIL NEURAL ]                           " NEON_CYAN "|\n");
  printf("|                                                                      |\n");
  printf("|" NEON_GREEN " OPERADOR: " BRIGHT_WHITE "%-50s" NEON_CYAN "|\n", nome);
  printf("|" NEON_GREEN " CLASSE: " BRIGHT_YELLOW "%-52s" NEON_CYAN "|\n", classedef);
  printf("|                                                                      |\n");
  printf("|" NEON_CYAN " LEVEL: " BRIGHT_CYAN "%02d" NEON_CYAN "                                                   |\n", personagem.level);
  printf("|" NEON_RED " VIDA: " BRIGHT_RED "%03d" NEON_RED "/" BRIGHT_RED "%03d" NEON_CYAN "                                              |\n",
         personagem.vida, personagem.vida_max);
  printf("|" NEON_YELLOW " FORCA: " BRIGHT_YELLOW "%02d" NEON_CYAN "                                                   |\n", personagem.forca);
  printf(NEON_CYAN "|");
  printf(CYBER_BLUE " DEFESA: ");
  printf(BRIGHT_BLUE "%02d", personagem.defesa);
  printf(NEON_CYAN "                                                  |\n" RESET);
  printf("|                                                                      |\n");
  printf("|" NEON_MAGENTA " XP: " BRIGHT_MAGENTA "%04d" NEON_MAGENTA "/" BRIGHT_MAGENTA "%04d" NEON_CYAN "                                             |\n",
         personagem.xp, personagem.xp_proximo_level);
  printf("|" NEON_GREEN " PROGRESSO: " BRIGHT_GREEN "%02d" NEON_CYAN "                                             |\n", personagem.progresso);
  printf("|                                                                      |\n");
  print_cyberpunk_border_end();
}

void mostrar_area(const struct Area* area) {
  printf("\n");
  print_cyberpunk_border();
  printf(NEON_CYAN "|" NEON_MAGENTA "                     [ SCAN DE AREA ]                            " NEON_CYAN "|\n");
  printf("|                                                                      |\n");
  printf("|" NEON_GREEN " LOCALIZACAO: " BRIGHT_WHITE "%-46s" NEON_CYAN "|\n", area->nome);
  printf("|" NEON_YELLOW " DESCRICAO: " BRIGHT_YELLOW "%-48s" NEON_CYAN "|\n", area->descricao);
  printf("|                                                                      |\n");
  printf("|" NEON_RED " HOSTIL DETECTADO: " BRIGHT_RED "%-41s" NEON_CYAN "|\n", area->mob.nome);
  printf("|" NEON_CYAN " LOOT DISPONIVEL: " BRIGHT_CYAN "%-42s" NEON_CYAN "|\n", area->mob.itemDrop);
  printf("|                                                                      |\n");
  printf("|" BRIGHT_YELLOW "                    [ SCAN COMPLETO ]                          " NEON_CYAN "|\n");
  print_cyberpunk_border_end();
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
  printf("\n");
  print_cyberpunk_border();
  printf(NEON_CYAN "|" NEON_MAGENTA "                    [ COMANDOS NEURAIS ]                          " NEON_CYAN "|\n");
  printf("|                                                                      |\n");
  printf("|" NEON_GREEN " hunt       " BRIGHT_WHITE "- Engajar hostis na area atual                      " NEON_CYAN "|\n");
  printf("|" NEON_GREEN " help       " BRIGHT_WHITE "- Exibir interface de comandos                      " NEON_CYAN "|\n");
  printf("|" NEON_GREEN " perfil     " BRIGHT_WHITE "- Acessar dados do operador                         " NEON_CYAN "|\n");
  printf("|" NEON_GREEN " inventario " BRIGHT_WHITE "- Verificar inventario neural                       " NEON_CYAN "|\n");
  printf("|" NEON_GREEN " usar       " BRIGHT_WHITE "- Ativar item do inventario                         " NEON_CYAN "|\n");
  printf("|" NEON_GREEN " area       " BRIGHT_WHITE "- Escanear area atual                               " NEON_CYAN "|\n");
  printf("|" NEON_GREEN " salvar     " BRIGHT_WHITE "- Salvar dados na memoria                           " NEON_CYAN "|\n");
  printf("|                                                                      |\n");
  printf("|" BRIGHT_YELLOW "                  [ INTERFACE ATIVA ]                          " NEON_CYAN "|\n");
  print_cyberpunk_border_end();
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
