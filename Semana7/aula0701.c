/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: arquivo .c da aula 07

$Author$
$Date$
$Log$
*/

/* Crie o arquivo "aula0701.c" contendo o código fonte da função MostrarMonitor. Esta função deverá conter,
antes da exibição do conteúdo, uma chamada para a função system executando o comando clear. Após a exibição
do conteúdo, esta função deverá conter uma chamada para a função usleep (com o tempo recebido).
A função deverá retornar ok (ZERO) ou o código de erro correspondente (todas as possíveis condições de erro
detectáveis na função).

Antes de exibir o conteúdo correspondente ao dispositivo de saída em questão, a função deverá exibir uma linha
N hifens (N deverá ser igual ao número de colunas do dispositivo + 4) seguida por uma linha contendo os caracteres
delimitadores "|" (pipe) como definido abaixo.

À esquerda do conteúdo cada linha deverá conter um caractere "|" seguido por um caractere de espaço. À direita
do conteúdo cada linha deverá conter um caractere de espaço seguido por um caractere "|". Após a exibição do
conteúdo deverá ser exibida uma linha contendo os caracteres delimitadores, seguida por uma linha com N hifens.

Entre dois caracteres representando dois pixels vizinhos NÃO PODERÁ ser exibido nenhum caractere. */

// ANOTACOES:
//
//
// SE ERRO COM USLEEP: Adicionar modulos
//# define CLEAR_SCREEN system ("clear")
// testar outros modulos salvos em Pendencias - system(clear)


#include "aula0701.h"
#include <stdlib.h>
#include <unistd.h> /* useconds_t */
#include <stdio.h>

#ifdef _WIN32
# define CLEAR_SCREEN system ("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

tipoErros MostrarMonitor(useconds_t tempoEspera, /* E */
                        tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS] , /* E */
                        unsigned numeroMaximoLinhas, /* E */
                        unsigned numeroMaximoColunas /* E */ ){
    
    /* definir variaveis */
    unsigned short d;
    int retornoEspera;
    
    /* limpa monitor */
    CLEAR_SCREEN
    
    /* espera tempo / retorna 0 se sucesso e -1, se falha. */
    retornoEspera = usleep(tempoEspera);
    if (retornoEspera == -1){ 
        return falhaEspera;
    }
    
    for (d = 0; d < numeroMaximoLinhas; d++){
        for (m = 0; m < numeroMaximoColunas; m++){
            if (monitor[d][m] == apagado){
            monitor[d][m] == APAGADO;
            }
            elif (monitor[d][m] == aceso){
                monitor[d][m] == ACESO;
            }
            elif (monitor[d][m] == defeituoso){
                monitor[d][m] == DEFEITUOSO;
            }
        }
    }
    
    return ok;
}
    
/* $RCSfile$ */
