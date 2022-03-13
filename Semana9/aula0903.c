#include "aula0901.c"
#include <stdio.h>
#include <stdlib.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1

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
    tipoErros retorno = ConverterArquivoFormatoUnixParaFormatoDos (original,convertido);
    
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    return OK;
}