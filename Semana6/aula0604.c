/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: implementacao de determinantesMatriz

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

#include "aula0601.c"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> /* DBL_MAX */
#include <errno.h>

int main (int argc, char **argv){

    /* definir variaveis usadas */
    unsigned short ordem;
    unsigned short m;
    unsigned short n;
    char *verificacao;
    unsigned short i = 1;
    double matriz [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    double *determinante;

    /* se possui no minimo a linha, a coluna e um elemento de matriz */
    if (argc < 3){
        printf("%s", ">ordem< >elementos matriz<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    ordem = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base ordem invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para ordem ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Ordem contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
  

    /* tratamento de erros - numero de argumentos */
    if (argc != (ordem*ordem+2)){
        printf("%s", "Argumentos: >ordem< >elementos matriz<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    for (m = 0; m < ordem; m++){
        for (n = 0; n < ordem; n++){
            matriz[m][n] = strtod(argv[i], &verificacao);
            i++;
        }
    }

    
    /* verificacao de erros na coleta de variaveis */
    if (errno == ERANGE){
  		printf ("Valor fornecido para elemento da matriz ultrapassa o valor maximo permitido para double (%d)\n",DBL_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Argumento fornecido para matriz contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = CalcularDeterminanteMatriz(ordem,matriz,determinante);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno); // eh % u msm?

    else{
        /* printar matriz na tela */
        for (m = 0; m < ordem; m++){
            for (n = 0; n < ordem; n++){
                printf("%.5lf ", matriz[m][n]);
            }
            printf("\n");
        }
        printf ("Determinante matriz: %.5lf\n",*determinante);
    }
    
    return OK;



}

/* $RCSfile$ */