#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

main()//MENU DO PROJETO
{
    aparenciaPadrao ();
    int opcao;
inicio:

    setlocale( LC_ALL, "" );
    do
    {
        printf("\n\n O====CALCULADORA DE MATRIZES====O\n");
        printf("\n\n O~~~--------~~~~O~~~~--------~~~O");
        printf("\n ? A - MULTIPLICA��O DE MATRIZES ?");
        printf("\n ! B - SOMA DE MATRIZES          !");
        printf("\n | C - MATRIZ INVERSA            |");
        printf("\n | D - ESCALONAMENTO DE MATRIZES |");
        printf("\n � E - MULTIPLICA��O POR ESCALAR �");
        printf("\n � F - MATRIZ TRANSPOSTA         �");
        printf("\n O G - SUBTRA��O DE MATRIZES     O");
        printf("\n ? H - DETERMINANTE DE MATRIZES  ?");
        printf("\n ! I - MATRIZ OPOSTA             !");
        printf("\n | J - ELEVAR MATRIZ � POT�NCIA  |");
        printf("\n | K - POSTO DE MATRIZ           |");
        printf("\n � L - OP��ES                    �");
        printf("\n � M - SAIR                      �");
        printf("\n O~~~--------~~~~O~~~~--------~~~O ");
        printf("\n\n Escolha uma op��o: ");
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
        case 'J'://FUN�AO ELEVAR MATRIZ � POTENCIA
            system("cls");
            elevarAPotenciaDe();
            break;
        case 'K'://POSTO DE MATRIZ
            system("cls");
            postoMatriz();
            break;
        case 'L'://OP�OES DE COR DE PROGRAMA
            opcoes ();
            system("cls");
            break;
        case 'M'://FUN�AO SAIR
            system("cls");
            sair();
            break;
        default://OP�AO INVALIDA
            printf("Voc� deve escolher uma opc�o v�lida!\n");
            printf("Pressione a tecla ENTER para voltar ao menu\n");
            getchar();

            goto inicio;
        }
    }
    while (1);//DEIXAR MENU CONTINUO

}

int det(int matriz1[50][50], int n)//FUN�AO DETERMINATE DE MATRIZES UTILIZANDO RECURSS�O UTILIZADO EM determiMat()
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
    printf("Pressione a tecla ENTER para voltar ao menu\n");
    getchar();
}

opcoes(){
    int selecioneOpcoes;

    opcao:
    do
    {
        system("cls");
        printf("\n=========Op��es=========\n\n\n");
        printf ("A - Apar�ncia\n");
        printf ("H - Hist�rico\n");
        printf("\n\nDigite a letra referente a op��o desejada: \n");
    selecioneOpcoes = getch();
    switch (toupper(selecioneOpcoes))
    {
    case 'A' :
        aparencia();
        break;
    case 'H':
        limpaTelaOpcao();
        break;
    default:
            printf("Voc� deve escolher uma opc�o v�lida\n");
            printf("Precione ENTER para tentar novamente\n");
            getchar();
            goto opcao;
        }
    }
    while(0);

}
int limpaTelaOpcao()
{

    int historico;

    opcaoHistorico:
    do
    {
        system("cls");
        printf("\n=========Hist�rico=========\n\n");
        printf ("A - Ativar hist�rico\n");
        printf ("D - Desativar hist�rico\n\n");
        printf("\nDigite a letra referente a op��o desejada: \n");
    historico = getch();
    switch (toupper(historico))
    {
    case 'A' :

        break;
    case 'D':


        break;
    default:
            printf("Voc� deve escolher uma opc�o v�lida\n");
            printf("Precione ENTER para tentar novamente\n");
            getchar();
            goto opcaoHistorico;
        }
    }
    while(0);

    printf("\nPressione a tecla ENTER para voltar ao menu\n");

    getchar();

}
int limpaTela(int limpaTela)
{
    int limparTela = 0;

    if (limpaTela == 0)
    {
    return 0;
    }else{
    system("cls");
    }


}

int metodoDeGauss ()//FUN��O ESCALONAMENTO DE MATRIZES
{
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
    printf("Pressione a tecla ENTER para voltar ao menu\n");
    getchar();
}
void aparenciaPadrao (){
    system ("color 0F");
}
void aparencia ()//FUN�AO APARENCIA DE CORES DO MENU
{
    int cor;
    selecioneCor:

    do
    {
        system("cls");
        printf ("\n=========Apar�ncia=========\n\n");
        printf ("C - Apar�ncia Clara\n\n");
        printf ("E - Apar�ncia Escura (Padr�o)\n");
        printf("\nDigite a letra referente a apar�ncia desejada: \n");
    cor = getch();
    switch (toupper(cor))
    {
    case 'C' :
        system ("color 70");
        break;
    case 'E':
        system ("color 0F");
        break;
    default:
            printf("Voc� deve escolher uma opc�o v�lida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            getchar();
            goto selecioneCor;
        }
    }
    while(0);

    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
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
    printf("Digite os elementos da matriz %.0fX%.0f: \n", k, k);
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
        printf("\nMatriz inversa dos valores recebidos n�o � possivel\n");
    }
    else
    {
        cofator(a, k);
    }
    getchar();
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
}

float determinanteInversa(float a[25][25], float k)//FUN�AO DETERMINANTE USADA PARA INVERSA
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
        getchar();
    }
    getchar();
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
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
        getchar();
    }
    getchar();
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
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

    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
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
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
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
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
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

    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
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
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
}
elevarAPotenciaDe()
{
    int numLinhaMat1, p, numLinha, numColuna, i, k, n;

    printf("\n==========ELEVAR MATRIZ � POT�NCIA==========\n");
    printf("\nMatriz 1\n==========\n");
    printf("\nDigite o n�mero de linhas/colunas da matriz quadrada...: ");
    scanf("%d", &numLinhaMat1);
    do
    {
        printf("Digite um expoente maior ou igual a 1: ");
        scanf("%d", &p);
    }
    while(p<=0);
    int matriz1[numLinhaMat1][numLinhaMat1], matriz2[numLinhaMat1][numLinhaMat1], matriz3[numLinhaMat1][numLinhaMat1];


    printf("\nValores da Matriz 1\n=====================\n\n");
    for (numLinha=0; numLinha<numLinhaMat1; numLinha++)
    {
        for(numColuna=0; numColuna<numLinhaMat1; numColuna++)
        {
            printf("Digite um valor para [%d][%d].: ", (numLinha+1), (numColuna+1));
            scanf("%d", &matriz1[numLinha][numColuna]);
            matriz2[numLinha][numColuna] = matriz1[numLinha][numColuna];
        }
    }

    int sum = 0;
    for ( i = 0; i < p - 1; i++)
    {
        for ( numLinha = 0 ; numLinha < numLinhaMat1 ; numLinha++ )
        {
            for (numColuna = 0 ; numColuna < numLinhaMat1 ; numColuna++ )
            {
                for ( k = 0 ; k < numLinhaMat1 ; k++ )
                {
                    sum += matriz2[numLinha][k]*matriz1[k][numColuna];
                }
                matriz3[numLinha][numColuna] = sum;
                sum = 0;
            }
        }

        for ( numLinha = 0 ; numLinha < numLinhaMat1 ; numLinha++ )
        {
            for ( numColuna = 0 ; numColuna < numLinhaMat1 ; numColuna++ )
            {
                matriz2[numLinha][numColuna] = matriz3[numLinha][numColuna];
            }
        }
    }

    printf("\nMatriz elvada � '%d':\n======================\n\n", p);

    for ( n = 0 ; n < numLinhaMat1 ; n++ )
    {
        for ( numColuna = 0 ; numColuna < numLinhaMat1 ; numColuna++ )
        {
            printf("%d   ", matriz2[n][numColuna]);
        }
        printf("\n");
    }
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();

}
int numLinhas,numColunas;
int i, j;
int matriz1[10][10];
void saida( int, int);
void entrada( int, int);
int Posto_Mat(int , int);
void troca(int, int, int);
/* ESSA FUN�AO TROCA DUAS LINHAS DE UMA MATRIZ */
void troca( int linha1,int linha2, int col)
{
    for( i = 0; i < col; i++)
    {
        int temp = matriz1[linha1][i];
        matriz1[linha1][i] = matriz1[linha2][i];
        matriz1[linha2][i] = temp;
    }
    printf("\n\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
}
/* ESSA FUN�AO ACHAR O POSTO DA MATRIZ */
int Posto_Mat(int linha1, int col1)
{
    int numLin, numCol;
    for(numLin = 0; numLin< col1; numLin++)
    {
        saida(numLinhas,numColunas);
        if( matriz1[numLin][numLin] )
            for(numCol = 0; numCol < linha1; numCol++)
                if(numCol != numLin)
                {
                    /* faz com que todos os elementos acima e abaixo
                       da diagonal principal atual sejam zero */
                    float razao = matriz1[numCol][numLin]/ matriz1[numLin][numLin];
                    for( i = 0; i < col1; i++)
                        matriz1[numCol][i] -= razao * matriz1[numLin][i];
                }
                else
                    printf("\n");
        else
        {
            for(numCol =  numLin+1 ; numCol < linha1;  numCol++)
                if (matriz1[numCol][numLin])
                {
                    troca(numLin,numCol,col1);
                    break ;
                }

            if(numCol == linha1)
            {
                -- col1;

                for(numCol = 0; numCol < linha1; numCol ++)
                    matriz1[numCol][numLin] = matriz1[numCol][col1];
            }
            --numLin;
        }
    }
    return col1;

    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
}
/* FUN�AO DE SAIDA */
void saida( int lin, int col)
{
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("  %d", matriz1[i][j]);
        }
        printf("\n");
    }
}
/* FUN�AO DE ENTRADA */
void entrada( int lin, int col)
{
    int valor;
    for(i = 0 ; i< lin; i++)
    {
        for(j = 0 ;  j<col; j++)
        {
            printf("\nDigite um valor para: %d: %d: ", i+1, j+1);
            scanf("%d",  &valor);
            matriz1[i][j] = valor;
        }
    }
    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
}
/* FUN�AO PRINCIPAL PARA ACHAR POSTO MATRIZ */
void postoMatriz()
{
    int posto;
    printf("\n Digite o n�mero de linhas:");
    scanf("%d", &numLinhas);
    printf("\n Digite o n�mero de colunas:");
    scanf("%d", &numColunas);
    entrada(numLinhas, numColunas);

    saida(numLinhas,numColunas);
    printf("\n N�mero de linhas : %d", numLinhas);
    printf("\n N�mero de colunas : %d\n", numColunas);
    printf("\n Matriz entrada pelo usu�rio:\n");

    posto = Posto_Mat(numLinhas, numColunas);
    printf("\n O posto da matriz acima � : %d\n", posto);

    printf("\nPressione a tecla ENTER para voltar ao menu\n");
    getchar();
}

void sair(){
    printf("Obrigado por usar a nossa calculadora de matrizes.\n");
    printf("Criadores do programa: \n");
    printf("\nLin Shiau Lon Rocha \n");
    printf("Rodrigo de Oliveira Ribeiro \n\n");

    exit(0);
}
