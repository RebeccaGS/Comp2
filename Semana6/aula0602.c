/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Implementacao da func MultiplicarMatrizes

$Author$
$Date$
$Log$ */

/* $RCSfile$ */

/*
Crie o arquivo "aula0602.c" contendo o programa de testes para a função MultiplicarMatrizes.
O programa deverá receber,  através dos argumentos de linha de comando, as dimensões de cada matriz
e os valores de cada elemento das matrizes de entrada. Após executar a função de multiplicação de matrizes,
o programa deverá exibir a matriz produto (em formato de matriz). Os valores desta matriz deverão ser exibidos
com no mínimo 5 casas decimais. Este programa NÃO pode utilizar alocação dinâmica de memória.

Exemplo:
./aula0602 3 2 2 4 a11 a12 a13 a21 ... b31 b32 b33 b34

No exemplo acima, a matriz A terá 3 linhas x 2 colunas, enquanto que a matriz B terá 2 linhas x 4 colunas.
*/

// NOTS
// CONFERIR TRATAMENTOS DE ERRO
// botar .h e nao .c
// conferir defines e includes

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4

#define EOS				      					'\0'

#include "aula0601.c"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> /* DBL_MAX */
#include <errno.h>

int main (int argc, char **argv){

    /* definir variaveis usadas */
    double matriz1 [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    double matriz2 [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    double matrizProduto [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    char *verificacao;
    unsigned short linhas1;
    unsigned short colunas1;
    unsigned short linhas2;
    unsigned short colunas2;
    unsigned short m; /* matriz1[m][n] * matriz2[n][p] = matrizproduto[m][p]*/
    unsigned short p;
    unsigned short n;
    unsigned short i = 1; /* indice dos for */

    // argc > minimo
    // conferencia strOUL para cada um
    // arc total
    // conferencia strOD para cada um (sem base)
    // verificar retorno 
    
    /* pegar argumentos a serem usados */
    linhas1 = strtoul(argv[i++], &verificacao, 10);
    colunas1 = strtoul(argv[i++], &verificacao, 10);
    linhas2 = strtoul(argv[i++], &verificacao, 10);
    colunas2 = strtoul(argv[i++], &verificacao, 10);

    /* tratamento de erros - numero de argumentos */
    if (argc != (linhas1*colunas1 +5 + linhas2*colunas2)){
        printf("%s", "complete ambas as matrizes\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    for (m = 0; m < linhas1; m++){
        for (n = 0; n < colunas1; n++){
            matriz1[m][n] = strtod(argv[i], &verificacao);
            i++;
        }
    }

    for (n = 0; n < linhas2; n++){
        for (p = 0; p < colunas2; p++){
            matriz2[n][p] = strtod(argv[i], &verificacao);
            i++;
        }
    }
    
    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = MultiplicarMatrizes(linhas1,colunas1,linhas2,colunas2,matriz1,matriz2,matrizProduto);
    
    /* verificacao de erros na coleta de variaveis */
    if (errno == EINVAL)
    {
  		printf ("Base invalida\n");
        exit (BASE_INVALIDA);
    }
  
    if (errno == ERANGE)
  	{
  		printf ("Valor fornecido ultrapassa o valor maximo permitido para double (%d)\n", 
  						 DBL_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
        printf ("Argumento contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno); // eh % u msm?

    else{
        /* printar matriz na tela */
        for (m = 0; m < linhas1; m++){
            for (p = 0; p < colunas2; p++){
                printf("%.5lf ", matrizProduto[m][p]);
            }
            printf("\n");
        }
    }
    
    return OK;
}