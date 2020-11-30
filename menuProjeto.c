#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

main()//MENU DO PROJETO
{
    int opcao;
inicio:
    system("cls");
    setlocale( LC_ALL, "" );
    do
    {
        printf("\n\n O====CALCULADORA DE MATRIZES====O\n");
        printf("\n\n O~~~--------~~~~O~~~~--------~~~O");
        printf("\n ? A - MULTIPLICACAO DE MATRIZES ?");
        printf("\n ! B - SOMA DE MATRIZES          !");
        printf("\n | C - MATRIZ INVERSA            |");
        printf("\n � D - ESCALONAMENTO DE MATRIZES �");
        printf("\n � E - MULTIPLICACAO POR ESCALAR �");
        printf("\n O F - MATRIZ TRANSPOSTA         O");
        printf("\n ? G - SUBTRA�AO DE MATRIZES     ?");
        printf("\n ! H - DETERMINANTE DE MATRIZES  !");
        printf("\n | I - MATRIZ OPOSTA             |");
        printf("\n � J - SAIR                      �");
        printf("\n � K - OP�OES                    �");
        printf("\n O~~~--------~~~~O~~~~--------~~~O ");
        printf("\n\n Escolha uma opcao: ");
        opcao = getch();
        switch (toupper(opcao))
        {
        case 'A'://MULTIPLICA�AO DE MATRIZES
            system("cls");
            multMat();
            break;
        case 'B'://SOMA DE MATRIZES
            system("cls");
            somaMat();
            break;
        case 'C'://MATRIZ INVERSA
        {
            system("cls");
            matrizInversa2();
            break;
        }
        case 'D'://ESCALONAMENTO DE MATRIZES
            system("cls");
            metodoDeGauss ();

            break;
        case 'E'://MULTIPLA�AO POR ESCALAR
            system("cls");
            multEsc();
            break;
        case 'F'://MATRIZ TRANSPOSTA
            system("cls");
            matTranspt();
            break;
        case 'G'://SUBTRA�AO DE MATRIZES
            system("cls");
            subtraMat();
            break;
        case 'H'://DETERMINANTE DE MATRIZES
            system("cls");
            determiMat();
            break;
        case 'I'://MATRIZ OPOSTA
            system("cls");
            matOpos();
            break;
        case 'J'://FUN�AO SAIR
            system("cls");
            exit(0);
            break;
        case 'K'://OP�OES DE COR DE PROGRAMA
            system("cls");
            system("cls");
            printf("===================== OPC�ES =====================\n\n");
            aparencia ();
            system("cls");
            break;
        default://OP�AO INVALIDA
            printf("Voc� deve escolher uma opc�o v�lida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            system("pause");
            goto inicio;
        }
    }
    while (1);//DEIXAR MENU CONTINUO

}

int det(int matriz1[50][50], int n)//FUN�AO DETERMINATE DE MATRIZES UTILIZANDO RECURSSAO UTILIZADO EM determiMat()
{
    int Menor[50][50];
    int numLinha,numColuna,k,c1,c2;
    int determinante;
    int c[50];
    int O=1;
    determinante = 0;
    if(n == 2)
    {
        determinante = matriz1[0][0]*matriz1[1][1]-matriz1[0][1]*matriz1[1][0];
        return determinante;
    }
    else
    {
        for(numLinha=0; numLinha<n; numLinha++)
        {
            c1 = 0, c2 = 0;
            for(numColuna=0; numColuna<n; numColuna++)
            {
                for(k=0; k<n; k++)
                {
                    if(numColuna != 0 && k != numLinha)
                    {
                        Menor[c1][c2] = matriz1[numColuna][k];
                        c2++;
                        if(c2>n-2)
                        {
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            determinante = determinante + O*(matriz1[0][numLinha]*det(Menor,n-1));
            O=-1*O;
        }
    }
    return determinante;
    system("pause");
}

int metodoDeGauss ()//FUN�AO ESCALONAMENTO DE MATRIZES
{
    setlocale( LC_ALL, "" );
    int aux, numColuna, k, ordem;
    float A[20][20], c, x[10], soma=0.0;
    printf("\n========== M�todo de Gauss: Escalonamento e Resolu��o ==========");
    printf("\n\nEscreva a ordem da Matriz: ");
    scanf("%d", &ordem);
    printf("Escreva os elementos da Matriz aumentada:\n\n");
    for(aux = 1; aux<=ordem; aux++)
    {
        for ( numColuna=1; numColuna<=(ordem+1); numColuna++)
        {
            printf("A[%d][%d] : ", aux, numColuna);
            scanf("%f", &A[aux][numColuna]);
        }
    }
    for(numColuna=1; numColuna<=ordem; numColuna++)
    {
        for(aux=1; aux<=ordem; aux++)
        {
            if(aux>numColuna)
            {
                c= - (A[aux][numColuna] / A[numColuna][numColuna]);
                for(k=1; k<=ordem+1; k++)
                {
                    A[aux][k] = c*A[numColuna][k]+ A[aux][k];
                }
            }
        }
    }
    for(aux=1; aux<=ordem; aux++)
    {
        for(numColuna=1; numColuna<=ordem+1; numColuna++)
        {
            if(numColuna!=ordem+1)
            {
                printf("%0.0f ", A[aux][numColuna]);
            }
            else
            {
                printf("%0.0f \n", A[aux][numColuna]);
            }
        }
    }
    x[ordem] = A[ordem][ordem+1]/A[ordem][ordem];
    for (aux=ordem-1; aux>=1; aux--)
    {
        soma=0;
        for(numColuna=aux+1; numColuna<=ordem; numColuna++)
        {
            soma = soma+ A[aux][numColuna]*x[numColuna];
        }
        x[aux] = (A[aux][ordem+1]- soma) / A[aux][aux];
    }
    printf("\nA solu��o do Sistema Linear �: \n");
    for (aux=1; aux<=ordem; aux++)
    {
        printf("\nx%d = %0.0f\t", aux,x[aux]); //IMPRESSAO DAS SOLU�OES
    }
    return(0);
    system("pause");
}

int aparencia ()//FUN�AO APARENCIA DE CORES DO MENU
{
    int x;
    do
    {
        printf ("1 - Apar�ncia Claro\n");
        printf ("2 - Apar�ncia Escura\n");
        printf("\nDigite o apar�ncia desejada: \n");
        scanf("%i", &x);
    }
    while (x < 0 || x > 2);
    if (x == 1)
        system ("color 70");
    else if (x == 2)
        system ("color 0F");

    if (x == 10)
        printf ("Obrigado\n");
    else if (x != 1)
        printf("\nN�mero Inv�lido\n");
    else if (x != 2)
        printf("\nN�mero Inv�lido\n");
    return 0;
    system("pause");
}
float determinanteInversa(float a[][25], float k);
void cofator(float [][25], float);
void transposta(float [][25], float [][25], float);
int matrizInversa2()//FUN�AO MATRIZ INVERSA
{
    float a[25][25], k, d;
    int numLinha, numColuna;
    printf("Digite a ordem da matriz quadrada : ");
    scanf("%f", &k);
    printf("digite os elementos da matriz %.0fX%.0f: \n", k, k);
    for (numLinha = 0; numLinha < k; numLinha++)
    {
        for (numColuna = 0; numColuna < k; numColuna++)
        {
            scanf("%f", &a[numLinha][numColuna]);
        }
    }
    d = determinanteInversa(a, k);
    if (d == 0)
    {
        printf("\nMatriz inversa dos valores recebidos nao eh possivel\n");
    }
    else
    {
        cofator(a, k);
    }
}

float determinanteInversa(float a[25][25], float k)//FU�AO DETERMINANTE USADA PARA INVERSA
{
    float s = 1, det = 0, b[25][25];
    int numLinha, numColuna, m, n, c;
    if (k == 1)
    {
        return (a[0][0]);
    }
    else
    {
        det = 0;
        for (c = 0; c < k; c++)
        {
            m = 0;
            n = 0;
            for (numLinha = 0; numLinha < k; numLinha++)
            {
                for (numColuna = 0 ; numColuna < k; numColuna++)
                {
                    b[numLinha][numColuna] = 0;
                    if (numLinha != 0 && numColuna != c)
                    {
                        b[m][n] = a[numLinha][numColuna];
                        if (n < (k - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det = det + s * (a[0][c] * determinanteInversa(b, k - 1));
            s = -1 * s;
        }
    }
    return (det);

    system("pause");
}

void cofator(float num[25][25], float f)//FUN�AO COFATOR USADA PARA CALCULO DE MATRIZ INVERSA
{
    float b[25][25], fac[25][25];
    int p, q, m, n, numLinha, numColuna;
    for (q = 0; q < f; q++)
    {
        for (p = 0; p < f; p++)
        {
            m = 0;
            n = 0;
            for (numLinha = 0; numLinha < f; numLinha++)
            {
                for (numColuna = 0; numColuna < f; numColuna++)
                {
                    if (numLinha != q && numColuna != p)
                    {
                        b[m][n] = num[numLinha][numColuna];
                        if (n < (f - 2))
                            n++;
                        else
                        {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinanteInversa(b, f - 1);
        }
    }
    transposta(num, fac, f);

    system("pause");
}

void transposta(float num[25][25], float fac[25][25], float r)//FUN�AO TRANSPOSTA USADA PARA CALCULO DE MATRIZ INVERSA
{
    int numLinha, numColuna;
    float b[25][25], inversa[25][25], d;

    for (numLinha = 0; numLinha < r; numLinha++)
    {
        for (numColuna = 0; numColuna < r; numColuna++)
        {
            b[numLinha][numColuna] = fac[numColuna][numLinha];
        }
    }
    d = determinanteInversa(num, r);
    for (numLinha = 0; numLinha < r; numLinha++)
    {
        for (numColuna = 0; numColuna < r; numColuna++)
        {
            inversa[numLinha][numColuna] = b[numLinha][numColuna] / d;
        }
    }
    printf("\n\n\nA matriz inversa eh : \n");

    for (numLinha = 0; numLinha < r; numLinha++)
    {
        for (numColuna = 0; numColuna < r; numColuna++)
        {
            printf("\t%f", inversa[numLinha][numColuna]);
        }
        printf("\n");
    }
    system("pause");
}
multMat()// FUN�AO MULTIPLICA�AO DE MATRIZES
{
    int numLinhaMat1, numColMat1, numLinhaMat2, numColMat2, numLinha, numColuna, k, n, resultado, matriz1[50][50], matriz2[50][50], matriz3[50][50];

    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)//LIMPAR O ARMAZENAMENTO DA MATRIZ RESULTADO CASO TENHA SIDO USADA ANTERIORMENTE DEVIDO AO MENU
    {
        for (numColuna=0; numColuna<numColMat2; numColuna++)
        {
            matriz3[numLinha][numColuna] = 0;
        }
    }
    printf("\n==========MULTIPLICACAO DE MATRIZES==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat1);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat1);
    printf("\nMatriz 2\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat2);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat2);
    if (numColMat1 == numLinhaMat2)
    {
        printf("\nValores da Matriz 1\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for(numColuna=0; numColuna<numColMat1; numColuna++)
            {
                printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
                scanf("%d", &matriz1[numLinha][numColuna]);
            }
        }
        printf("\nValores da Matriz 2\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat2; numLinha++)
        {
            for (numColuna=0; numColuna<numColMat2; numColuna++)
            {
                printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
                scanf("%d", &matriz2[numLinha][numColuna]);
            }
        }
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for (numColuna=0; numColuna<numLinhaMat1; numColuna++)
            {
                for (k=0; k<numColMat1; k++)
                {
                    matriz3[numLinha][numColuna] = matriz3[numLinha][numColuna] + (matriz1[numLinha][k] * matriz2[k][numColuna]);
                }
            }
        }
        printf("\nMatriz 3\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for (numColuna=0; numColuna<numColMat2; numColuna++)
            {
                printf("%d ", matriz3[numLinha][numColuna]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("\nErro! Impossivel multiplicar as matrizes informadas.\n\n");
    }
    system("pause");
}
somaMat()//FUN�AO SOMA DE MATRIZES
{
    int numLinhaMat1, numColMat1, numLinhaMat2, numColMat2, numLinha, numColuna, k, n, resultado, matriz1[50][50], matriz2[50][50], matriz3[50][50];

    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)//LIMPAR O ARMAZENAMENTO DA MATRIZ RESULTADO CASO TENHA SIDO USADA ANTERIORMENTE DEVIDO AO MENU
    {
        for (numColuna=0; numColuna<numColMat2; numColuna++)
        {
            matriz3[numLinha][numColuna] = 0;
        }
    }
    printf("\n==========SOMA DE MATRIZES==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat1);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat1);
    printf("\nMatriz 2\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat2);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat2);
    if (numColMat1 == numLinhaMat2)
    {
        printf("\nValores da Matriz 1\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for(numColuna=0; numColuna<numColMat1; numColuna++)
            {
                printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
                scanf("%d", &matriz1[numLinha][numColuna]);
            }
        }
        printf("\nValores da Matriz 2\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat2; numLinha++)
        {
            for (numColuna=0; numColuna<numColMat2; numColuna++)
            {
                printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
                scanf("%d", &matriz2[numLinha][numColuna]);
            }
        }
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for (numColuna=0; numColuna<numLinhaMat1; numColuna++)
            {
                matriz3[numLinha][numColuna] = matriz3[numLinha][numColuna] + (matriz1[numLinha][numColuna] + matriz2[numLinha][numColuna]);
            }
        }
        printf("\nMatriz 3\n=====================\n\n");

        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for (numColuna=0; numColuna<numColMat2; numColuna++)
            {
                printf("%d ", matriz3[numLinha][numColuna]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("\n\nErro! Imposs�vel somar as matrizes informadas.\n\n");
    }
    system("pause");
}
multEsc()//FUN�AO MULTIPLICA�AO POR ESCALAR
{
    int numLinhaMat1, numColMat1, numLinhaMat2, numColMat2, numLinha, numColuna, k, n, resultado, matriz1[50][50], matriz2[50][50], matriz3[50][50];

    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)//LIMPAR O ARMAZENAMENTO DA MATRIZ RESULTADO CASO TENHA SIDO USADA ANTERIORMENTE DEVIDO AO MENU
    {
        for (numColuna=0; numColuna<numColMat2; numColuna++)
        {
            matriz3[numLinha][numColuna] = 0;
        }
    }
    printf("\n==========MULTIPLICACAO POR ESCALAR==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat1);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat1);
    printf("\nValores da Matriz 1\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for(numColuna=0; numColuna<numColMat1; numColuna++)
        {
            printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
            scanf("%d", &matriz1[numLinha][numColuna]);
        }
    }
    printf("Digite um escalar : ");
    scanf("%d", &k);
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numColMat1; numColuna++)
        {
            matriz3[numLinha][numColuna] = matriz1[numLinha][numColuna] * k;
        }
    }
    printf("\nMatriz 3\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numColMat1; numColuna++)
        {
            printf("%d ", matriz3[numLinha][numColuna]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
}
matTranspt()//FUN�AO MATRIZ TRANSPOSTA
{
    int numLinhaMat1, numColMat1, numLinhaMat2, numColMat2, numLinha, numColuna, k, n, resultado, matriz1[50][50], matriz2[50][50], matriz3[50][50];

    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)//LIMPAR O ARMAZENAMENTO DA MATRIZ RESULTADO CASO TENHA SIDO USADA ANTERIORMENTE DEVIDO AO MENU
    {
        for (numColuna=0; numColuna<numColMat2; numColuna++)
        {
            matriz3[numLinha][numColuna] = 0;
        }
    }
    printf("\n==========MATRIZ TRANSPOSTA==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat1);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat1);
    printf("\nValores da Matriz 1\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for(numColuna=0; numColuna<numColMat1; numColuna++)
        {
            printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
            scanf("%d", &matriz1[numLinha][numColuna]);
        }
    }
    for (numLinha=0; numLinha<numColMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numLinhaMat1; numColuna++)
        {
            matriz3[numLinha][numColuna] = matriz1[numColuna][numLinha];
        }
    }
    printf("\nMatriz Original\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numColMat1; numColuna++)
        {
            printf("%d ", matriz1[numLinha][numColuna]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\nMatriz Transposta\n=====================\n\n");
    for (numLinha=0; numLinha<numColMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numLinhaMat1; numColuna++)
        {
            printf("%d ", matriz3[numLinha][numColuna]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
}
subtraMat()//FUN�AO SUBTRA�AO DE MATRIZES
{
    int numLinhaMat1, numColMat1, numLinhaMat2, numColMat2, numLinha, numColuna, k, n, resultado, matriz1[50][50], matriz2[50][50], matriz3[50][50];

    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)//LIMPAR O ARMAZENAMENTO DA MATRIZ RESULTADO CASO TENHA SIDO USADA ANTERIORMENTE DEVIDO AO MENU
    {
        for (numColuna=0; numColuna<numColMat2; numColuna++)
        {
            matriz3[numLinha][numColuna] = 0;
        }
    }
    printf("\n==========SUBTRACAO DE MATRIZES==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat1);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat1);
    printf("\nMatriz 2\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat2);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat2);
    if (numColMat1 == numLinhaMat2)
    {
        printf("\nValores da Matriz 1\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for(numColuna=0; numColuna<numColMat1; numColuna++)
            {
                printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
                scanf("%d", &matriz1[numLinha][numColuna]);
            }
        }
        printf("\nValores da Matriz 2\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat2; numLinha++)
        {
            for (numColuna=0; numColuna<numColMat2; numColuna++)
            {
                printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
                scanf("%d", &matriz2[numLinha][numColuna]);
            }
        }
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for (numColuna=0; numColuna<numLinhaMat1; numColuna++)
            {
                matriz3[numLinha][numColuna] = matriz3[numLinha][numColuna] + (matriz1[numLinha][numColuna] - matriz2[numLinha][numColuna]);
            }
        }
        printf("\nMatriz 3\n=====================\n\n");
        for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
        {
            for (numColuna=0; numColuna<numColMat2; numColuna++)
            {
                printf("%d ", matriz3[numLinha][numColuna]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        printf("\nErro! Impossivel somar as matrizes informadas.\n");
    }
    system("pause");
}
determiMat()//FUN�AO DETERMINANTE DE MATRIZES
{
    int numLinhaMat1, numColMat1, numLinhaMat2, numColMat2, numLinha, numColuna, k, n, resultado, matriz1[50][50], matriz2[50][50], matriz3[50][50];
    printf("\n==========DETERMINANTE DE MATRIZES==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite a ordem da matriz...: ");
    scanf("%d",&n);
    printf("\nValores da Matriz 1\n=====================\n\n");
    for (numLinha=0; numLinha<n; numLinha++)
    {
        for(numColuna=0; numColuna<n; numColuna++)
        {
            printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
            scanf("%d", &matriz1[numLinha][numColuna]);
        }
    }
    for(numLinha=0; numLinha<n; numLinha++)
    {
        for(numColuna=0; numColuna<n; numColuna++)
        {
            printf("%5d",matriz1[numLinha][numColuna]);
        }
        printf("\n");
    }
    resultado = det(matriz1,n);
    printf("\nDeterminante da matriz \n=====================\n");
    printf("\n     det = %d\n",resultado);
    system("pause");
}
matOpos()//FUN�AO MATRIZ OPOSTA
{
    int numLinhaMat1, numColMat1, numLinhaMat2, numColMat2, numLinha, numColuna, k, n, resultado, matriz1[50][50], matriz2[50][50], matriz3[50][50];

    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)//LIMPAR O ARMAZENAMENTO DA MATRIZ RESULTADO CASO TENHA SIDO USADA ANTERIORMENTE DEVIDO AO MENU
    {
        for (numColuna=0; numColuna<numColMat2; numColuna++)
        {
            matriz3[numLinha][numColuna] = 0;
        }
    }
    printf("\n==========MATRIZ OPOSTA==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite o numero de linhas...: ");
    scanf("%d", &numLinhaMat1);
    printf("Digite o numero de colunas..: ");
    scanf("%d", &numColMat1);
    printf("\nValores da Matriz 1\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for(numColuna=0; numColuna<numColMat1; numColuna++)
        {
            printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
            scanf("%d", &matriz1[numLinha][numColuna]);
        }
    }
    printf("\nMatriz Original\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numColMat1; numColuna++)
        {
            printf("%d ", matriz1[numLinha][numColuna]);
        }
        printf("\n");
    }
    printf("\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numColMat1; numColuna++)
        {
            matriz3[numLinha][numColuna] = matriz1[numLinha][numColuna] * (-1);
        }
    }
    printf("\nMatriz Oposta\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for (numColuna=0; numColuna<numColMat1; numColuna++)
        {
            printf("%d ", matriz3[numLinha][numColuna]);
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
}
