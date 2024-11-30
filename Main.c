
#include <stdio.h>
#include <string.h>  
#include <stdlib.h> 
#include <time.h>

#include "Classes.h" 
#include "Questionario.c" 
#include "Areas.h"  
#include "Componentes.h"  
 
const char* quizclasse(); 
void helpmenu();
int primeiravez(); 

int main(){     

  const char* classeJogador; 
  classeJogador = primeiravez();

  int tamanho = 0;
  int progresso = 0; // Exemplo de progresso do jogador
  char comando[50];    
   
  struct Item items[100];
  const struct Area* areaNascimento = definirAreaNascimento (classeJogador); //Se ela for declarada dentro de um if ou else, por exemplo, ela não estará disponível fora desses blocos.
  const struct Personagem personagemEscolhido = criarPersonagem(classeJogador);  
  
  char* nome; 
  nome = (char *)malloc(50 * sizeof(char)); 

  int tamnome = 0;
  printf("\nDigite seu nome:\n");  
  scanf("%[^\n]s", nome);
  tamnome = strlen(nome); 
  nome = (char *)malloc((tamnome+1) * sizeof(char)); 
  perfil(classeJogador, personagemEscolhido, nome);  
  
 
 
  
 
  
  srand(time(NULL)); //inicializar a semente

  printf("\nDigite um comando: (Para saber um comando válido, digite help)\n"); 
  scanf("%s", comando);  
  
  int acao = identificar_acao(comando); 
  
  while(1){
    switch(acao) {
      case 1:
        hunt(items, areaNascimento, &tamanho, progresso);
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