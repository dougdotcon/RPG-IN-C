#ifndef COMPONENTES_H
#define COMPONENTES_H

#include "Classes.h"
#include "Areas.h"

#define MAX_ITENS_INV 500

// Declarações de funções
const char* primeiravez();
void inventario(struct Item *itens, int tamanho);
void hunt(struct Item *itens, const struct Area *suaArea, int *tamanho, int progresso);
void perfil(const char* classedef, struct Personagem personagem, char* nome);
void helpmenu();
int identificar_acao(char *comando);

#endif
