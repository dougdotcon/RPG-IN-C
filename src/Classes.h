#ifndef CLASSES_H
#define CLASSES_H

#include <string.h>

// Definição da estrutura Personagem
struct Personagem {
  int vida;
  int vida_max;
  int forca;
  int defesa;
  int level;
  int xp;
  int xp_proximo_level;
  int progresso;
};

// Declarações de funções
struct Personagem inicializarPersonagem(int vida, int forca, int defesa);
struct Personagem criarGuerreiro();
struct Personagem criarAssassino();
struct Personagem criarBarbaro();
struct Personagem criarLadino();
struct Personagem criarClerigo();
struct Personagem criarRange();
struct Personagem criarPaladino();
struct Personagem criarMago();
struct Personagem criarBruxo();
struct Personagem criarAtirador();
struct Personagem criarNecromante();
struct Personagem criarCavaleiro();
struct Personagem criarDruida();
void ganharXP(struct Personagem* personagem, int xp_ganho);
struct Personagem criarPersonagem(const char* classedef);

#endif