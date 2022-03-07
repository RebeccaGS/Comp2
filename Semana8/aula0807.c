/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Funcao teste para desconverter na base 32 -> 16

$Author$
$Date$
$Log$ */


// mudar pra .h
#include "aula0801.c"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define NULO                                    2
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4

#define EOS				      					'\0'

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    char *base64;
    tipoFinalLinha finalDeLinha;
    byte *base16;
    unsigned long long numeroEmBase16 = 0;
    
    char *verificacao;
    unsigned short i = 0;

    /* se possui ao menos 2 args */
    if (argc < 3){
        printf("%s", "Favor, colocar: <finalDeLinha> <Bytes>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* Pegar alfabeto */
    finalDeLinha = strtoul(argv[++i], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("finalDeLinha invalido.\n");
        exit (BASE_INVALIDA);
    }

    if (errno == ERANGE){
  		printf ("Valor fornecido para finalDeLinha ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("finalDeLinha contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* pegar bytes */
    base64 = argv[2];
    int len = strlen(base64);
    if (len %2 != 0){
        len = len + 2;
        base64 = malloc (len * sizeof (char));
        for (i = 1; i < len; i++){            
            base64[i] = argv[2][i-1];
        }
        base64[0] = '0';
        base64[len] = EOS;
    }

    if (base64 == NULL){        
        exit (NULO);
        free(base64);
    }

    /* len pois base16 tb possui final de string */
    base16 = malloc ((3*len/4) * sizeof (byte));

    if (base16 == NULL){
        exit (NULO);
        free(base64);
        free(base16);
    }

    /* enviar argumentos para conversao */
    tipoErros retorno = DecodificarBase64 (base64, finalDeLinha, base16, &numeroEmBase16);

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
    
    free(base64);
    free(base16);

    return OK;
}