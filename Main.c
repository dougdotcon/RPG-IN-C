
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Classes.h"
#include "Areas.h"
#include "Componentes.h"

const char* quizclasse();

int main(){

  const char* classeJogador;
  char nome[100]; // Buffer fixo para evitar problemas de memória
  char classe_str[50]; // Para armazenar classe como string
  int tamanho = 0;
  char comando[50];

  struct Item items[100];
  struct Personagem personagemEscolhido;

  // Tentar carregar jogo salvo
  if (carregar_jogo(nome, classe_str, &personagemEscolhido, items, &tamanho)) {
    printf("Jogo carregado com sucesso!\n");
    printf("Bem-vindo de volta, %s!\n", nome);
    classeJogador = classe_str;
  } else {
    // Novo jogo
    classeJogador = primeiravez();
    personagemEscolhido = criarPersonagem(classeJogador);

    // Limpar buffer de entrada antes de ler o nome
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nDigite seu nome:\n");
    fgets(nome, sizeof(nome), stdin);

    // Remover quebra de linha se presente
    size_t len = strlen(nome);
    if (len > 0 && nome[len-1] == '\n') {
      nome[len-1] = '\0';
    }
    strcpy(classe_str, classeJogador);
  }

  const struct Area* areaNascimento = definirAreaNascimento(classeJogador);
  perfil(classeJogador, personagemEscolhido, nome);
  
 
 
  
 
  
  srand(time(NULL)); //inicializar a semente

  printf("\nDigite um comando: (Para saber um comando válido, digite help)\n"); 
  scanf("%s", comando);  
  
  int acao = identificar_acao(comando); 
  
  while(1){
    switch(acao) {
      case 1:
        hunt(items, areaNascimento, &tamanho, &personagemEscolhido);
        break;
      case 2:
        helpmenu();
        break;
      case 3:
        perfil(classeJogador, personagemEscolhido, nome);
        break;
      case 4:
        inventario(items, tamanho);
        break;
      case 5:
        usar_item(items, &tamanho, &personagemEscolhido);
        break;
      case 6:
        mostrar_area(areaNascimento);
        break;
      case 7:
        salvar_jogo(nome, classeJogador, personagemEscolhido, items, tamanho);
        break;
      default:
        printf("Comando inválido.\n");
        break;
    }

    printf("\n\nDigite um comando: (Para saber um comando válido, digite help)\n"); 
    scanf("%s", comando);  
    acao = identificar_acao(comando);
  }
  
  return 0;
}