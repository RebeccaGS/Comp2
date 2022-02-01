/*
Inclua, no arquivo "aula0701.h", a definição do protótipo da função DesenharReta.
Esta função deverá receber uma matriz de pixels (tipoPixel) correspondendo ao monitor,
suas dimensões reais (numeroMaximoLinhas e numeroMaximoColunas) e os valores (linha e coluna)
correspondentes a dois pontos (as duas extremidadades da reta desejada). Se todos os argumentos
forem válidos, a função deverá "acender" todos os pixels necessários para desenhar a reta 
desejada. A função deverá retornar ok (ZERO) ou o código de erro correspondente (todas as
possíveis condições de erro detectáveis na função).

Caso um pixel necessário para desenhar a reta esteja defeituoso, a função deverá retornar o
código de erro correspondente. Antes de desenhar a reta (marcar os pixels correspondentes à
reta com o valor correspndete a aceso (tipoPixel), verifique todos os pontos necessários).
As retas não serão necessariamente horizontais ou verticais e dada a simplicidade do 
dispositivo, poderão apresentar pequenas imperfeições.

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS],
                       unsigned numeroMaximoLinhas,
                       unsigned numeroMaximoColunas,
                       unsigned linhaA,
                       unsigned colunaA,
                       unsigned linhaB,
                       unsigned colunaB);

Inclua, no arquivo "aula0701.c", a implementação da função DesenharReta.

Crie o arquivo "aula0704.c" contendo o o programa de testes para a função
DesenharReta. O programa deverá receber,  através dos argumentos de linha
de comando, o tempo de congelamento da exibição (us), as dimensões reais
do monitor (número de linhas e número de colunas), o percentual de pixels
com defeito, o percentual de pixels apagados e os valores correspondentes
aos pontos A e B (extremidades da reta). A partir dos percentuais, o
programa deverá executar a função GerarDistribuicaoInicial visando preencher
a matriz com os dados correspondentes. A seguir deverá executar as funções
MostrarMonitor, LimparMonitor, DesenharReta e MostrarMonitor.

./aula0704 <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <linha-ponto-1> <coluna-ponto-1> <linha-ponto-2> <coluna-ponto-2>
./aula0704 5 100 200 10 70 30 5 10 70

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
    unsigned linhaA, colunaA, linhaB, colunaB;

    /* se possui os 9 args */
    if (argc < 10){
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

    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = GerarDistribuicaoInicial(monitor,numeroMaximoLinhas, numeroMaximoColunas,percentualDefeituosos, percentualApagados);
    printf("1\n");
    if (retorno != ok){
        printf ("Erro executando a funcao GerarDistribuicaoInicial. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
    printf("2\n");
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = LimparMonitor(monitor,numeroMaximoLinhas, numeroMaximoColunas);
    printf("3\n");
    if (retorno != ok){
        printf ("Erro executando a funcao LimparMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = DesenharReta (monitor,numeroMaximoLinhas,numeroMaximoColunas,linhaA,colunaA,linhaB,colunaB);
    printf("4\n");
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
    printf("5\n");
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }
    /* MostrarMonitor, LimparMonitor, DesenharReta e MostrarMonitor. */
    printf("6\n");

    return OK;
}

/* $RCSfile$ */
