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

./aula0702 <tempo-congelamento>  <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>
./aula0702 5 100 200 2.5 70

*/

//CONFERIR ERROS E TIPO ERROS (VER EM AULA06)
// PRINTAR USANDO TERNARIO

#include "aula0701.h"
#include <stdlib.h>
#include <unistd.h> /* useconds_t */
#include <stdio.h>

#define OK										0

int main (int argc, char **argv) {

    /* definir variaveis usadas */
    useconds_t tempoEspera;
    tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
    unsigned numeroMaximoLinhas;
    unsigned numeroMaximoColunas;
    unsigned numeroMaximoLinhas;
    unsigned numeroMaximoColunas;
    float percentualDefeituosos;
    float percentualApagados;
    unsigned short i = 1; /* indice dos for */
    char* pEnd;
    char *verificacao;

    /* pegar argumentos a serem usados */
    tempoEspera = strtoul(argv[i++], &verificacao, 10);
    numeroMaximoLinhas = strtoul(argv[i++], &verificacao, 10);
    numeroMaximoColunas = strtoul(argv[i++], &verificacao, 10);
    percentualDefeituosos = strtof (argv[i++], &pEnd);
    percentualApagados = strtof (argv[i++], &pEnd);
    unsigned short d;
    unsigned short m;

    /* enviar argumentos para montagem de matrizprodutos */
    tipoErros retorno = GerarDistribuicaoInicial(tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                                     unsigned numeroMaximoLinhas,unsigned numeroMaximoColunas,
                                     float percentualDefeituosos,float percentualApagados);
    
    tipoErros retorno2 = MostrarMonitor(useconds_t tempoEspera,tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                        unsigned numeroMaximoLinhas,unsigned numeroMaximoColunas);
    
    /* cobrir numero de linhas iniciais */
    for (d = 0; d < numeroMaximoColunas+4; d++)
        {         
            printf("-");
        }
    
    for (d = 0; d < numeroMaximoLinhas; d++){
        printf("\n| ");
        for (m = 0; m < numeroMaximoColunas; m++){
            printf("%.5lf ",monitor[d][m]);
        }
        printf(" |\n");
    }

    /* cobrir numero de colunas finais */
    for (d = 0; d < numeroMaximoColunas+4; d++)
        {         
            printf("-");
        }
    printf("\n");
    

    return OK;
}