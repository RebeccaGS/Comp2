#include "aula0901.h"
#include <stdio.h>
#include <stdlib.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    char *nomeArquivo;
    unsigned short i;

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