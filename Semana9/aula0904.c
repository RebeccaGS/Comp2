/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: testes para dos to unix*/

#include "aula0901.c"
#include <stdio.h>
#include <stdlib.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1

#define _XOPEN_SOURCE													500

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    char *original,*convertido;

    /* pegar variavel */
    original = argv[1];
    convertido = argv[2];

    if(argc != 3){
        printf("%s", "Favor, colocar: <nome do arquivo original> <nome do arquivo convertido>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* enviar para funcao */
    tipoErros retorno = ConverterArquivoFormatoDosParaFormatoUnix (original,convertido);
    
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    return OK;
}

/* $RCSfile: aula0904.c,v $ */