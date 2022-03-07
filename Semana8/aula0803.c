/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Funcao teste para desconverter na base 16

$Author$
$Date$
$Log$ */


// mudar pra .h
#include "aula0801.c"
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define NULO                                    2

#define EOS				      					'\0'

int main (int argc, char *argv[]) {
    /* definir variaveis usadas */
    char *base16;
    byte *base10;
    unsigned long long numeroEmBase10 = 0;
    
    char *verificacao;
    unsigned short i = 0, n = 0;

    /* se possui ao menos 2 args */
    if (argc < 2){
        printf("%s", "Favor, colocar: <Bytes>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar bytes */
    base16 = argv[1];
    int len = strlen(base16);
    if (len %2 != 0){
        len = len + 2;
        base16 = malloc (len * sizeof (char));
        for (i = 1; i < len; i++){            
            base16[i] = argv[1][i-1];
        }
        base16[0] = '0';
        base16[len] = EOS;
    }
   
    if (base16 == NULL){        
        exit (NULO);
        free(base16);
    }

    base10 = malloc (len/2 * sizeof (byte));

    if (base10 == NULL){
        exit (NULO);
        free(base10);
        free(base16);
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
    
    free(base10);
    free(base16);

    return OK;
}