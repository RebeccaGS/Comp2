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


#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4

#define EOS				      					'\0'

#include "aula0601.h"
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

  
    /* se possui no minimo as linha, as coluna e 1 elemento de cada */
    if (argc < 7){
        printf("%s", ">linhas matriz 1< >colunas matriz 1< >linhas matriz 2< >colunas matriz 2< >elementos matriz 1< >elementos matriz 2<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    linhas1 = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base em quantidade de linhas da matriz 1 invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para quantidade de linhas da matriz 1 ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Quantidade de Linhas da matriz 1 contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
  
    colunas1 = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base em quantidade de colunas da matriz 1 invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para quantidade de colunas da matriz 1 ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Quantidade de colunas da matriz 1 contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    linhas2 = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base em quantidade de linhas da matriz 2 invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para quantidade de linhas da matriz 2 ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Quantidade de Linhas da matriz 2 contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    colunas2 = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base em quantidade de colunas da matriz 2 invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para quantidade de colunas da matriz 2 ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Quantidade de colunas da matriz 2 contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* tratamento de erros - numero de argumentos */
    if (argc != (linhas1*colunas1 +5 + linhas2*colunas2)){
        printf("%s", ">linhas matriz 1< >colunas matriz 1< >linhas matriz 2< >colunas matriz 2< >elementos matriz 1< >elementos matriz 2<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar elementos para matriz 1*/
    for (m = 0; m < linhas1; m++){
        for (n = 0; n < colunas1; n++){
            matriz1[m][n] = strtod(argv[i], &verificacao);
            i++;
        }
    }

    if (errno == ERANGE)
  	{
  		printf ("Valor fornecido em elemento matriz 1 ultrapassa o valor maximo permitido para double (%f)\n",DBL_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
        printf ("Argumento fornecido como elemento da matriz 1 contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    /* pegar elementos para matriz 2*/
    for (n = 0; n < linhas2; n++){
        for (p = 0; p < colunas2; p++){
            matriz2[n][p] = strtod(argv[i], &verificacao);
            i++;
        }
    }

    if (errno == ERANGE)
  	{
  	    printf ("Valor fornecido em elemento matriz 2 ultrapassa o valor maximo permitido para double (%f)\n",DBL_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
        printf ("Argumento fornecido como elemento da matriz 2 contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = MultiplicarMatrizes(linhas1,colunas1,linhas2,colunas2,matriz1,matriz2,matrizProduto);


    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

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


/* $RCSfile$ */
