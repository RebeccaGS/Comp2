/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: implementacao de calcular menor complementar

$Author$
$Date$
$Log$
*/

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4

#define EOS				      					'\0'

#include "aula0601.c"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h> /* DBL_MAX */
#include <errno.h>


int main (int argc, char **argv){

    /* definir variaveis usadas */
    double matriz [LINHAS_MATRIZES][COLUNAS_MATRIZES];
    unsigned short ordem;
    unsigned short linha;
    unsigned short coluna;
    double *menorComplementar;
    char *verificacao;
    unsigned short i = 1; /* indice dos for */
    unsigned short m;
    unsigned short n;

    /* se possui no minimo ordem, linha, coluna e 1 elemento */
    if (argc < 5){
        printf("%s", ">ordem< >linhas< >coluna< >elementos func<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    ordem = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base ordem invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para ordem ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Ordem contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
  
    linha = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base de linha invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor de Linha fornecido ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Linha contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
  
    coluna = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Base de coluna invalida\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para coluna ultrapassa o valor maximo permitido para unsigned short (%d)\n",USHRT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Coluna contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
  
    
    /* tratamento de erros - numero de argumentos */
    if (argc < ordem*ordem + 4){
        printf("%s", ">ordem< >linhas< >coluna< >elementos func<\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    for (m = 0; m < ordem; m++){
        for (n = 0; n < ordem; n++){
            matriz[m][n] = strtod(argv[i], &verificacao);
            i++;
        }
    }

    /* verificacao de erros na coleta de elementos matriz */
    if (errno == ERANGE){
  		printf ("Valor fornecido ultrapassa o valor maximo permitido para double (%d)\n",DBL_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Argumento contem caractere invalido.\n");
        printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    /* enviar argumentos */
    tipoErros retorno = CalcularMenorComplementar(ordem,linha,coluna,matriz,menorComplementar);
    
    /* conferir se o retorno ta ok */
    if (retorno != ok)
        printf ("Erro executando a funcao. Erro numero %u.\n", retorno); // eh % u msm?

    else{
        /* printar matriz na tela */
        for (m = 0; m < ordem; m++){
            for (n = 0; n < ordem; n++){
                printf("%.5lf ", matriz[m][n]);
            }
            printf("\n");
        }
    }
    
    return OK;
}

/* $RCSfile$ */