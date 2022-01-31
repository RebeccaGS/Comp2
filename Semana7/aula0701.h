/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: arquivo .h da aula 07

$Author$
$Date$
$Log$
*/

#include <unistd.h> /* useconds_t */
#ifdef __linux__
#define _XOPEN_SOURCE  500
#endif

#ifndef   _AULA0701_
#define   _AULA0701_    "@(#)aula0701.h $Revision$"

#define NUMERO_MAXIMO_LINHAS      250
#define NUMERO_MAXIMO_COLUNAS     800
#define APAGADO                   ' '
#define ACESO                     'O'
#define DEFEITUOSO                '.'


typedef enum {ok = 0, linhaInvalida = 1, colunaInvalida = 2, falhaEspera = 3, percentualDefeituososForaRange = 4,percentualApagadosForaRange=8,
                                monitorNulo = 6, retaInvalida = 5, falhaPercentual = 7} tipoErros;

typedef enum {apagado = 0, aceso = 1, defeituoso = -1} tipoPixel;

tipoErros
MostrarMonitor (useconds_t tempoEspera, /* E */
                        tipoPixel monitor [NUMERO_MAXIMO_LINHAS ] [NUMERO_MAXIMO_COLUNAS ], /* E */
                        unsigned numeroMaximoLinhas, /* E */
                        unsigned numeroMaximoColunas /* E */ );


tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS], /* E/S */
                                     unsigned numeroMaximoLinhas /* E */,
                                     unsigned numeroMaximoColunas, /* E */
                                     float percentualDefeituosos, /* E */
                                     float percentualApagados /* E */);

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS], /* E/S */
                       unsigned numeroMaximoLinhas, /* E */
                       unsigned numeroMaximoColunas);

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS], /* E/S */
                       unsigned numeroMaximoLinhas, /* E */
                       unsigned numeroMaximoColunas, /* E */
                       unsigned linhaA, /* E */
                       unsigned colunaA, /* E */
                       unsigned linhaB, /* E */
                       unsigned colunaB /* E */);
                       
#endif

/* $RCSfile$ */
