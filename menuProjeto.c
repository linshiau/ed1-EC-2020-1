#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 main()
{
int opcao;
    inicio:
    system("cls");
    system("color 0F");
    printf("1 - MULTIPLICACAO DE MATRIZES \n2 - SOMA DE MATRIZES \n3 - ESCALONAMENTO DE MATRIZ \n4 - MATRIZ INVERSA\n5 - MULTIPLICACAO POR ESCALAR \n6 - MATRIZ TRANSPOSTA \n7 - SUBTRACAO DE MATRIZES \n8 - SAIR");
    opcao = getch();
    switch (opcao) {
    case '1':
        system("cls");

            int i1, j1, i2, j2, i, j, k, m1[50][50], m2[50][50], m3[50][50];

              printf("\n==========MULTIPLICACAO DE MATRIZES==========\n");
              printf("\nMatriz 1\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i1);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j1);
              printf("\nMatriz 2\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i2);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j2);
              if (j1 == i2) {
                printf("\nValores da Matriz 1\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for(j=0; j<j1; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m1[i][j]);
                  }
                }
                printf("\nValores da Matriz 2\n=====================\n\n");
                for (i=0; i<i2; i++) {
                  for (j=0; j<j2; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m2[i][j]);
                  }
                }
                for (i=0;i<i1; i++) {
                  for (j=0; j<i1; j++) {
                    for (k=0; k<j1; k++) {
                      m3[i][j] = m3[i][j] + (m1[i][k] * m2[k][j]);
                    }
                  }
                }
                printf("\nMatriz 3\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for (j=0; j<j2; j++) {
                    printf("%d ", m3[i][j]);
                  }
                  printf("\n");
                }
                printf("\n");
              }
              else {
                  printf("\nErro! Impossivel multiplicar as matrizes informadas.\n");
                }
              return(0);
        break;
    case '2':
        system("cls");

        printf("\n==========SOMA DE MATRIZES==========\n");
              printf("\nMatriz 1\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i1);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j1);
              printf("\nMatriz 2\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i2);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j2);
              if (j1 == i2) {
                printf("\nValores da Matriz 1\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for(j=0; j<j1; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m1[i][j]);
                  }
                }
                printf("\nValores da Matriz 2\n=====================\n\n");
                for (i=0; i<i2; i++) {
                  for (j=0; j<j2; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m2[i][j]);
                  }
                }
                for (i=0;i<i1; i++) {
                  for (j=0; j<i1; j++) {
                      m3[i][j] = m3[i][j] + (m1[i][j] + m2[i][j]);
                  }
                }
                printf("\nMatriz 3\n=====================\n\n");

                for (i=0; i<i1; i++) {
                  for (j=0; j<j2; j++) {
                    printf("%d ", m3[i][j]);
                  }
                  printf("\n");
                }
                printf("\n");
              }
              else {
                  printf("\nErro! Impossivel somar as matrizes informadas.\n");
                }
              return(0);
        break;
    case '3':
        system("cls");

        void inicializaMatriz(float ***m, int *numLin, int *numCol);
        void imprimeMatriz(float **m, int numLin, int numCol);
        void escalonaMatriz(float **m, int tamLin, int tamCol);
        void analisaMatrizEscalonada(float **m, int tamLin, int tamCol);

        break;
    case '4':
        system("cls");

        break;
    case '5':
        system("cls");

        printf("\n==========MULTIPLICACAO POR ESCALAR==========\n");
              printf("\nMatriz 1\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i1);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j1);
                printf("\nValores da Matriz 1\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for(j=0; j<j1; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m1[i][j]);
                  }
                }
                printf("Digite um escalar : ");
                    scanf("%d", &k);
                for (i=0;i<i1; i++) {
                  for (j=0; j<i1; j++) {
                      m3[i][j] = m1[i][j] * k;
                  }
                }
                printf("\nMatriz 3\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for (j=0; j<j1; j++) {
                    printf("%d ", m3[i][j]);
                  }
                  printf("\n");
                }
                printf("\n");
              return(0);


        break;
    case '6':
        system("cls");

        printf("\n==========MATRIZ TRANSPOSTA==========\n");
              printf("\nMatriz 1\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i1);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j1);
                printf("\nValores da Matriz 1\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for(j=0; j<j1; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m1[i][j]);
                  }
                }
                for (i=0;i<j1; i++) {
                  for (j=0; j<i1; j++) {
                      m3[i][j] = m1[j][i];
                  }
                }
                printf("\nMatriz Original\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for (j=0; j<j1; j++) {
                    printf("%d ", m1[i][j]);
                  }
                  printf("\n");
                }
                printf("\n");
                printf("\nMatriz Transposta\n=====================\n\n");
                for (i=0; i<j1; i++) {
                  for (j=0; j<i1; j++) {
                    printf("%d ", m3[i][j]);
                  }
                  printf("\n");
                }
                printf("\n");
              return(0);
        break;
    case '7':
        system("cls");
        printf("\n==========SUBTRACAO DE MATRIZES==========\n");
              printf("\nMatriz 1\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i1);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j1);
              printf("\nMatriz 2\n==========\n");
              printf("\nDigite o numero de linhas...: ");
              scanf("%d", &i2);
              printf("Digite o numero de colunas..: ");
              scanf("%d", &j2);
              if (j1 == i2) {
                printf("\nValores da Matriz 1\n=====================\n\n");
                for (i=0; i<i1; i++) {
                  for(j=0; j<j1; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m1[i][j]);
                  }
                }
                printf("\nValores da Matriz 2\n=====================\n\n");
                for (i=0; i<i2; i++) {
                  for (j=0; j<j2; j++) {
                    printf("Digite um valor para [%d][%d].: ", (i+1), (j+1));
                    scanf("%d", &m2[i][j]);
                  }
                }
                for (i=0;i<i1; i++) {
                  for (j=0; j<i1; j++) {
                      m3[i][j] = m3[i][j] + (m1[i][j] - m2[i][j]);
                  }
                }
                printf("\nMatriz 3\n=====================\n\n");

                for (i=0; i<i1; i++) {
                  for (j=0; j<j2; j++) {
                    printf("%d ", m3[i][j]);
                  }
                  printf("\n");
                }
                printf("\n");
              }
              else {
                  printf("\nErro! Impossivel somar as matrizes informadas.\n");
                }
              return(0);

        break;
    case '8':
        system("cls");

        break;
    default:
        printf("voce deve escolher uma opcao valida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
    }
}
