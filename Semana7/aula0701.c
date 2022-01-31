
// ANOTACOES:
// COMO RESOLVER RETORNO? BOTAR ISSO EM GERAR DISTRIBUICAO MSM COM UM PRINT E UM EXIT ANTES DE PRINTAR?
// ver tipoErros (separar falhas percentuais? falta alguma? implementei todas?)
// SE ERRO COM USLEEP: Adicionar modulos
//# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
// testar outros modulos salvos em Pendencias - system(clear)
// indef depuracao (?) [PERGUNTAR]

// IR PRA MONITORIA COM:
// 4 - 01: 01 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK]
// 5 - 01: 02 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK] 
// 7 - 01: 03 implementada [CHECK] / testada [CHECK] / tipo erros [CHECK]
// 1 - 01: 04 implementada
// 2 - 01: 05 implementada
// 3 - 01: 06 implementada
// 6 - 02: testado [CHECK] / erros implementados [CHECK] / Ternario implementado
// 9 - 03: testado [CHECK] / erros implementados [CHECK]
// 8 - BSD e GNU parcialmente feitos

// PERGUNTAR NA MONITORIA:
// Sobre retornos (percentual em teste tambem? sao os msms, nao devia conferir apenas 1 vez?)
//
//

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

#include "aula0701.h"
#include <stdlib.h>
#include <unistd.h> /* useconds_t */
#include <stdio.h>

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
    
    /* limpa monitor */
    //CLEAR_SCREEN;

    /* verificar se linhas e colunas excedidas */
    if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS){
        return linhaInvalida;
    }
    if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS){
        return colunaInvalida;
    }

    if (monitor == NULL){
        return monitorNulo;
    }
    
    /* espera tempo / retorna 0 se sucesso e -1, se falha. */
    retornoEspera = usleep(tempoEspera);
    if (retornoEspera == -1){ 
        return falhaEspera;
    }
    
    /* cobrir numero de linhas iniciais */
    for (d = 0; d < numeroMaximoColunas+4; d++)
        {         
            printf("-");
        }
    
    /* reescreve matriz para 'o', ' ' e '.' ao inves de 1, 0 e -1*/
    for (d = 0; d < numeroMaximoLinhas; d++){
        printf("\n| ");
        for (m = 0; m < numeroMaximoColunas; m++){
            monitor[d][m] == apagado ? printf("%c",APAGADO) : (monitor[d][m] == aceso ? printf("%c",ACESO) : printf("%c",DEFEITUOSO);
        printf(" |\n");
    }
    
    /* cobrir numero de colunas finais */
    for (d = 0; d < numeroMaximoColunas+4; d++)
        {         
            printf("-");
        }
    printf("\n");    
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
    if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS){
        return linhaInvalida;
    }
    if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS){
        return colunaInvalida;
    }

    if (monitor == NULL){
        return monitorNulo;
    }

    if (percentualDefeituosos < 0 || percentualDefeituosos > 100){
        return percentualForaRange;
    }

    if (percentualApagados < 0 || percentualApagados > 100){
        return percentualForaRange;
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
    if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS){
        return linhaInvalida;
    }
    if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS){
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
    unsigned short linhas, colunas, relacao, d, m, i;

    /* conferir se caminho defeituoso*/

    // CONFERIR DIRECAO!!!!!!!!!!!!!!
    /* achar relacao */
    if (linhaA > linhaB){
        linhas = linhaA - linhaB;
    }
    else{
        linhas = linhaB - linhaA;
    }

    if (colunaA > colunaB){
        colunas = colunaA - colunaB;
    }
    else{
        colunas = colunaB - colunaA;
    }
    
    if (linhas > colunas){
        relacao = linhas/colunas;
    }
    else{
        relacao = colunas/linhas;
    }

    /* acendendo a reta */
    
    
    /* caso 1: pra baixo e pra direita */
    if (linhaA < linhaB && colunaA < colunaB){
        relacao = (linhaB - linhaA)/(colunaB - colunaA);
        for (d = linhaA; d < 1; d++){
            for (m = colunaA; m < relacao; m++){
                if (monitor[d][m] != DEFEITUOSO){
                    monitor[d+1][m] = ACESO;
                }
                else{
                    return retaInvalida;
                }
            }
        }        
    }
    return ok;
}
/* $RCSfile$ */

