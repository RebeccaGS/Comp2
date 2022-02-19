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

#define EOS				      					'\0'

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    byte *conjuntoDeBytes;
    unsigned long long numeroDeBytes;
    char *saida;
    tipoAlfabetoBase32 alfabeto;

    char *verificacao;
    unsigned short i = 1, n;

    /* se possui ao menos 4 args: arquivo; numero de bytes = 1; o byte a ser convertido */
    if (argc < 4){
        printf("%s", "Favor, colocar: <alfabeto> <numeros de Bytes>  <Bytes listados>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    
    /* pegar argumentos a serem usados */
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


    /* pegar bytes listados */
    for (n = 0; n < numeroDeBytes; n++){
            conjuntoDeBytes[n] = strtod(argv[i], &verificacao);
            i++;
    }

    if (errno == ERANGE)
  	{
  	    printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned char (%u)\n",CHAR_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
        printf ("Argumento fornecido contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* enviar argumentos para conversao */
    tipoErros retorno = CodificarBase32 (conjuntoDeBytes, numeroDeBytes, alfabeto, saida);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        for (n = 0; n < numeroDeBytes; n++){
            printf("%u", saida[n]);
        }
    }
    
    return OK;
}