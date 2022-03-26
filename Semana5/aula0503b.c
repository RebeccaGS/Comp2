/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: testa ValidarRG no formato XX.XXX.XXX-X

Exemplos:
./aula0503a 56.843.539-4
RG: 56.843.539-4 - valido.
./aula0503a 56.843.539-7
RG: 56.843.539-7 - invalido.
*/

#include "aula0501.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define NUMERO_ARGUMENTOS                       2

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO				1
#define COMPRIMENTO_ARGUMENTO_INVALIDO			2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO		3
#define BASE_INVALIDA                           4
#define VALOR_MAXIMO_EXCEDIDO                   5
#define CONTEM_CARACTERE_INVALIDO               6

#define EOS				      					'\0'

int main (int argc, char **argv){

    /* definir variaveis usadas */
    char *rgDado;
    byte bytes[COMPRIMENTO_RG];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    int i;
    int numero;

    /* tratamento de erros - numero de argumentos */
    if (argc != 2){
        printf("%s", "Digite rg no seguinte formato: >XX.XXX.XXX-X<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar variaveis a serem usadas */
    rgDado = argv[1];
    for (i = 0; i < 2; i++)
        bytes[i] = rgDado[i];   
    
    for (i = 3; i < 6; i++)
        bytes[i-1] = rgDado[i]; 
    
    for (i = 7; i < 10; i++)
        bytes[i-2] = rgDado[i];      
    bytes[8] = rgDado[11];

    /* enviar argumentos coletados para calculo de seu ultimo digito */
    tipoErros retorno = ValidarRg(bytes);
    
    /* conferir se o retorno ta ok */
    if (retorno != ok && retorno != rgInvalido)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar rg na tela */
        for (numero = 0; numero < COMPRIMENTO_RG; numero++){
            if (numero == 2 || numero == 5)
                printf(".");
            if (numero == 8)
                printf("-");
            printf("%u", bytes[numero]);
        }
        if (retorno == rgInvalido){
            printf(" - invalido.");
        }
        else{
            printf(" - valido.");
        }
        printf("\n");
    }
    return OK;

}

/* $RCSfile: aula0503b.c,v $ */

