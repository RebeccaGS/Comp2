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

    /* verificar se linhas e colunas > 100 */
    if (linhas1 > LINHAS_MATRIZES){
        return linhas1excedidas;
    }
    if (linhas2 > LINHAS_MATRIZES){
        return linhas2excedidas;
    }
    if (colunas1 > COLUNAS_MATRIZES){
        return colunas1excedidas;
    }
    if (colunas2 > COLUNAS_MATRIZES){
        return colunas2excedidas;
    }
    
    
    /* verificar se sao validas para multiplicacao de matrizes */
    if (colunas1 != linhas2){
        return matrizInvalida;
    }

    /* Verificar se matrizes vazias */
    if (matriz1 == NULL){
        return matriz1nula;
    }

    if (matriz2 == NULL){
        return matriz2nula;
    }

    if (matrizProduto == NULL){
            return matrizresultadonulo;
        }

    /* calcular matriz produto*/
    for (m = 0; m < linhas1; m++){
        for (p = 0; p < colunas2; p++){
            matrizProduto[m][p] = 0;
            for (n = 0; n < colunas1; n++){
                /* incrementar func*/
                matrizProduto[m][p] += matriz1[m][n] * matriz2[n][p];
            }
        }  
    }  
    for (m = 0; m < linhas1; m++){
        for (p = 0; p < colunas2; p++){
            printf("%.5lf ", matrizProduto[m][p]);
        }
        printf("\n\n");
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

    /* verificar se linhas e colunas > 100 */
    if (linhasOriginal > LINHAS_MATRIZES){
        return linhas1excedidas;
    }
 
    if (colunasOriginal > COLUNAS_MATRIZES){
        return colunas1excedidas;
    }

    /* Verificar se matrizes vazias */
    if (matrizOriginal == NULL){
        return matriz1nula;
    }

    if (matrizTransposta == NULL){
        return matriz2nula;
    }

    /* matriz transposta */
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
  
    printf("entrou");
    /* verificar se linhas e colunas > 100 */
    if (ordem > LINHAS_MATRIZES){
        return ordemInvalida;
    }

    /* Verificar se matriz vazia */
    if (matriz == NULL){
        return matriz1nula;
    }


    printf("entrou2");
    /* calculo determinante */
    if (ordem == 1){
        *determinante = matriz[0][0];
    }

    else if (ordem == 2){
         printf("entrou3");
         double prod = matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
         printf("\ne %lf\n",prod);
        *determinante = prod;
         printf("saiu0");
    }

    else if (ordem == 3){
        /* regra de Sarrus */
        *determinante = 0;
        *determinante += (matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1]);
        *determinante -= (matriz[0][2]*matriz[1][1]*matriz[2][0] + matriz[0][0]*matriz[1][2]*matriz[2][1] + matriz[0][1]*matriz[1][0]*matriz[2][2]);
    }

    else if (ordem > 3){
        /* laplace */
        *determinante = 0;
        /* pegar elementos da primeira linha (0) e calcular */
        for (i = 0; i<ordem; i++){
            double complementoAlgebrico;
            CalcularComplementoAlgebrico(ordem,0,i,matriz,&complementoAlgebrico);
            *determinante +=  matriz[0][i] * complementoAlgebrico;
        }
    }
    printf("saiu2");
    
    /* Verificar se determinante vazio */
    if (determinante == NULL){
        return determinanteNulo;
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

    /* verificar se linhas e colunas > 100 */
    if (ordem > LINHAS_MATRIZES){
        return ordemInvalida;
    }

    if (linha > LINHAS_MATRIZES){
        return linhas1excedidas;
    }

    if (coluna > LINHAS_MATRIZES){
        return colunas1excedidas;
    }

    /* Verificar se matriz vazia */
    if (matriz == NULL){
        return matriz1nula;
    }


    /* Criar matriz auxiliar sem a linha e a coluna em questao */
    for (m = 0; m < ordem; m++){
        if (m == linha)
            continue;        
        for (n = 0; n < ordem; n++){
            if (n == coluna){
                continue;
            }
            matrizComplementar[l][k] = matriz [m][n];
            k++;
        }
        l++;
        k = 0;
    }    
    /* enviar matriz auxiliar para calcular o determinante */    
    CalcularDeterminanteMatriz(ordem-1,matrizComplementar,menorComplementar);
    printf("saiu");
    
        /* Verificar se determinante vazio */
    if (menorComplementar == NULL){
        return determinanteNulo;
    }

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
    int pot;
    
    /* verificar se linhas e colunas > 100 */
    if (ordem > LINHAS_MATRIZES){
        return ordemInvalida;
    }

    if (linha > LINHAS_MATRIZES){
        return linhas1excedidas;
    }

    if (coluna > LINHAS_MATRIZES){
        return colunas1excedidas;
    }

    /* Verificar se matriz vazia */
    if (matriz == NULL){
        return matriz1nula;
    }


    CalcularMenorComplementar(ordem,linha,coluna,matriz,&menorComplementar);
    if ((linha+coluna)%2 == 0)
      pot = 1;
    else
      pot = -1;
    *complementoAlgebrico = pot * menorComplementar;
    
    /* Verificar se determinante vazio */
    if (complementoAlgebrico == NULL){
        return determinanteNulo;
    }
    
    return ok;
}

/* $RCSfile$ */
