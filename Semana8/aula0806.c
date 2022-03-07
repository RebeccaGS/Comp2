/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: func teste para converter base 16 em 64.

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
    char *base64;
    tipoFinalLinha finaldeLinha;

    char *verificacao;
    unsigned short i = 1, n;

    /* se possui ao menos 4 args: arquivo; numero de bytes = 1; o byte a ser convertido */
    if (argc < 4){
        printf("%s", "Favor, colocar: <finalDelinha> <numeros de Bytes>  <Bytes listados>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    
    /* pegar argumentos a serem usados */
    finaldeLinha = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("finaldeLinha invalido.\n");
        exit (BASE_INVALIDA);
    }

    if (errno == ERANGE){
  		printf ("Valor fornecido para finaldeLinha ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("finaldeLinha contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

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

    if ((argc-3)!= numeroDeBytes){
        printf ("Numero de argumentos invalido");
        exit (NUM_ARG);
    }

    base16 = malloc (numeroDeBytes * sizeof (byte));
    
    if (base16 == NULL){
        exit (NULO);
    }
  
    base64 = malloc ((2*numeroDeBytes+1) * sizeof (char));
    
    if (base64 == NULL){
        free(base16);
        exit (NULO);
    }
    
    /* pegar bytes listados */
    for (n = 0; n < numeroDeBytes; n++){
        base16[n] = (byte) strtoul (argv[n+3], &verificacao, 16);
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

    /* enviar argumentos para conversao */
    tipoErros retorno = CodificarBase64 (base16, numeroDeBytes, finaldeLinha, base64);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        printf("%s\n", base64);
    }
    
    free(base16);
    free(base64);
    return OK;
}