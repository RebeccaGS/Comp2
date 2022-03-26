/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: Funcao teste para desconverter na base 16*/


#include "aula0801.h"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define NULO                                    2

#define EOS				      					'\0'

int main (int argc, char *argv[]) {
    /* definir variaveis usadas */
    byte *base10;
    unsigned long long numeroEmBase10 = 0;
    
    unsigned short i = 0;

    /* se possui ao menos 2 args */
    if (argc < 2){
        printf("%s", "Favor, colocar: <Bytes>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    base10 = malloc (argc/2 * sizeof (byte));

    if (base10 == NULL){
        exit (NULO);
        free(base10);
    }

    /* enviar argumentos para conversao */
    tipoErros retorno = DecodificarBase16(argv[1],base10,&numeroEmBase10);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        for (i = 0; i < numeroEmBase10; i++){
            /* resposta deve conter 3 digitos */
            printf("%03u ",base10[i]);
        }
    }
    printf("\n\n");
    free(base10);

    return OK;
}

/* $RCSfile $ */ 