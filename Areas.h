#ifndef AREAS_H
#define AREAS_H 

#include <stdio.h>
#include <string.h> 

struct Item{
  char nome[50];
  int quantidade;
  int def, atk, vida;
}; 

struct Mob{
  char nome[50], itemDrop[100];
}; 

struct Area{
  char nome[50];
  struct Mob mob;  
  char descricao[100]; 
};
 
struct Area area1 = {"Castle Town", {"Gárgula", "Assas de Gárgula"},"Descrição de Castle Town"}; 
struct Area area2 = {"Forest", {"Dragão", "Escama de Dragão"},"Descrição de Florest"};
struct Area area3 = {"Aetheria", {"Manticore", "Veneno"},"Descrição de Aetheria"}; 
struct Area area4 = {"Aztlan", {"Gigante de pedra", "Cristais"},"Descrição de Aztlan"}; 
struct Area area5 = {"Tenebris", {"Peixe", "Escama"},"Descrição de Tenebris"}; 

struct Area* definirAreaNascimento(const char* classedef){   
  struct Area* suaArea; 

    if (strcmp(classedef, "Guerreiro") == 0 || strcmp(classedef, "Arqueiro") == 0 ||
      strcmp(classedef, "Ranger") == 0 || strcmp(classedef, "Paladino") == 0 ||
      strcmp(classedef, "Atirador") == 0 || strcmp(classedef, "cavaleiro") == 0) {
      suaArea = &area1;
    }  
    else if (strcmp(classedef, "Assassino") == 0 || strcmp(classedef, "Bárbaro") == 0 ||
      strcmp(classedef, "Ladino") == 0) {
      suaArea = &area4;
    }  
    else if (strcmp(classedef, "Bruxo") == 0 || strcmp(classedef, "mago") == 0) {
      suaArea = &area3;
    }  
    else if (strcmp(classedef, "Necromante") == 0) {
      suaArea = &area5;
    }  
    else if (strcmp(classedef, "Druida") == 0) {
      suaArea = &area2;
    }   
    if (suaArea == NULL) {
      printf("Erro: Classe não reconhecida.\n");
      return NULL;
    } 

  FILE *arquivo = fopen("Perfil.txt", "a+");  
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return NULL; // Ou outra ação apropriada em caso de erro
  } 
  printf("\n\nAtenção!\n\tSeu destino está entrelaçado com o local de onde você vem. Logo você nasceu e foi criado(a) em %s. As terras de %s moldaram você, concedendo-lhe as habilidades e conhecimentos únicos que definem sua classe.\n\n", suaArea->nome, suaArea->nome); 
  fprintf(arquivo, "\nAtenção!\nSeu destino está entrelaçado com o local de onde você vem. Logo, você nasceu e foi criado(a) em %s. As terras de %s moldaram você, concedendo-lhe as habilidades e conhecimentos únicos que definem sua classe.\n\n", suaArea->nome, suaArea->nome); 
  fclose(arquivo);  
  
  return suaArea;
}
 #endif 