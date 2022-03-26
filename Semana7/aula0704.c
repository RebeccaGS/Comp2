/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: testes para printar reta
*/

#ifdef __linux__
#define _XOPEN_SOURCE  500
#endif


#include "aula0701.h"
#include <stdlib.h>
#include <unistd.h> /* useconds_t */
#include <stdio.h>
#include <limits.h>
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
    char *verificacao;
    unsigned linhaA, colunaA, linhaB, colunaB;

    /* se possui os 9 args */
    if (argc != 10){
        printf("%s", "<tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <linha-ponto-1> <coluna-ponto-1> <linha-ponto-2> <coluna-ponto-2>\n");
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

    if(sscanf(argv[i], "%f", &percentualDefeituosos) == 0){
        printf ("Percentual de defeituosos contem caractere invalido.\n");
        printf ("Input invalido: \'%s\'\n", argv[i]);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    i++;
    
    if (errno == ERANGE){
  		printf ("Valor fornecido para percentual de defeituosos ultrapassa o valor maximo permitido para unsigned short (%f)\n",FLT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    

    if(sscanf(argv[i], "%f", &percentualApagados) == 0){
        printf ("Percentual de apagados contem caractere invalido.\n");
        printf ("Input invalido: \'%s\'\n", argv[i]);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    i++;
    
    if (errno == ERANGE){
  	  	printf ("Valor fornecido para percentual de apagados ultrapassa o valor maximo permitido para unsigned short (%f)\n",FLT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
   
   
    linhaA = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("LinhaA invalida.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para linha A ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Linha A contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    colunaA = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("coluna A invalida.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para coluna A ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("coluna A contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    linhaB = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("LinhaB invalida.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para linha B ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Linha B contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    colunaB = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("coluna B invalida.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para coluna B ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("coluna B contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    /* enviar argumentos */
    tipoErros retorno = GerarDistribuicaoInicial(monitor,numeroMaximoLinhas, numeroMaximoColunas,percentualDefeituosos, percentualApagados);
    if (retorno != ok){
        printf ("Erro executando a funcao GerarDistribuicaoInicial. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = LimparMonitor(monitor,numeroMaximoLinhas, numeroMaximoColunas);
    if (retorno != ok){
        printf ("Erro executando a funcao LimparMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = DesenharReta (monitor,numeroMaximoLinhas,numeroMaximoColunas,linhaA,colunaA,linhaB,colunaB);
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    return OK;
}

/* $RCSfile: aula0704.c,v $ */
