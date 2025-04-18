/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: Funcao teste para desconverter na base 32
*/


#include "aula0801.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define NULO                                    2
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4

#define EOS				      					'\0'

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    char *base32;
    tipoAlfabetoBase32 alfabeto;
    byte *base16;
    unsigned long long numeroEmBase16 = 0;
    
    char *verificacao;
    unsigned short i = 0;

    /* se possui ao menos 2 args */
    if (argc < 3){
        printf("%s", "Favor, colocar: <Alfabeto> <Bytes>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* Pegar alfabeto */
    alfabeto = strtoul(argv[++i], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("alfabeto invalido.\n");
        exit (BASE_INVALIDA);
    }

    if (errno == ERANGE){
  		printf ("Valor fornecido para alfabeto ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("alfabeto contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* pegar bytes */
    base32 = argv[2];
    int len = strlen(base32);
    if (len %2 != 0){
        len = len + 2;
        base32 = malloc (len * sizeof (char));
        for (i = 1; i < len; i++){            
            base32[i] = argv[2][i-1];
        }
        base32[0] = '0';
        base32[len] = EOS;
    }

    if (base32 == NULL){        
        exit (NULO);
        free(base32);
    }

    base16 = malloc ((5*len/8) * sizeof (byte));

    if (base16 == NULL){
        exit (NULO);
        free(base32);
        free(base16);
    }

    /* enviar argumentos para conversao */
    tipoErros retorno = DecodificarBase32 (base32, alfabeto, base16, &numeroEmBase16);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        for (i = 0; i < numeroEmBase16; i++){
            /* resposta deve conter 2 digitos */
            printf("%02X ",base16[i]);
        }
    }
    printf("\n");
    
    free(base32);
    free(base16);

    return OK;
}

/* $RCSfile: aula0805.c,v $ */