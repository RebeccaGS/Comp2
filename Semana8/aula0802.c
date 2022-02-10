/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: converte base 10 em 16.

$Author$
$Date$
$Log$ */



// Crie o arquivo "aula0802.c" contendo o código fonte de um programa de testes para a função da
// CodificarBase16. Este programa deverá receber, através dos argumentos de linha de comando, o
// número de bytes a codificar, seguido pelos bytes em notação decimal (valores entre 0 e 255). O
// programa deverá exibir a string gerada pela função ou a mensagem de erro correspondente.
// Exemplo:
// ./aula0802 10 32 171 224 80 24 41 113 120 255 0




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
    byte *bytes;
    unsigned long long numerosBytes;
    char *base16;
    char *verificacao;
    unsigned short i = 1, n;

    /* se possui os 5 args */
    if (argc != 3){
        printf("%s", "<numeros de Bytes>  <Bytes listados>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }


    /* pegar argumentos a serem usados */
    numerosBytes = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("numerosBytes invalido.\n");
        exit (BASE_INVALIDA);
    }

    if (errno == ERANGE){
  		printf ("Valor fornecido para numerosBytes ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("numerosBytes contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    /* pegar bytes listados */
    for (n = 0; n < numerosBytes; n++){
            bytes[n] = strtod(argv[i], &verificacao);
            i++;
    }

    if (errno == ERANGE)
  	{
  	    printf ("Valor fornecido ultrapassa o valor maximo permitido para unsigned char (%u)\n",CHAR_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
        printf ("Argumento fornecido como elemento da matriz 2 contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = CodificarBase16(bytes,numerosBytes,base16);


    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar matriz na tela */
        for (n = 0; n < numerosBytes; n++){
            printf("%u", bytes[n]);
        }
    }
    
    return OK;
}