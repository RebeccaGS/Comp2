/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: func teste para converter base 16 em 32.

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
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4
#define ERRO_CHAMADA_FUNCAO                     5
#define NULO                                    6
#define NUM_ARG                                 7

#define EOS				      					'\0'

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    byte *base16;
    unsigned long long numeroDeBytes;
    char *base32;
    tipoAlfabetoBase32 alfabeto;

    char *verificacao;
    unsigned short i = 0, n;

    /* se possui ao menos 4 args: arquivo; numero de bytes = 1; o byte a ser convertido */
    if (argc < 4){
        printf("%s", "Favor, colocar: <alfabeto> <numeros de Bytes>  <Bytes listados>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
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

    numeroDeBytes = strtoul(argv[++i], &verificacao, 10);
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
    base16 = malloc (numeroDeBytes * sizeof (byte));
    
    if (base16 == NULL){
        exit (NULO);
    }
  
    base32 = malloc ((2*numeroDeBytes+1) * sizeof (char));
    if (base32 == NULL){
        free(base16);
        exit (NULO);
    }
    /* pegar bytes listados */
    for (n = 0; n < numeroDeBytes; n++){
        base16[n] = (byte) strtoul (argv[n+i+1], &verificacao, 16);

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
    if ((argc-3)!= numeroDeBytes){
        printf ("Numero de argumentos invalido");
        exit (NUM_ARG);
    }
    /* enviar argumentos para conversao */
    tipoErros retorno = CodificarBase32 (base16, numeroDeBytes, alfabeto, base32);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        printf("%s\n", base32);
    }
    
    free(base16);
    free(base32);
    return OK;
}
