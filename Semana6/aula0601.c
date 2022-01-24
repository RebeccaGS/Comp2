/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: implementacao da aula 06

$Author$
$Date$
$Log$
*/


// ERROS E ANOTACOES:
// Verificar cada tipo erro
// nao ta printando certo

#include "aula0601.h"
#include <stdio.h> /* incluir NULL */
#include <math.h>

tipoErros
MultiplicarMatrizes (unsigned short linhas1, /* numero de linhas da matriz 1 (E) */
                            unsigned short colunas1, /* numero de colunas da matriz 1 (E) */
                            unsigned short linhas2, /* numero de linhas da matriz 2 (E) */
                            unsigned short colunas2, /* numero de colunas da matriz 2 (E) */
                            double matriz1[LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz 1 (E) */
                            double matriz2[LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz 2 (E) */
                            double matrizProduto[LINHAS_MATRIZES][COLUNAS_MATRIZES]){ /* matriz produto (S) */

    /* definir variaveis */
    unsigned short m;  /* matriz1[m][n] * matriz2[n][p] = matrizproduto[m][p]*/
    unsigned short p;
    unsigned short n;

    /*tipo erros se argumento nulo ou se matriz eh invalida */
    if (colunas1 != linhas2){
        return matrizInvalida;
    }

    for (m = 0; m < linhas1; m++){
        for (p = 0; p < colunas2; p++){
            matrizProduto[m][p] = 0;
            for (n = 0; n < colunas1; n++){
                /* incrementar func*/
                matrizProduto[m][p] += matriz1[m][n] * matriz2[n][p];
            }
        }
    }        
    return ok;
}

tipoErros
ObterMatrizTransposta (unsigned short linhasOriginal, /* numero de linhas da matriz original (E) */
                                    unsigned short colunasOriginal, /* numero de colunas da matriz original (E) */
                                    double matrizOriginal[LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz original (E) */
                                    double matrizTransposta[LINHAS_MATRIZES][COLUNAS_MATRIZES]){ /* matriz transposta (S) */
        
    /* definir variaveis */
    unsigned short m;
    unsigned short p;

    for (m = 0; m < colunasOriginal; m++){
        for (p = 0; p < linhasOriginal; p++){
            matrizTransposta[m][p] = matrizOriginal[p][m];
        }
    } 
    
    return ok;
}


tipoErros
CalcularDeterminanteMatriz (unsigned short ordem, /* ordem da matriz (E) */
                                           double matriz[LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz (E) */
                                           double *determinante){ /* determinante (S) */
    unsigned short i;

    if (ordem ==1){
        *determinante = matriz[0][0];
    }

    if (ordem == 2){
        *determinante = matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0];
    }

    if (ordem == 3){
        /* regra de Sarrus */
        *determinante = 0;
        *determinante += (matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1]);
        *determinante -= (matriz[0][2]*matriz[1][1]*matriz[2][0] + matriz[0][0]*matriz[1][2]*matriz[2][1] + matriz[0][1]*matriz[1][0]*matriz[2][2]);
    }

    if (ordem > 3){
        /* laplace */
        *determinante = 0;
        /* pegar elementos da primeira linha (0) e calcular */
        for (i = 0; i<ordem; i++){
            double complementoAlgebrico;
            tipoErros retorno = CalcularComplementoAlgebrico(ordem,0,i,matriz,&complementoAlgebrico);
            *determinante +=  matriz[0][i] * complementoAlgebrico;
        }
    }
    return ok;
}

/* cria matriz auxiliar e possui ja seu determinante */
tipoErros
CalcularMenorComplementar (unsigned short ordem, /* ordem da matriz (E) */
                                            unsigned short linha, /* linha do elemento (E) */
                                            unsigned short coluna, /* coluna do elemento (E) */
                                            double matriz[LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz (E) */
                                            double *menorComplementar){ /* menor complementar (S) */
    
    double matrizComplementar[LINHAS_MATRIZES][COLUNAS_MATRIZES];
    unsigned short m; /* linha matriz original */
    unsigned short n;
    unsigned short l = 0; /* linha matriz auxiliar */
    unsigned short k = 0;

    for (m = 0; m < ordem; m++){
        if (m == linha){
            m = m+1;
            }
        for (n = 0; n < ordem; n++){
            if (n == coluna){
                n = n + 1;
                }
            matrizComplementar[l][k] = matriz [m][n];
        }
    }    
    
    tipoErros retorno = CalcularDeterminanteMatriz(ordem-1,matrizComplementar,menorComplementar);

    return ok;
}

/* calcula o cofator */
tipoErros
CalcularComplementoAlgebrico (unsigned short ordem, /* ordem da matriz (E) */
                                                unsigned short linha, /* linha do elemento (E) */
                                                unsigned short coluna, /* coluna do elemento (E) */
                                                double matriz[LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz (E) */
                                                double *complementoAlgebrico){ /* complemento algebrico ou cofator (S) */
    
    double menorComplementar;
    tipoErros retorno = CalcularMenorComplementar(ordem,linha,coluna,matriz,&menorComplementar);
    double pot = pow(-1,linha+coluna);
    *complementoAlgebrico = pot * menorComplementar;

    return ok;
}

/* $RCSfile$ */