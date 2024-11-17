#ifndef CLASSES_H
#define CLASSES_H 

#include <string.h>

// Definição da estrutura Personagem
struct Personagem {
  int vida;
  int forca;
  int defesa;
  int level; 
  int progresso;
};

// Funções para inicializar os stats do jogador de acordo com sua classe
struct Personagem criarGuerreiro() {
  struct Personagem guerreiro;
    guerreiro.vida = 18;
    guerreiro.forca = 18;
    guerreiro.defesa = 14;
    guerreiro.level = 1;
    return guerreiro;
}

struct Personagem criarAssassino() {
  struct Personagem assassino;
    assassino.vida = 14;
    assassino.forca = 14;
    assassino.defesa = 14;
    assassino.level = 1;
    return assassino;
}

struct Personagem criarBarbaro() {
  struct Personagem barbaro;
    barbaro.vida = 22;
    barbaro.forca = 18;
    barbaro.defesa = 16;
    barbaro.level = 1;
    return barbaro;
}

struct Personagem criarLadino() {
  struct Personagem ladino;
    ladino.vida = 16;
    ladino.forca = 12;
    ladino.defesa = 12;
    ladino.level = 1;
    return ladino;
}

struct Personagem criarClerigo() {
  struct Personagem clerigo;
    clerigo.vida = 16;
    clerigo.forca = 14;
    clerigo.defesa = 12;
    clerigo.level = 1;
    return clerigo;
}

struct Personagem criarRange() {
  struct Personagem range;
    range.vida = 16;
    range.forca = 14;
    range.defesa = 12;
    range.level = 1;
    return range;
}

struct Personagem criarPaladino() {
  struct Personagem paladino;
    paladino.vida = 18;
    paladino.forca = 16;
    paladino.defesa = 14;
    paladino.level = 1;
    return paladino;
}

struct Personagem criarMago() {
  struct Personagem mago;
    mago.vida = 16;
    mago.forca = 10;
    mago.defesa = 8;
    mago.level = 1;
    return mago;
}

struct Personagem criarBruxo() {
  struct Personagem bruxo;
    bruxo.vida = 16;
    bruxo.forca = 12;
    bruxo.defesa = 12;
    bruxo.level = 1;
    return bruxo;
}

struct Personagem criarAtirador() {
  struct Personagem atirador;
    atirador.vida = 16;
    atirador.forca = 12;
    atirador.defesa = 12;
    atirador.level = 1;
    return atirador;
}

struct Personagem criarNecromante() {
  struct Personagem necromante;
    necromante.vida = 16;
    necromante.forca = 10;
    necromante.defesa = 12;
    necromante.level = 1;
    return necromante;
}

struct Personagem criarCavaleiro() {
  struct Personagem cavaleiro;
    cavaleiro.vida = 18;
    cavaleiro.forca = 16;
    cavaleiro.defesa = 14;
    cavaleiro.level = 1;
    return cavaleiro;
}

struct Personagem criarDruida() {
  struct Personagem druida;
    druida.vida = 16;
    druida.forca = 14;
    druida.defesa = 12;
    druida.level = 1;
    return druida;
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

#endif 