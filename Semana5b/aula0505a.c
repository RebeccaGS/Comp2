/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Codigo que calcula ultimo numero do RG

$Author$
$Date$
$Log$ */

/* recebe 8 digitos - tratamento de erro */
/* deve ser printado assim: XX.XXX.XXX-X */




#include "aula0504.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define NUMERO_ARGUMENTOS                       9

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO				1
#define COMPRIMENTO_ARGUMENTO_INVALIDO			2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO		3
#define BASE_INVALIDA                           4
#define VALOR_MAXIMO_EXCEDIDO                   5
#define CONTEM_CARACTERE_INVALIDO               6
#define TAMANH0_ARGUMENTO_INVALIDO              7

#define EOS				      					'\0'

int main (int argc, char **argv){
    
    /* definir variaveis usadas */
    char entrada [COMPRIMENTO_RG];
    char saida;
    int i;
    char *verificacao;
    int numero;
    
    /* tratamento de erros - numero de argumentos */
    if (argc != 9){
        printf("%s", "Digite 8 numeros validos\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }
    
    /* pegar argumentos a serem usados */
    for (i = 0; i<8; i++){
        if (strlen(argv[i+1]) != 1){
            printf("Cada digito deve estar entre 0 e 9.");
            exit(TAMANH0_ARGUMENTO_INVALIDO);
        }
        entrada[i] = argv[i+1][0];
    }
    entrada[i] = EOS;

    /* enviar argumentos coletados para calculo de seu ultimo digito */
    tipoErros retorno = GerarDigitosVerificadoresRg(entrada, &saida);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar rg na tela */
        for (numero = 0; numero < COMPRIMENTO_RG; numero++){
            if (numero == 2 || numero == 5)
                printf(".");
            if (numero == 8)
                printf("-");
            printf("%c", entrada[numero]);
        }
        printf("%c", saida);
        printf("\n");
    }
    return OK;
}

/* $RCSfile$ */