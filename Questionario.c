#ifndef QUESTIONARIO_H
#define QUESTIONARIO_H

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include "CyberpunkStyle.h"


const char* quizclasse(){ 
 
  setlocale(LC_ALL, "Portuguese");
  char num1, num2, num3, num4, num5, num6;  
  int guerreiro=0, assassino=0, barbaro=0, ladino=0, clerigo=0, ranger=0, paladino=0, mago=0, bruxo=0, atirador=0, necromante=0, cavaleiro=0, druida=0;
  char tecla; 
 
  clear_screen();
  print_cyberpunk_header();
  printf("\n");
  print_cyberpunk_border();
  printf(NEON_CYAN "|" BRIGHT_YELLOW "                    [ NEURAL CLASS SELECTION ]                    " NEON_CYAN "|\n");
  printf("|                                                                      |\n");
  printf("|" NEON_GREEN "  > Digite 'O' para iniciar selecao de classe neural              " NEON_CYAN "|\n");
  printf("|" NEON_RED "  > Digite 'X' para desconectar do sistema                       " NEON_CYAN "|\n");
  printf("|                                                                      |\n");
  print_cyberpunk_border_end();
  printf(NEON_YELLOW "\n[SISTEMA] Aguardando comando: " RESET);
 
  scanf(" %c", &tecla); // Adicione um espaço antes de %c para ignorar espaços em branco
 
  const char* classedef = NULL;

  if(tecla == 'x' || tecla == 'X'){
    printf(NEON_RED "\n[SISTEMA] Desconectando interface neural...\n" RESET);
    print_loading_bar(100);
    printf(NEON_RED "\n[SISTEMA] Conexão encerrada.\n" RESET);
    return NULL;
  }

  else if (tecla == 'O'|| tecla == 'o'){
    printf(NEON_GREEN "\n[SISTEMA] Iniciando analise psicologica neural...\n" RESET);
    print_loading_bar(100);
    printf("\n\n");

    print_cyberpunk_border();
    printf(NEON_CYAN "|" NEON_MAGENTA "                    [ ANALISE PSICOLOGICA ]                       " NEON_CYAN "|\n");
    printf("|" BRIGHT_YELLOW "              Responda com honestidade para calibracao             " NEON_CYAN "|\n");
    printf("|                                                                      |\n");
    print_cyberpunk_border_end();
    printf("\n");

    // Perguntas parte 1
    do{
      printf(NEON_CYAN "+======================================================================+\n");
      printf("|" NEON_YELLOW " [Q1] Protocolo de Combate Preferido:                             " NEON_CYAN "|\n");
      printf("|                                                                      |\n");
      printf("|" NEON_GREEN "   [A] Combate corpo-a-corpo / Implantes de forca                 " NEON_CYAN "|\n");
      printf("|" NEON_GREEN "   [B] Combate a distancia / Sistemas de mira neural              " NEON_CYAN "|\n");
      printf("|" NEON_GREEN "   [C] Hibrido tatico / Suporte cibernetico                       " NEON_CYAN "|\n");
      printf("|                                                                      |\n");
      printf("+======================================================================+\n" RESET);
      printf(NEON_YELLOW "[INPUT] Selecione protocolo: " RESET);
      scanf(" %c", &num1);

      if (num1 == 'a' || num1 == 'A'){ 
        guerreiro += 10; 
        cavaleiro += 10;
        barbaro += 10;
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
        printf(NEON_RED "[ERRO] Protocolo inválido. Recalibrando...\n" RESET);
      }
    } while(num1 != 'a' && num1 != 'A' && num1 != 'b' && num1 != 'B' && num1 != 'c' && num1 != 'C');

    do{
      printf(NEON_CYAN "\n+======================================================================+\n");
      printf("|" NEON_YELLOW " [Q2] Sistema de Armamento Preferido:                             " NEON_CYAN "|\n");
      printf("|                                                                      |\n");
      printf("|" NEON_GREEN "   [A] Armas fisicas / Implantes de combate                       " NEON_CYAN "|\n");
      printf("|" NEON_GREEN "   [B] Sistemas energeticos / Hacking neural                      " NEON_CYAN "|\n");
      printf("|" NEON_GREEN "   [C] Arsenal hibrido / Adaptacao situacional                    " NEON_CYAN "|\n");
      printf("|                                                                      |\n");
      printf("+======================================================================+\n" RESET);
      printf(NEON_YELLOW "[INPUT] Selecione armamento: " RESET);
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
        printf(NEON_RED "[ERRO] Armamento inválido. Recalibrando...\n" RESET);
      }
    } while(num2 != 'a' && num2 != 'A' && num2 != 'b' && num2 != 'B' && num2 != 'c' && num2 != 'C');

    do{
      printf(NEON_CYAN "\n+======================================================================+\n");
      printf("|" NEON_YELLOW " [Q3] Protocolo Tatico Principal:                                 " NEON_CYAN "|\n");
      printf("|                                                                      |\n");
      printf("|" NEON_GREEN "   [A] Protecao de equipe / Lideranca tatica                      " NEON_CYAN "|\n");
      printf("|" NEON_GREEN "   [B] Eliminacao rapida / Eficiencia letal                       " NEON_CYAN "|\n");
      printf("|" NEON_GREEN "   [C] Controle de campo / Suporte medico                          " NEON_CYAN "|\n");
      printf("|                                                                      |\n");
      printf("+======================================================================+\n" RESET);
      printf(NEON_YELLOW "[INPUT] Selecione tática: " RESET);
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
       printf("Opcao invalida, por favor escolha uma opcao valida.\n");
      }
    } while(num3 != 'a' && num3 != 'A' && num3 != 'b' && num3 != 'B' && num3 != 'c' && num3 != 'C'); 

    do{
      printf("4. De onde vem o seu poder?\n");
        printf("   a) Forca fisica e treinamento especifico.\n"); 
        printf("   b) Fe inabalavel e/ou devocao a um ideal.\n"); 
        printf("   c) Estudo e conhecimento.\n");
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
         printf("Opcao invalida, por favor escolha uma opcao valida.\n");
        }
      }while(num4 != 'a' && num4 != 'A' && num4 != 'b' && num4 != 'B' && num4 != 'c' && num4 != 'C'); 

    do{  
      printf("5. Qual a sua inclinacao moral?\n"); 
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
        printf("Opcao invalida, por favor escolha uma opcao valida.\n");
      }
    } while(num5 != 'a' && num5 != 'A' && num5 != 'b' && num5 != 'B' && num5 != 'c' && num5 != 'C'); 

    do{
      printf("6. O que te motiva a lutar? Voce busca justica, gloria, conhecimento, vinganca?\n"); 
      printf("   a) Justica\n"); 
      printf("   b) Gloria\n"); 
      printf("   c) Conhecimento\n"); 
      printf("   d) Vinganca\n"); 
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
      else if(num6 == 'e' || num6 == 'E'){
        ladino += 12;
      }
      else{ 
        printf("Opcao invalida, por favor escolha uma opcao valida.\n");
      }
    }  
    while(num6 != 'a' && num6 != 'A' && num6 != 'b' && num6 != 'B' && num6 != 'c' && num6!= 'C' && num6 != 'd' && num6 != 'D' && num6 != 'e' && num6 != 'E');    

    int pontuacoes[] = {guerreiro, assassino, barbaro, ladino, clerigo, ranger, paladino, mago, bruxo, atirador, necromante, cavaleiro, druida};  
    const char* classes[] = {"guerreiro", "assassino", "barbaro", "ladino", "clerigo", "ranger", "paladino", "mago", "bruxo", "atirador", "necromante", "cavaleiro", "druida"}; 
  
    int maiorPontuacao = pontuacoes[0];  
    classedef = classes[0];
    
    for (int i = 0; i < 13; i++){ // Corrigido para 13 classes
      if (pontuacoes[i] > maiorPontuacao) {
        maiorPontuacao = pontuacoes[i];
        classedef = classes[i];
      }
    }
  
    printf("\n");
    print_cyberpunk_border();
    printf(NEON_CYAN "|" NEON_MAGENTA "                    [ ANALISE COMPLETA ]                          " NEON_CYAN "|\n");
    printf("|                                                                      |\n");
    printf("|" NEON_GREEN "  Classe Neural Detectada: " NEON_YELLOW "%-32s" NEON_CYAN "|\n", classedef);
    printf("|                                                                      |\n");
    printf("|" BRIGHT_YELLOW "              [ CALIBRACAO NEURAL CONCLUIDA ]                     " NEON_CYAN "|\n");
    print_cyberpunk_border_end();

    FILE *arquivo = fopen("Perfil.txt", "a+");  
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return NULL; // Ou outra ação apropriada em caso de erro
    }
    fprintf(arquivo, "Sua classe é %s.\n\n", classedef); 
    fclose(arquivo); 
     
  }  
  return classedef;   
}
  
#endif 
 
/*Retorna um ponteiro para uma string (const char*).  
    a variável classedef aponta para um elemento do array estático classes, que é seguro pq 
    o array classes tem duração de vida estática e permanece válido durante toda a execução do programa.
    Porém, em outros cenários, pode surgir um problema se tentar retornar um ponteiro para uma variável 
    local ou para uma string alocada na stack (pilha). Isso porque variáveis locais têm duração limitada  
    ao escopo em que foram declaradas. Assim que a função retorna, as variáveis locais deixam de existir,  
    e qualquer ponteiro que as referencie passa a ser inválido, levando a comportamento indefinido*/