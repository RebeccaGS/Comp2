/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: programa de testes que printa numero de rg completo incluindo o ultimo - recebe no formato XX.XXX.XXX-X
*/

/*
56.843.539
RG: 56.843.539-4
*/

#include "aula0504.h"
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
    char saida;

    /* tratamento de erros - numero de argumentos */
    if (argc != 2){
        printf("%s", "Digite rg no seguinte formato: >XX.XXX.XXX<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* enviar argumentos coletados para calculo de seu ultimo digito */
    tipoErros retorno = GerarDigitosVerificadoresRg(argv[1], &saida);

    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar rg na tela */
        printf("%s-%c\n", argv[1],saida);
    }
    return OK;
}
/* $RCSfile: aula0505b.c,v $ */
