/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: implementação de um programa de testes para a função GerarDigitosVerificadoresRg.
Este programa deverá receber os 8 primeiros dígitos do RG desejado através de um único
argumento da linha de comando (CLI) no formato "XX.XXX.XXX" (sem as aspas). 
O programa deverá exibir o RG cpmpleto no formato "XX.XXX.XXX-X" (sem as aspas).
Todos os tratamentos de erro necessários e que não possam realizados na função
GerarDigitosVerificadoresRg deverão ser implementados neste programa.

$Author$
$Date$
$Log$ */

/*
56.843.539
RG: 56.843.539-4
*/

#include "aula0504.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define NUMERO_ARGUMENTOS                         2

#define OK                                        0
#define NUMERO_ARGUMENTOS_INVALIDO                1
#define COMPRIMENTO_ARGUMENTO_INVALIDO            2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO       3
#define BASE_INVALIDA                             4
#define VALOR_MAXIMO_EXCEDIDO                     5

#define EOS                                      '\0'

int main(int argc, char **argv)
{

    /* definir variaveis usadas */
    char entrada [COMPRIMENTO_RG];
    char saida;
    char *rgDado;
    int i;
    int numero;

    /* tratamento de erros - numero de argumentos */
    if (argc != 2){
        printf("%s", "Digite rg no seguinte formato: >XX.XXX.XXX<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar variaveis a serem usadas */
    rgDado = argv[1][0];
    for (i = 0; i < 2; i++)
        entrada[i] = rgDado[i] - '0';   
    
    for (i = 3; i < 6; i++)
        entrada[i-1] = rgDado[i] - '0'; 
    
    for (i = 7; i < 10; i++)
        entrada[i-2] = rgDado[i] - '0';   

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
            printf("%u", entrada[numero]);
        }
        printf("\n");
    }
    return OK;
}
/* $RCSfile$ */