
// ANOTACOES:
// ver tipoErros (separar falhas percentuais? falta alguma? implementei todas?)
// SE ERRO COM USLEEP: Adicionar modulos
//# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
// testar outros modulos salvos em Pendencias - system(clear)
// ifdef depuracao (?) [PERGUNTAR]

// IR PRA MONITORIA COM:
// 4 - 01: 01 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK]
// 5 - 01: 02 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK] 
// 7 - 01: 03 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK]
// 1 - 01: 04 criar logica [CHECK] / implementada
// 2 - 01: 05 criar logica         / implementada
// 3 - 01: 06 criar logica         / implementada
// 6 - 02: testado [CHECK] / erros implementados [CHECK] / Ternario implementado [CHECK]
// 9 - 03: testado [CHECK] / erros implementados [CHECK]
// 8 - BSD [CHECK]         / GNU [CHECK]

// PERGUNTAR NA MONITORIA:
// Sobre retornos (percentual em teste tambem? sao os msms, nao devia conferir apenas 1 vez?)
//
//

// .c nao .h

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

#ifdef __linux__
#define _XOPEN_SOURCE  500
#endif

#include "aula0701.h"
#include <stdlib.h>
#include <unistd.h> /* useconds_t */
#include <stdio.h>
#include <math.h>

#ifdef _WIN32
# define CLEAR_SCREEN system ("cls")
#else
# define CLEAR_SCREEN system ("clear")
#endif

tipoErros MostrarMonitor(useconds_t tempoEspera, /* E */
                        tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS] , /* E */
                        unsigned numeroMaximoLinhas, /* E */
                        unsigned numeroMaximoColunas /* E */ ){
    
    /* definir variaveis */
    unsigned short d;
    unsigned short m;
    int retornoEspera;

    /* verificar se linhas e colunas excedidas */
    if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoLinhas == 0){
        return linhaInvalida;
    }
    if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS || numeroMaximoColunas == 0){
        return colunaInvalida;
    }

    if (monitor == NULL){
        return monitorNulo;
    }
    
    /* limpa monitor */
    //CLEAR_SCREEN;
    
    /* cobrir numero de linhas iniciais */
    for (d = 0; d < numeroMaximoColunas+4; d++)
        {         
            printf("-");
        }
    
    /* reescreve matriz para 'o', ' ' e '.' ao inves de 1, 0 e -1*/
    for (d = 0; d < numeroMaximoLinhas; d++){
        printf("\n| ");
        for (m = 0; m < numeroMaximoColunas; m++){
            monitor[d][m] == apagado ? printf("%c",APAGADO) : (monitor[d][m] == aceso ? printf("%c",ACESO) : printf("%c",DEFEITUOSO));
        }
        printf(" |\n");
    }
    
    /* cobrir numero de colunas finais */
    for (d = 0; d < numeroMaximoColunas+4; d++)
        {         
            printf("-");
        }
    printf("\n");   

    /* espera tempo / retorna 0 se sucesso e -1, se falha. */
    retornoEspera = usleep(tempoEspera);
    if (retornoEspera == -1){ 
        return falhaEspera;
    } 
    return ok;
}

/* -------------------------------------------------------------------------
----------------------------------------------------------------------------
---------------------------------------------------------------------------- */

tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                                     unsigned numeroMaximoLinhas /* E */,
                                     unsigned numeroMaximoColunas, /* E */
                                     float percentualDefeituosos, /* E */
                                     float percentualApagados /* E */){
    
    /* definir variaveis */
    unsigned short numeroElementosTotais, numeroElementosDefeituosos, 
                        numeroElementosAcesos, numeroElementosApagados;
    int linhaSorteada, colunaSorteada;
    unsigned short d, m;
    tipoPixel auxiliar;

    /* verificar tipoErros */
    if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoLinhas == 0){
        return linhaInvalida;
    }
    if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS || numeroMaximoColunas == 0){
        return colunaInvalida;
    }

    if (monitor == NULL){
        return monitorNulo;
    }

    if (percentualDefeituosos < 0 || percentualDefeituosos > 100){
        return percentualDefeituososForaRange;
    }

    if (percentualApagados < 0 || percentualApagados > 100){
        return percentualApagadosForaRange;
    }
    
    if (percentualDefeituosos+percentualApagados > 100){
        return falhaPercentual;
    }
    
    /* decobrir quant de elementos */
    numeroElementosTotais = numeroMaximoColunas*numeroMaximoLinhas;
    numeroElementosDefeituosos = percentualDefeituosos*numeroElementosTotais/100;
    numeroElementosApagados = percentualApagados*numeroElementosTotais/100;
    numeroElementosAcesos = numeroElementosTotais - numeroElementosDefeituosos - numeroElementosApagados;
    
    /* adicionar valores a elementos da matriz original */
    for (d = 0; d < numeroMaximoLinhas; d++){
        for (m = 0; m < numeroMaximoColunas; m++){
            if (numeroElementosDefeituosos>0){
                monitor[d][m] = defeituoso;
                numeroElementosDefeituosos--;
            }
            else if (numeroElementosAcesos>0){
                monitor[d][m] = aceso;
                numeroElementosAcesos--;
            }
            else if (numeroElementosApagados>0){
                monitor[d][m] = apagado;
                numeroElementosApagados--;
            }
        }
    }

    /* tornar aleatorio */
    for (d = 0; d < numeroMaximoLinhas; d++){
        for (m = 0; m < numeroMaximoColunas; m++){
                linhaSorteada = rand() % (numeroMaximoLinhas);
                colunaSorteada = rand() % (numeroMaximoColunas);
                auxiliar = monitor[d][m];
                monitor[d][m] = monitor[linhaSorteada][colunaSorteada];
                monitor[linhaSorteada][colunaSorteada] = auxiliar;
        }
    }    

    return ok;
}



/* -------------------------------------------------------------------------
----------------------------------------------------------------------------
---------------------------------------------------------------------------- */

tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                       unsigned numeroMaximoLinhas, /* E */
                       unsigned numeroMaximoColunas){

    unsigned short d, m;
    
    /* verificar tipoErros */
    if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoLinhas == 0){
        return linhaInvalida;
    }
    if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS || numeroMaximoColunas == 0){
        return colunaInvalida;
    }

    if (monitor == NULL){
        return monitorNulo;
    }

    /* ir elemento a elemento para conferir se eh valido e apagar apenas estes */
    // pra transformar em 0 e apagar em mostrar matrizes OU transformar em ' ' direto?
    // pq tipo, vai ficar 0s e '.'?
    for (d = 0; d < numeroMaximoLinhas; d++){
        for (m = 0; m < numeroMaximoColunas; m++){
            if (monitor[d][m] != defeituoso){
                monitor[d][m] = apagado;
            }
        }
    }
    return ok;
}


/* -------------------------------------------------------------------------
----------------------------------------------------------------------------
---------------------------------------------------------------------------- */

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                       unsigned numeroMaximoLinhas, /* E */
                       unsigned numeroMaximoColunas, /* E */
                       unsigned linhaA, /* E */
                       unsigned colunaA, /* E */
                       unsigned linhaB, /* E */
                       unsigned colunaB /* E */){
    /* definir variaveis */
    unsigned modulolinhas;
    unsigned modulocolunas;
    unsigned x,y;
    float coefAngular;
    float coefLinear;
    linhaA--;
    linhaB--;
    colunaA--;
    colunaB--;
    
    /* calcular modulo linhas e colunas */
    if (linhaA < linhaB){
        modulolinhas = linhaB-linhaA;
    }
    else{
        modulolinhas = linhaA-linhaB;
    }

    if(colunaA < colunaB){
        modulocolunas = colunaB-colunaA;
    }
    else{
        modulocolunas = colunaA-colunaB;
    }
    
    /* caso 1 */
    if (modulolinhas > modulocolunas)
    {
        coefAngular = (modulocolunas)/(modulolinhas);
        coefLinear = colunaA - coefAngular*linhaA;
        if (linhaA < linhaB){
            for(x = linhaA; x < linhaB+1; x++){
                y = roundf(coefAngular*x + coefLinear);
                if(monitor[x][y] == defeituoso){
                    return pixelDefeituoso;
                }
                printf("\nmonitor antes aceso: %c | ",monitor[x][y]);
                monitor[x][y] = aceso;
                printf("monitor depois aceso: %c\n",monitor[x][y]);
            }
        }
        else{
            for(x = linhaA; x > linhaB+1; x--){
                y = roundf(coefAngular*x + coefLinear);
                if(monitor[x][(y)] == defeituoso){
                    return pixelDefeituoso;
                }
                printf("\nmonitor antes aceso: %c | ",monitor[x][y]);
                monitor[x][y] = aceso;
                printf("monitor depois aceso: %c\n",monitor[x][y]);
            }
        }
    }
    
    /* caso 2 */
    else
    {
        coefAngular = (modulolinhas)/(modulocolunas);
        coefLinear = linhaA - coefAngular*colunaA;
        if (colunaA < colunaB){
            for(y = colunaA; y < colunaB+1; y++){
                x = roundf(coefAngular*y + coefLinear);
                if(monitor[x][y] == defeituoso){
                    return pixelDefeituoso;
                }
                printf("\nmonitor antes aceso: %c | ",monitor[x][y]);
                monitor[x][y] = aceso;
                printf("monitor depois aceso: %c\n",monitor[x][y]);
            }
        }
        else{
            for(y = colunaA; y > colunaB+1; y--){
                x = roundf(coefAngular*y + coefLinear);
                if(monitor[x][y] == defeituoso){
                    return pixelDefeituoso;
                }
                printf("\nmonitor antes aceso: %c | ",monitor[x][y]);
                monitor[x][y] = aceso;
                printf("monitor depois aceso: %c\n",monitor[x][y]);
            }
        }
    }

    return ok;
    
}
/* $RCSfile$ */

