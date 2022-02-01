/*

Crie o arquivo "aula0702.c" contendo o o programa de testes para as funções GerarDistribuicaoInicial e MostrarMonitor.
O programa deverá receber,  através dos argumentos de linha de comando, o tempo de congelamento da exibição (em us),
as dimensões reais do monitor (número de linhas e número de colunas), , o percentual de pixels com defeito e o
percentual de pixels apagados. A partir destes percentuais, a função deverá executar a função GerarDistribuicaoInicial
visando preencher a matriz com os dados correspondentes. A seguir deverá executar a função MostrarMonitor.

O programa deverá permitir que vários testes sejam realizados, incluindo:

a) todos os pixels apagados (sem pixels defeituosos).
b) todos os pixels apagados (com pixels defeituosos).
c) todos os pixels acesos (sem pixels defeituosos).
d) todos os pixels acesos (com pixels defeituosos).
e) todos os pixels com defeito.
f) distribuição aleatória com as três possibilidades.

./aula0702 
./aula0702 5 100 200 2.5 70

*/

/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: testes para MostrarMonitor e GeerarDistribuicaoInicial

$Author$
$Date$
$Log$
*/

#ifdef __linux__
#define _XOPEN_SOURCE  500
#endif

#include "aula0701.c"
#include <stdlib.h>
#include <unistd.h> /* useconds_t */
#include <stdio.h>
#include <limits.h>
//#include <string.h>
#include <errno.h>
#include <float.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4
#define ERRO_CHAMADA_FUNCAO                     5

#define EOS				      					'\0'

int main (int argc, char **argv) {

    /* definir variaveis usadas */
    useconds_t tempoEspera;
    tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
    unsigned numeroMaximoLinhas;
    unsigned numeroMaximoColunas;
    float percentualDefeituosos;
    float percentualApagados;
    unsigned short i = 1; /* indice dos for */
    char* pEnd;
    char *verificacao;

    /* se possui os 5 args */
    if (argc < 6){
        printf("%s", "<tempo-congelamento>  <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    tempoEspera = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("tempo de espera invalido.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para tempo de espera ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Tempo de espera contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    numeroMaximoLinhas = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Numero maximo de linhas invalido.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para numero maximo de linhas ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Numero maximo de linhas contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    numeroMaximoColunas = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Numero maximo de colunas invalido.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para numero maximo de colunas ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Numero maximo de colunas contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    percentualDefeituosos = strtof (argv[i++], &pEnd);
    if (errno == ERANGE){
  		printf ("Valor fornecido para percentual de defeituosos ultrapassa o valor maximo permitido para unsigned short (%d)\n",FLT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Percentual de defeituosos contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    
    percentualApagados = strtof (argv[i++], &pEnd);
    if (errno == ERANGE){
  		printf ("Valor fornecido para percentual de defeituosos ultrapassa o valor maximo permitido para unsigned short (%d)\n",FLT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Percentual de defeituosos contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = GerarDistribuicaoInicial(monitor,numeroMaximoLinhas, numeroMaximoColunas,percentualDefeituosos, percentualApagados);
    /* conferir se o retorno ta ok */
    if (retorno != ok){
        printf ("Erro executando a funcao GerarDistribuicaoInicial. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
    /* conferir se o retorno ta ok */
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    return OK;
}

/* $RCSfile$ */
