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

// ANOTACOES:
//Da por == quando é letra? tem q vir com um ' '?
// ver tipoErros (separar falhas percentuais? falta alguma? implementei todas?)
// SE ERRO COM USLEEP: Adicionar modulos
//# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
// testar outros modulos salvos em Pendencias - system(clear)
// indef depuracao (?)

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
    CLEAR_SCREEN;
    
    /* espera tempo / retorna 0 se sucesso e -1, se falha. */
    retornoEspera = usleep(tempoEspera);
    if (retornoEspera == -1){ 
        return falhaEspera;
    }
    
    /* reescreve matriz para 'o', ' ' e '.' ao inves de 1, 0 e -1*/
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

tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                                     unsigned numeroMaximoLinhas /* E */,
                                     unsigned numeroMaximoColunas, /* E */
                                     float percentualDefeituosos, /* E */
                                     float percentualApagados /* E */){
    
    /* definir variaveis */
    unsigned short numeroElementosTotais;
    unsigned short numeroElementosDefeituosos;
    unsigned short numeroElementosAcessos;
    unsigned short numeroElementosApagados;
    int linhaSorteada;
    int colunaSorteada;
    unsigned short d;
    unsigned short m;

    /* decobrir quant de elementos */
    numeroElementosTotais = numeroMaximoColunas*numeroMaximoLinhas;
    numeroElementosDefeituosos = percentualDefeituosos*numeroElementosTotais/100;
    numeroElementosApagados = percentualApagados*numeroElementosTotais/100;
    numeroElementosAcessos = numeroElementosTotais - numeroElementosDefeituosos - numeroElementosApagados;
    
    /* adicionar valores a elementos da matriz original */
    for (d = 0; d < numeroMaximoLinhas; d++){
        for (m = 0; m < numeroMaximoColunas; m++){
            if (numeroElementosDefeituosos>0){
                monitor[d][m] == defeituoso;
                numeroElementosDefeituosos--;
            }
            elif (numeroElementosAcessos>0){
                monitor[d][m] == aceso;
                numeroElementosAcessos--;
            }
            elif (numeroElementosApagados>0){
                monitor[d][m] == apagado;
                numeroElementosApagados--;
            }
        }
    }

    /* tornar aleatorio */
    for (d = 0; d < numeroMaximoLinhas; d++){
        for (m = 0; m < numeroMaximoColunas; m++){
                linhaSorteada = d + rand() % (numeroMaximoLinhas - d + 1);
                colunaSorteada = m + rand() % (numeroMaximoColunas - m + 1);
                monitor[d][m] = monitor[linhaSorteada][colunaSorteada];
        }
    }    

    return ok;
}



tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                       unsigned numeroMaximoLinhas, /* E */
                       unsigned numeroMaximoColunas){
    
    /* ir elemento a elemento para conferir se eh valido e apagar apenas estes */
    // pra transformar em 0 e apagar em mostrar matrizes OU transformar em ' ' direto?
    // pq tipo, vai ficar 0s e '.'?
    for (d = 0; d < numeroMaximoLinhas; d++){
        for (m = 0; m < numeroMaximoColunas; m++){
            if (monitor[d][m] != DEFEITUOSO){
            monitor[d][m] == apagado;
            }
        }
    }
    return ok;
}


/* $RCSfile$ */
