/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: converte base 10 em 16.

$Author: rebecca.simao $
$Date: 2022/02/17 10:57:09 $
$Log: aula0802.c,v $
Revision 1.1  2022/02/17 10:57:09  rebecca.simao
Initial revision
 */


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
#define EOS				      					'\0'

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    byte *conjuntoDeBytes;
    unsigned long long numeroDeBytes;
    char *saida;

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
  
    conjuntoDeBytes = malloc (numeroDeBytes * sizeof (byte));
    
    if (conjuntoDeBytes == NULL){
        exit (NULO);
    }
  
    saida = malloc ((2*numeroDeBytes+1) * sizeof (char));
    
    if (saida == NULL){
        free(conjuntoDeBytes);
        exit (NULO);
    }
    
    
    /* pegar bytes listados */
    for (n = 0; n < numeroDeBytes; n++){
        if (argv[i] > 255 || argv[i] < 0){
            printf("apenas numeros entre 0-255");
            exit (FORA_RANGE);
        }
        conjuntoDeBytes[n] = strtod(argv[i], &verificacao);
        i++;
    }

    if (errno == ERANGE)
  	{
        free(conjuntoDeBytes);
        free(saida);
  	    printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned char (%u)\n",CHAR_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
        free(conjuntoDeBytes);
        free(saida);
        printf ("Argumento fornecido contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* enviar argumentos para conversao */
    tipoErros retorno = CodificarBase16(conjuntoDeBytes,numeroDeBytes,saida);
    printf("%u",retorno);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        printf("%s\n", saida);
    }
    
    free(conjuntoDeBytes);
    free(saida);
    return OK;
}
