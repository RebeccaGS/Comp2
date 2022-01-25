/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: implementacao da aula 06

$Author$
$Date$
$Log$
*/

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
    unsigned short linhasOriginal;
    unsigned short colunasOriginal;
    double matrizOriginal [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    double matrizTransposta [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    unsigned short i = 1;
    char *verificacao;
    unsigned short m;
    unsigned short n;

    /* se possui no minimo a ordem e um elemento de matriz */
    if (argc < 3){
        printf("%s", ">ordem matriz< >elementos matriz<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    linhasOriginal = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base em quantidade de linhas da matriz invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para quantidade de linhas da matriz ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Quantidade de Linhas da matriz contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
  

    colunasOriginal = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base em quantidade de colunas da matriz invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para quantidade de colunas da matriz ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    if (*verificacao != EOS){
        printf ("Quantidade de colunas da matriz contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* tratamento de erros - numero de argumentos */
    if (argc != (linhasOriginal*colunasOriginal +3)){
        printf("%s", ">linhas matriz< >colunas matriz< >elementos matriz<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    for (m = 0; m < linhasOriginal; m++){
        for (n = 0; n < colunasOriginal; n++){
            matrizOriginal[m][n] = strtod(argv[i], &verificacao);
            i++;
        }
    }

    /* verificacao de erros na coleta de elementos matriz */
    if (errno == ERANGE){
  		printf ("Valor fornecido para elemento da matriz ultrapassa o valor maximo permitido para double (%f)\n",DBL_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Argumento fornecido para matriz contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = ObterMatrizTransposta(linhasOriginal,colunasOriginal,matrizOriginal,matrizTransposta);
    

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar matriz na tela */
        for (m = 0; m < colunasOriginal; m++){
            for (n = 0; n < linhasOriginal; n++){
                printf("%.5lf ", matrizTransposta[m][n]);
            }
            printf("\n");
        }
    }
    
    return OK;

}

/* $RCSfile$ */
