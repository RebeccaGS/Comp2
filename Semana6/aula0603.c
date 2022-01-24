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

// ERROS E ANOTACOES:
// Verificar cada tipo erro
// botar .h e nao .c
// conferir defines e includes
// nao ta printando certo


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
    unsigned short linhasOriginal;
    unsigned short colunasOriginal;
    double matrizOriginal [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    double matrizTransposta [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    unsigned short i = 1;
    char *verificacao;
    unsigned short m;
    unsigned short n;

    /* pegar argumentos a serem usados */
    linhasOriginal = strtol(argv[i++], &verificacao, 10);
    colunasOriginal = strtol(argv[i++], &verificacao, 10);
    printf("linhasOriginal: %d\n",linhasOriginal);
    printf("colunasOriginal: %d\n",colunasOriginal);

    /* tratamento de erros - numero de argumentos */
    if (argc != (linhasOriginal*colunasOriginal +3)){
        printf("%s", "complete ambas as matrizes\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    for (m = 0; m < colunasOriginal; m++){
        for (n = 0; n < linhasOriginal; n++){
            matrizOriginal[m][n] = strtol(argv[i], &verificacao, 10);
            i++;
        }
    }

    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = ObterMatrizTransposta(linhasOriginal,colunasOriginal,matrizOriginal,matrizTransposta);
    
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
        for (m = 0; m < colunasOriginal; m++){
            for (n = 0; n < linhasOriginal; n++){
                printf("| n e m: %.5lf |", matrizTransposta[n][m]);
                printf("| m e n: %.5lf |", matrizTransposta[m][n]);
            }
            printf("\n");
        }
    }
    
    return OK;

}
/* $RCSfile$ */