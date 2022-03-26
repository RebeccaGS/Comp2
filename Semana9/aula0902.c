/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: testes para ver arquivo*/

#include "aula0901.h"
#include <stdio.h>
#include <stdlib.h>
#define _WITH_GETLINE

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1

#define _XOPEN_SOURCE													500

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    char *nomeArquivo;


    /* pegar variavel */
    nomeArquivo = argv[1];

    if(argc != 1){
        printf("%s", "Favor, colocar: <nome do arquivo>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* enviar para funcao */
    tipoErros retorno = ExibirConteudoArquivo (nomeArquivo);
    
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    return OK;
}

/* $RCSfile: aula0902.c,v $ */
