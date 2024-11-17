#ifndef QUESTIONARIO_H
#define QUESTIONARIO_H

#include <stdlib.h>
#include <stdio.h>


const char* quizclasse(){ 

  char num1, num2, num3, num4, num5, num6;  
  int guerreiro=0, assassino=0, barbaro=0, ladino=0, clerigo=0, ranger=0, paladino=0, mago=0, bruxo=0, atirador=0, necromante=0, cavaleiro=0, druida=0;
  char tecla; 

  printf("\n\t\t+---------------------------------------------------+");
  printf("\n\t\t|                                                   |");
  printf("\n\t\t|   _______    _______      _______                 |");
  printf("\n\t\t|  (  ____ \\  (  ___  )    |  ___  \\                |");
  printf("\n\t\t|  | (    \\/  | (   ) |    | |   )  )               |");
  printf("\n\t\t|  | |        | |   | |    | |  /  /                |");
  printf("\n\t\t|  | | ____   | |   | |    | | /  /                 |");
  printf("\n\t\t|  | | \\_  )  | |   | |    | | \\  \\                 |");
  printf("\n\t\t|  | (___) |  | (___) |    | |  \\  \\                |");
  printf("\n\t\t|  (_______)  (_______)    | |   \\  \\               |");
  printf("\n\t\t|                                                   |");
  printf("\n\t\t|               Bem-vindo ao RPG                    |");
  printf("\n\t\t|                                                   |");
  printf("\n\t\t+---------------------------------------------------+");
  printf("\n\t\t|   > Pressione O para começar a seleção            |");
  printf("\n\t\t|     de sua classe                                 |");
  printf("\n\t\t|   > Pressione X para sair                         |");
  printf("\n\t\t+---------------------------------------------------+\n");
  printf("\n\t\tEscolha: ");
  scanf(" %c", &tecla); // Adicione um espaço antes de %c para ignorar espaços em branco


  if(tecla == 'x' || tecla == 'X'){
    printf("Saindo da seleção."); 
    return 0;
  } 

  else if (tecla == 'O'|| tecla == 'o'){

    printf("\nResponda as perguntas com honestidade.\n\n");

  // Perguntas parte 1 
    do{    
      printf("1. Qual estilo de combate você prefere?\n"); 
      printf("   a) De perto, corpo a corpo\n"); 
      printf("   b) A distancia, ataques de longo alcance\n");   
      printf("   c) Equilíbrio entre ataque e defesa, com magias de suporte.\n");  
      scanf(" %c", &num1); 

      if (num1 == 'a' || num1 == 'A'){ 
        guerreiro += 10; 
        cavaleiro += 10;
        barbaro += 10;
        paladino += 10; 
        ladino += 10;
        assassino += 10;
      } 
      else if (num1 == 'b' || num1 == 'B'){  
        mago += 15;
        bruxo += 15;
        necromante += 15;
        ranger += 15;
        atirador += 15;
      } 
      else if(num1 == 'c' || num1 == 'C'){ 
        clerigo += 22;
        paladino += 22;
        ranger += 22; 
        druida +=22;
      } 
      else{ 
        printf("Opção inválida, por favor escolha uma opção válida.\n");
      }
    } while(num1 != 'a' && num1 != 'A' && num1 != 'b' && num1 != 'B' && num1 != 'c' && num1 != 'C'); 

    do{
      printf("2.  Você prefere usar armas, magias ou uma combinação de ambos?\n"); 
      printf("   a) Armas, sejam espadas, lanças ou machados.\n"); 
      printf("   b) Magias, conjurando fogo, gelo ou raios.\n"); 
      printf("   c) Uma combinação de armas e magias, adaptando-se à situação.\n");
      scanf(" %c", &num2);  

      if (num2 == 'a' || num2 == 'A'){ 
        guerreiro += 10;  
        cavaleiro += 10;
        barbaro += 10; 
        assassino += 10;
        atirador += 10;
      } 
      else if (num2 == 'b' || num2 == 'B'){  
        mago += 5;
        bruxo += 5;
        necromante += 5;
      } 
      else if(num2 == 'c' || num2 == 'C'){ 
        clerigo += 15; 
        paladino += 15; 
        ranger += 15;  
        ladino += 15; 
        druida +=15;
      }   
      else{ 
        printf("Opção inválida, por favor escolha uma opção válida.\n");
      }
    } while(num2 != 'a' && num2 != 'A' && num2 != 'b' && num2 != 'B' && num2 != 'c' && num2 != 'C');

    do{
      printf("3. Qual é o seu foco principal em combate?\n");
      printf("   a) Proteger seus aliados e liderar a carga.\n"); 
      printf("   b) Eliminar seus inimigos com rapidez e eficiência.\n"); 
      printf("   c) Controlar o campo de batalha e curar seus aliados.\n");
      scanf(" %c", &num3);  

      if (num3 == 'a' || num3 == 'A'){ 
        guerreiro += 5; 
        cavaleiro += 5;
        clerigo += 5;
        paladino += 5;  
        druida += 3;
      } 
      else if (num3 == 'b' || num3 == 'B'){  
        barbaro += 10;
        assassino += 10;
        ranger += 10;
        ladino += 10;  
        druida += 10;
      } 
      else if(num3 == 'c' || num3 == 'C'){ 
        clerigo += 15;
        druida += 15;
        mago += 15; 
        necromante += 15; 
        druida += 15;
      } 
      else{ 
       printf("Opção inválida, por favor escolha uma opção válida.\n");
      }
    } while(num3 != 'a' && num3 != 'A' && num3 != 'b' && num3 != 'B' && num3 != 'c' && num3 != 'C'); 

    do{
      printf("4. De onde vem o seu poder?\n");
        printf("   a) Força física e treinamento específico.\n"); 
        printf("   b) Fé inabalável e devoção a um ideal.\n"); 
        printf("   c) Estudo e conhecimento de magias antigas.\n");
        scanf(" %c", &num4);

        if (num4 == 'a' || num4 == 'A'){ 
          guerreiro += 10; 
          cavaleiro += 10;
          barbaro += 10;
          ranger += 10; 
          assassino += 10;
        } 
        else if (num4 == 'b' || num4 == 'B'){  
          clerigo += 3;
          paladino += 3;
        } 
        else if(num4 == 'c' || num4 == 'C'){ 
          mago += 7;
          bruxo += 7;
          necromante += 7;
          druida += 7;
        } 
        else{ 
         printf("Opção inválida, por favor escolha uma opção válida.\n");
        }
      }while(num4 != 'a' && num4 != 'A' && num4 != 'b' && num4 != 'B' && num4 != 'c' && num4 != 'C'); 

    do{  
      printf("5. Qual a sua inclinação moral?\n"); 
      printf("   a) Bom\n"); 
      printf("   b) Neutro\n");   
      printf("   c) Mau\n"); 
      scanf(" %c", &num5);   

      if (num5 == 'a' || num5 == 'A'){ 
        clerigo += 5;
        paladino += 5;
        ranger += 5;
        cavaleiro += 5;
      } 
      else if (num5 == 'b' || num5 == 'B'){  
        druida += 4;
        ladino += 4;
        ranger += 4;
        assassino += 4;
        barbaro += 4;
      } 
      else if(num5 == 'c' || num5 == 'C'){ 
        bruxo += 8;
        necromante += 8;
      } 
      else{ 
        printf("Opção inválida, por favor escolha uma opção válida.\n");
      }
    } while(num5 != 'a' && num5 != 'A' && num5 != 'b' && num5 != 'B' && num5 != 'c' && num5 != 'C'); 

    do{
      printf("6. O que te motiva a lutar? Você busca justiça, glória, conhecimento, vingança?\n"); 
      printf("   a) Justiça\n"); 
      printf("   b) Glória\n"); 
      printf("   c) Conhecimento\n"); 
      printf("   d) Vingança\n"); 
      printf("   e) Dinheiro\n");

      scanf(" %c", &num6);  

      if (num6 == 'a' || num6 == 'A'){
        clerigo += 8; 
        paladino += 8;  
        ranger  += 8;
      } 
      else if (num6 == 'b' || num6 == 'B'){  
        guerreiro += 10; 
        cavaleiro += 10; 
        barbaro += 10;
      } 
      else if(num6 == 'c' || num6 == 'C'){ 
        mago += 5;
        bruxo += 5;
        druida += 5;
      } 
      else if(num6 == 'd' || num6 == 'D'){ 
        assassino += 15;
      } 
      else if(num1 == 'e' || num6 == 'E'){ 
        ladino += 12;
      }  
      else{ 
        printf("Opção inválida, por favor escolha uma opção válida.\n");
      }
    } while(num6 != 'a' && num6 != 'A' && num6 != 'b' && num6 != 'B' && num6 != 'c' && num6!= 'C' && num6 != 'd' && num6 != 'D' && num6 != 'e' && num6 != 'E');    

    int pontuacoes[] = {guerreiro, assassino, barbaro, ladino, clerigo, ranger, paladino, mago, bruxo, atirador, necromante, cavaleiro, druida};  
    const char* classes[] = {"guerreiro", "assassino", "barbaro", "ladino", "clerigo", "ranger", "paladino", "mago", "bruxo", "atirador", "necromante", "cavaleiro", "druida"}; 
  
    int maiorPontuacao = pontuacoes[0];  
    const char* classedef;
    
    for (int i = 1; i < 13; i++){ 
        if (pontuacoes[i] > maiorPontuacao) {
            maiorPontuacao = pontuacoes[i];
            classedef = classes[i];
        }
    }
  
    printf("\n╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺╺\n");
    printf("Sua classe é: %s", classedef); 
    //retorno = perfil(classedef);

    FILE *arquivo = fopen("Perfil.txt", "a+");  
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return NULL; // Ou outra ação apropriada em caso de erro
    }
    fprintf(arquivo, "Sua classe é %s.\n\n", classedef); 
    fclose(arquivo); 
    
    return classedef; 
  }else{
        printf("Invalido.");  
        return 0; 
  }
 
}
  
#endif