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

// Declarações de variáveis globais
extern struct Area area1, area2, area3, area4, area5;

// Declarações de funções
struct Area* definirAreaNascimento(const char* classedef);

#endif