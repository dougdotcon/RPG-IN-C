#include "Classes.h"
#include <stdio.h>

// Função auxiliar para inicializar personagem
struct Personagem inicializarPersonagem(int vida, int forca, int defesa) {
  struct Personagem personagem;
  personagem.vida = vida;
  personagem.vida_max = vida;
  personagem.forca = forca;
  personagem.defesa = defesa;
  personagem.level = 1;
  personagem.xp = 0;
  personagem.xp_proximo_level = 100;
  personagem.progresso = 0;
  return personagem;
}

// Funções para inicializar os stats do jogador de acordo com sua classe
struct Personagem criarGuerreiro() {
  return inicializarPersonagem(18, 18, 14);
}

struct Personagem criarAssassino() {
  return inicializarPersonagem(14, 14, 14);
}

struct Personagem criarBarbaro() {
  return inicializarPersonagem(22, 18, 16);
}

struct Personagem criarLadino() {
  return inicializarPersonagem(16, 12, 12);
}

struct Personagem criarClerigo() {
  return inicializarPersonagem(16, 14, 12);
}

struct Personagem criarRange() {
  return inicializarPersonagem(16, 14, 12);
}

struct Personagem criarPaladino() {
  return inicializarPersonagem(18, 16, 14);
}

struct Personagem criarMago() {
  return inicializarPersonagem(16, 10, 8);
}

struct Personagem criarBruxo() {
  return inicializarPersonagem(16, 12, 12);
}

struct Personagem criarAtirador() {
  return inicializarPersonagem(16, 12, 12);
}

struct Personagem criarNecromante() {
  return inicializarPersonagem(16, 10, 12);
}

struct Personagem criarCavaleiro() {
  return inicializarPersonagem(18, 16, 14);
}

struct Personagem criarDruida() {
  return inicializarPersonagem(16, 14, 12);
}

// Funções para gerenciar XP e level
void ganharXP(struct Personagem* personagem, int xp_ganho) {
  personagem->xp += xp_ganho;
  
  // Verificar se pode subir de level
  while (personagem->xp >= personagem->xp_proximo_level) {
    personagem->xp -= personagem->xp_proximo_level;
    personagem->level++;
    
    // Aumentar stats ao subir de level
    personagem->vida_max += 5;
    personagem->vida = personagem->vida_max; // Restaurar vida ao subir de level
    personagem->forca += 2;
    personagem->defesa += 1;
    
    // Aumentar XP necessário para próximo level
    personagem->xp_proximo_level = (int)(personagem->xp_proximo_level * 1.5);
    
    printf("\n*** LEVEL UP! ***\n");
    printf("Você subiu para o level %d!\n", personagem->level);
    printf("Vida: +5, Força: +2, Defesa: +1\n");
    printf("******************\n");
  }
}

struct Personagem criarPersonagem(const char* classedef) {
    if (strcmp(classedef, "guerreiro") == 0) {
        return criarGuerreiro();
    } else if (strcmp(classedef, "assassino") == 0) {
        return criarAssassino();
    } else if (strcmp(classedef, "barbaro") == 0) {
        return criarBarbaro();
    } else if (strcmp(classedef, "ladino") == 0) {
        return criarLadino();
    } else if (strcmp(classedef, "clerigo") == 0) {
        return criarClerigo();
    } else if (strcmp(classedef, "range") == 0) {
        return criarRange();
    } else if (strcmp(classedef, "paladino") == 0) {
        return criarPaladino();
    } else if (strcmp(classedef, "mago") == 0) {
        return criarMago();
    } else if (strcmp(classedef, "bruxo") == 0) {
        return criarBruxo();
    } else if (strcmp(classedef, "atirador") == 0) {
        return criarAtirador();
    } else if (strcmp(classedef, "necromante") == 0) {
        return criarNecromante();
    } else if (strcmp(classedef, "cavaleiro") == 0) {
        return criarCavaleiro();
    } else if (strcmp(classedef, "druida") == 0) {
        return criarDruida();
    } 
    struct Personagem Nenhum;
    // Inicialize 'personagemPadrao' adequadamente
    return Nenhum;
}
