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
    char *base32;
    tipoAlfabetoBase32 alfabeto;
    byte *base16;
    unsigned long long numeroEmBase16 = 0;
    
    char *verificacao;
    unsigned short i = 0, n = 0;

    /* se possui ao menos 2 args */
    if (argc < 3){
        printf("%s", "Favor, colocar: <Alfabeto> <Bytes>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* Pegar alfabeto */
    alfabeto = strtoul(argv[i++], &verificacao, 10);
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

    /* (len - 1) pois 1 eh EOS */
    numeroEmBase16 = (len-1)/2;

    base16 = malloc ((len-1) * sizeof (byte));

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
            if (base16[i] < 100){
                printf("(%c%c)16 = (0%d)10\n", base32[n],base32[n+1], base16[i]);    
            }
            else {
                printf("(%c%c)16 = (%d)10\n", base32[n],base32[n+1], base16[i]);
            }
            n = n+2;
        }
    }
    
    free(base32);
    free(base16);

    return OK;
}