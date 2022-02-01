
// ANOTACOES:
// fazer todos os testes possiveis no moba
// verificar logica das de baixo
// tipo erros duma das 3 ali

// GERAL -------------------------------------------------------------------------------
// 4 - 01: 01 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK]
// 5 - 01: 02 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK] 
// 7 - 01: 03 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK]
// 6 - 02: testado [CHECK] / erros implementados [CHECK] / Ternario implementado [CHECK]
//     03: testado [CHECK] / erros implementados [CHECK]
// 8 - BSD [CHECK]         / GNU [CHECK] / testado

// 01: 04 criar logica [CHECK] / implementada [CHECK] / funcional         / tipo erros
// 01: 05 criar logica [CHECK] / implementada [CHECK] / funcional         / tipo erros
// 01: 06 criar logica [CHECK] / implementada [CHECK] / funcional         / tipo erros
// 04: testado [CHECK]  / erros implementados [CHECK] / funcional
// 05: testado [CHECK]  / erros implementados [CHECK] / funcional
// 06: testado [CHECK]  / erros implementados [CHECK] / funcional


// .c nao .h

/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: arquivo .c da aula 07

$Author: rebecca.simao $
$Date: 2022/02/01 06:20:59 $
$Log: aula0701.c,v $
Revision 1.1  2022/02/01 06:20:59  rebecca.simao
Initial revision

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
    
    printf("linhaA: %d, linhaB: %d, colunaA: %d, colunaB: %d", linhaA, linhaB,colunaA,colunaB);
    usleep(1000000);
    
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

    if (linhaA == 0 || linhaA > numeroMaximoLinhas){
        return linhaAForaRange;
    }

    if (colunaA == 0 || colunaA > numeroMaximoColunas){
        return colunaAForaRange;
    }

    if (linhaB == 0 || linhaB > numeroMaximoLinhas){
        return linhaBForaRange;
    }

    if (colunaB == 0 || colunaB > numeroMaximoColunas){
        return colunaBForaRange;
    }

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
        if (linhaA < linhaB){
            coefAngular = (float)(colunaB-colunaA)/(float)(linhaB-linhaA);
            coefLinear = colunaA - coefAngular*linhaA;
            for(x = linhaA; x <= linhaB; x++){
                y = roundf(coefAngular*x + coefLinear);
                if(monitor[x][y] == defeituoso){
                    return pixelDefeituoso;
                }
                monitor[x][y] = aceso;
            }
        }
        else{
            coefAngular = (float)(colunaA-colunaB)/(float)(linhaA-linhaB);
            coefLinear = colunaA - coefAngular*linhaA;
            for(x = linhaB; x <= linhaA; x++){
                y = roundf(coefAngular*x + coefLinear);
                if(monitor[x][y] == defeituoso){
                    return pixelDefeituoso;
                }
                monitor[x][y] = aceso;
            }
        }
    }
    
    /* caso 2 */
    else
    {
        if (colunaA < colunaB){
            coefAngular = (float)(linhaB-linhaA)/(float)(colunaB-colunaA);
            coefLinear = (float)linhaA - coefAngular*(float)colunaA;
            for(y = colunaA; y <= colunaB; y++){
                x = roundf(coefAngular*y + coefLinear);
                if(monitor[x][y] == defeituoso){
                    return pixelDefeituoso;
                }
                monitor[x][y] = aceso;
            }
        }
        else{
            for(y = colunaB; y <= colunaA; y++){
                coefAngular = (float)(linhaA-linhaB)/(float)(colunaA-colunaB);
                coefLinear = (float)linhaA - coefAngular*(float)colunaA;
                x = roundf(coefAngular*y + coefLinear);
                if(monitor[x][y] == defeituoso){
                    return pixelDefeituoso;
                }
                monitor[x][y] = aceso;
            }
        }
    }

    return ok;    
}


/* -------------------------------------------------------------------------
----------------------------------------------------------------------------
---------------------------------------------------------------------------- */

tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS], /* E/S */
                             unsigned numeroMaximoLinhas, /* E */
                             unsigned numeroMaximoColunas, /* E */
                             unsigned numeroVertices, /* E */
                             unsigned linhasVertices [NUMERO_MAXIMO_LINHAS], /* E */
                             unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS] /* E */){
    unsigned short i;
    tipoErros retorno;
    
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

    if (linhasVertices == NULL){
        return linhasNulas;
    }
    
    if (colunasVertices == NULL){
        return colunasNulas;
    }

    /* execucao da func usando func desenharReta e vertices */

    for (i = 0; i<numeroVertices-1; i++){
        printf("i: %u, numeroVertices: %u\n",i,numeroVertices);
        retorno = DesenharReta (monitor,numeroMaximoLinhas,numeroMaximoColunas,linhasVertices[i],colunasVertices[i],linhasVertices[i+1],colunasVertices[i+1]);
        printf("i: %u, numeroVertices: %u\n",i,numeroVertices);
        usleep(1000000);
        if (retorno != ok){
            printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        }
    }

    retorno = DesenharReta (monitor,numeroMaximoLinhas,numeroMaximoColunas,linhasVertices[0],colunasVertices[0],linhasVertices[numeroVertices-1],colunasVertices[numeroVertices-1]);
    if (retorno != ok){
            printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
    }
    
    return ok;    
}


tipoErros
PreencherPoligono (useconds_t tempoEspera, /* E */
                             tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS], /* E/S */
                             unsigned numeroMaximoLinhas, /* E */
                             unsigned numeroMaximoColunas, /* E */
                             unsigned linha, /* E */
                             unsigned coluna /* E */ ){
    
    
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

    if (linha > numeroMaximoLinhas){
        return linhaAForaRange;
    }

    if (coluna > numeroMaximoColunas){
        return colunaAForaRange;
    }
    
    /* conferir se aceso */
    if (monitor[linha][coluna] == aceso){
        return ok;
    }
    else{
        if(monitor[linha][coluna] == defeituoso){
                return pixelDefeituoso;
        }
        monitor[linha][coluna] = aceso;
        MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
        /* esquerda, direita, abaixo e acima do pixel em questão - nesta ordem */
        if (monitor[linha][coluna-1] != aceso){
            if(monitor[linha][coluna-1] == defeituoso){
                return pixelDefeituoso;
            }
            monitor[linha][coluna-1] = aceso;
            PreencherPoligono (tempoEspera,monitor,numeroMaximoLinhas,numeroMaximoColunas,linha,coluna-1);
            MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
        }
        if (monitor[linha][coluna+1] != aceso){
            if(monitor[linha][coluna+1] == defeituoso){
                return pixelDefeituoso;
            }
            monitor[linha][coluna+1] = aceso;
            PreencherPoligono (tempoEspera,monitor,numeroMaximoLinhas,numeroMaximoColunas,linha,coluna+1);
            MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
        }
        if (monitor[linha+1][coluna] != aceso){
            if(monitor[linha+1][coluna] == defeituoso){
                return pixelDefeituoso;
            }
            monitor[linha+1][coluna] = aceso;
            PreencherPoligono (tempoEspera,monitor,numeroMaximoLinhas,numeroMaximoColunas,linha+1,coluna);
            MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
        }
        if (monitor[linha-1][coluna] != aceso){
            if(monitor[linha-1][coluna] == defeituoso){
                return pixelDefeituoso;
            }
            monitor[linha-1][coluna] = aceso;
            PreencherPoligono (tempoEspera,monitor,numeroMaximoLinhas,numeroMaximoColunas,linha-1,coluna);
            MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
        }
    }
    return ok;
}

/* $RCSfile: aula0701.c,v $ */


