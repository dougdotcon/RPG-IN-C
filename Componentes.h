#ifndef COMPONENTES_H
#define COMPONENTES_H

#include "Classes.h"
#include "Areas.h"

#define MAX_ITENS_INV 500

// Declarações de funções
const char* primeiravez();
void inventario(struct Item *itens, int tamanho);
void usar_item(struct Item *itens, int *tamanho, struct Personagem* personagem);
void hunt(struct Item *itens, const struct Area *suaArea, int *tamanho, struct Personagem* personagem);
void perfil(const char* classedef, struct Personagem personagem, char* nome);
void mostrar_area(const struct Area* area);
void salvar_jogo(const char* nome, const char* classe, struct Personagem personagem, struct Item* itens, int tamanho_inv);
int carregar_jogo(char* nome, char* classe, struct Personagem* personagem, struct Item* itens, int* tamanho_inv);
void helpmenu();
int identificar_acao(char *comando);

#endif
