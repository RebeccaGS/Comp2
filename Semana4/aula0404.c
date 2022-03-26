/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: prototipo de testes para calcular o valor da série harmônica alternada
*/

#ifdef __linux__
#define _XOPEN_SOURCE   600
#endif

#include "aula0401.h"

#include <stdio.h> 
#include <stdlib.h>
#include <float.h>
#include <errno.h>

#define SUCESSO	                              0
#define NUMERO_ARGUMENTOS_INVALIDO            1
#define ARGUMENTO_FORA_DA_RANGE               2
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO		3
#define BASE_INVALIDA													4
#define VALOR_MAXIMO_FLOAT_EXCEDIDO	        	5

#define EOS																	'\0'
#define NUMERO_ARGUMENTOS                     2

int main(int argc,char* argv[]){
    /*definindo e pegando os argumentos*/
    float porcento;
    unsigned short int termo;
    char *verificacao;
    float diferenca = 1;
    float produto = 0;
    float resultado;
    
    /*tratamentos de erro*/
    if (argc != NUMERO_ARGUMENTOS)
    {
      printf ("Uso: %s <inteiro-nao-negativo>\n", argv [0]);
      exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    porcento = strtof(argv[1], &verificacao);
    
    if (errno == EINVAL)
    {
  		printf ("Base invalida\n");
      exit (BASE_INVALIDA);
    }
  
    if (errno == ERANGE)
  	{
  		printf ("Valor fornecido ultrapassa o valor maximo permitido para float (%f)\n", 
  						 FLT_MAX);
      exit (VALOR_MAXIMO_FLOAT_EXCEDIDO);
  	}
    
    if (*verificacao != EOS)
    {
      printf ("Argumento contem caractere invalido.\n");
      printf ("Primeiro caractere invalido: \'%c\'\n", *verificacao);
      exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
    }
    
    if (!(0 < porcento && porcento < 1))
    {
      printf ("porcentagem deve ser dada entre 0 e 1\n");
      exit (ARGUMENTO_FORA_DA_RANGE);
    }
    
    /*printando a funcao com 0*/
    resultado = CalcularSerieHarmonicaAlternada (0);
    printf("S(0) = %.10f\n",resultado);
    
    /*|S (N) - S (N-1)| <= P vezes S (N - 1)*/
    /* entao: |S (n) - S (n-1)| > P * S (n - 1)*/
    for (termo = 1; diferenca > produto; termo++)
    {
      diferenca = CalcularSerieHarmonicaAlternada (termo) - CalcularSerieHarmonicaAlternada (termo-1);
      if (diferenca < 0)
        diferenca = -1*diferenca;
      produto = porcento*CalcularSerieHarmonicaAlternada (termo-1);
      
      /*printando a funcao*/
      resultado = CalcularSerieHarmonicaAlternada (termo);
      printf("S(%u) = %.10f\n", termo,resultado);
    }
    
    return SUCESSO;
}

/*$RCSfile: aula0404.c,v $*/
