/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: arquivo .h da aula 06
*/


#ifndef   _AULA0601_
#define   _AULA0601_    "@(#)aula0601.h $Revision: 1.1 $"

#define LINHAS_MATRIZES      100
#define COLUNAS_MATRIZES     100


typedef enum {ok = 0, matriz1nula = 21, matriz2nula = 22, matrizresultadonulo = 23, matrizInvalida = 24,
                         linhas1excedidas = 25, colunas1excedidas = 26, linhas2excedidas = 27, colunas2excedidas = 28, ordemInvalida = 29, determinanteNulo = 30} tipoErros;

tipoErros
MultiplicarMatrizes (unsigned short linhas1, /* numero de linhas da matriz 1 (E) */
                              unsigned short colunas1, /* numero de colunas da matriz 1 (E) */
                              unsigned short linhas2, /* numero de linhas da matriz 2 (E) */
                              unsigned short colunas2, /* numero de colunas da matriz 2 (E) */
                             double [LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz 1 (E) */
                             double [LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz 2 (E) */
                             double [LINHAS_MATRIZES][COLUNAS_MATRIZES]); /* matriz produto (S) */

tipoErros
ObterMatrizTransposta (unsigned short, /* numero de linhas da matriz original (E) */
                                    unsigned short, /* numero de colunas da matriz original (E) */
                                    double [LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz original (E) */
                                    double [LINHAS_MATRIZES][COLUNAS_MATRIZES]); /* matriz transposta (S) */

tipoErros
CalcularMenorComplementar (unsigned short, /* ordem da matriz (E) */
                                            unsigned short, /* linha do elemento (E) */
                                            unsigned short, /* coluna do elemento (E) */
                                           double [LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz (E) */
                                           double *); /* menor complementar (S) */

tipoErros
CalcularComplementoAlgebrico (unsigned short, /* ordem da matriz (E) */
                                                unsigned short, /* linha do elemento (E) */
                                                unsigned short, /* coluna do elemento (E) */
                                                double [LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz (E) */
                                                double *); /* complemento algebrico ou cofator (S) */

tipoErros
CalcularDeterminanteMatriz (unsigned short, /* ordem da matriz (E) */
                                           double [LINHAS_MATRIZES][COLUNAS_MATRIZES], /* matriz (E) */
                                           double *); /* determinante (S) */

#endif  

/* $RCSfile: aula0601.h,v $ */
