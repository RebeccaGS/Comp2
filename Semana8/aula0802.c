/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: converte base 10 em 16.*/


#include "aula0801.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4
#define ERRO_CHAMADA_FUNCAO                     5
#define NULO                                    6
#define FORA_RANGE                              7
#define NUM_ARG                                 8
#define EOS				      					'\0'

int main (int argc, char *argv[]) {
    /* definir variaveis usadas */
    byte *base10;
    unsigned long long numeroDeBytes;
    char *base16;

    char *verificacao;
    unsigned short i = 1, n;

    /* se possui ao menos 3 args: arquivo; numero de bytes = 1; o byte a ser convertido */
    if (argc < 3){
        printf("%s", "Favor, colocar: <numeros de Bytes>  <Bytes listados>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }


    /* pegar argumentos a serem usados */
    numeroDeBytes = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("numero de bytes invalido.\n");
        exit (BASE_INVALIDA);
    }

    if (errno == ERANGE){
  		printf ("Valor fornecido para numero de bytes ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("numero de bytes contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
  
    base10 = malloc (numeroDeBytes * sizeof (byte));
    
    if (base10 == NULL){
        exit (NULO);
    }
  
    base16 = malloc ((2*numeroDeBytes+1) * sizeof (char));
    
    if (base16 == NULL){
        free(base10);
        exit (NULO);
    }
    
    if ((argc-2)!= numeroDeBytes){
        printf ("Numero de argumentos invalido");
        exit (NUM_ARG);
    }
    /* pegar bytes listados */

    for (n = 0; n < numeroDeBytes; n++){
        base10[n] = (byte) strtoul (argv[n+2], &verificacao, 10);
        if (base10[n] > 255 || base10[n] < 0){
            printf("apenas numeros entre 0-255");
            exit (FORA_RANGE);
        }
        if (errno == EINVAL){
            printf ("byte invalido.\n");
            exit (BASE_INVALIDA);
        }

        if (errno == ERANGE){
            printf ("Valor fornecido para byte ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
            exit (VALOR_MAXIMO_EXCEDIDO);
        }
        
        if (*verificacao != EOS){
            printf ("byte contem caractere invalido.\n");
            printf ("Caractere invalido: \'%c\'\n", *verificacao);
            exit (CONTEM_CARACTERE_INVALIDO);
        }
    }

    if (errno == ERANGE)
  	{
        free(base10);
        free(base16);
  	    printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned char (%u)\n",CHAR_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
        free(base10);
        free(base16);
        printf ("Argumento fornecido contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* enviar argumentos para conversao */
    tipoErros retorno = CodificarBase16(base10,numeroDeBytes,base16);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        printf("%s\n", base16);
    }
    
    free(base10);
    free(base16);
    return OK;
}

/* $RCSfile: aula0802.c,v $ */
