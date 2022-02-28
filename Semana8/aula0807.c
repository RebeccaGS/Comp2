/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Funcao teste para desconverter na base 64

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
#define NULO                                    6

#define EOS				      					'\0'

int main (int argc, char *argv[]) {

    /* definir variaveis usadas */
    char *codificacaoBase64;
    tipoAlfabetoBase32 finalLinha;
    byte *saida;
    unsigned long long numeroDeBytes;

    char *verificacao;
    unsigned short i = 1, n;

    /* se possui ao menos 3 args: arquivo; numero de bytes = 1; o byte a ser convertido */
    if (argc < 3){
        printf("%s", "Favor, colocar: <alfabeto a ser utilizado>  <Bytes>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    finalLinha = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("finalLinha invalido.\n");
        exit (BASE_INVALIDA);
    }

    if (errno == ERANGE){
  		printf ("Valor fornecido para finalLinha ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("finalLinha contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    codificacaoBase64 = malloc (numeroDeBytes * sizeof (byte));
    
    if (codificacaoBase64 == NULL){
        exit (NULO);
    }
  
    saida = malloc ((2*numeroDeBytes+1) * sizeof (char));
    
    if (saida == NULL){
        free(codificacaoBase64);
        exit (NULO);
    }

    /* pegar bytes listados */
    for (n = 0; n < numeroDeBytes; n++){
            codificacaoBase64[n] = argv[i];
            codificacaoBase64[n] = argv[i+1];
            i = i + 2;
    }

    numeroDeBytes = i+1;

    /* enviar argumentos para conversao */
    tipoErros retorno = DecodificarBase64 (codificacaoBase64, finalLinha, saida, numeroDeBytes);

    
    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno);

    else{
        /* printar bytes na tela na tela */
        printf("%s\n", saida);
    }
    
    free(codificacaoBase64);
    free(saida);
    return OK;
}