/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simão
Descricao: Funcao que referencia os metodos dos arquivos em c
$Author: rebecca.simao $
$Date: 2022/01/11 18:59:46 $
$Log: aula0402.c,v $
Revision 1.6  2022/01/11 18:59:46  rebecca.simao
erro atualizado

Revision 1.5  2022/01/11 05:44:00  rebecca.simao
atualizado

Revision 1.4  2022/01/10 23:08:21  rebecca.simao
versao final

Revision 1.3  2022/01/10 05:36:58  rebecca.simao
atualizado.

Revision 1.2  2022/01/10 00:46:31  rebecca.simao
versao atualizada.

Revision 1.1  2022/01/10 00:16:41  rebecca.simao
Initial revision
*/



#include "aula0401.h"

#include <stdio.h> 
#include <stdlib.h>
#include <float.h>
#include <limits.h> 
#include <errno.h>
#include <math.h>

#define SUCESSO	                              0
#define NUMERO_ARGUMENTOS_INVALIDO            1
#define EXP_CONTEM_CARACTERE_INVALIDO  	    	2
#define NUMERO_CONTEM_CARACTERE_INVALIDO  		3
#define BASE_NUMERO_INVALIDA									4
#define VALOR_MAXIMO_DOUBLE_EXCEDIDO	      	5
#define VALOR_MAXIMO_INT_EXCEDIDO             6
#define BASE_EXP_INVALIDA   									7

#define EOS																	'\0'
#define NUMERO_ARGUMENTOS                     3


/*#define _ISOC99_SOURCE       See feature_test_macros(7) */


int main(int argc,char** argv){
    /*definindo e pegando os argumentos*/
    double numero;
    int exp;
    char *verificacaoNumero;
    char *verificacaoExp;
       
    /*tratamentos de erro*/
    if (argc != NUMERO_ARGUMENTOS)
    {
      printf ("Uso: %s <double para o numero> <inteiro para expoente>\n", argv [0]);
      exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /*pegar numero e conferir validade*/
    numero = strtod (argv[1], &verificacaoNumero);
    /*float strtof(const char *restrict, char **restrict);*/
    
    if (errno == EINVAL)
    {
  		printf ("Base invalida\n");
      exit (BASE_NUMERO_INVALIDA);
    }
  
    if (errno == ERANGE)
  	{
  		printf ("Valor fornecido ultrapassa o valor maximo permitido para double (%lf)\n", 
  						 DBL_MAX);
      exit (VALOR_MAXIMO_DOUBLE_EXCEDIDO);
  	}
    
    if (*verificacaoNumero != EOS)
    {
      printf ("Argumento contem caractere invalido.\n");
      printf ("Primeiro caractere invalido: \'%c\'\n", *verificacaoNumero);
      exit (NUMERO_CONTEM_CARACTERE_INVALIDO);
    }
    
    /*pegar exp e conferir validade*/
    exp = strtol(argv[2], &verificacaoExp, 10);
    
    if (errno == EINVAL)
    {
  		printf ("Base invalida\n");
      exit (BASE_EXP_INVALIDA);
    }
  
    if (errno == ERANGE)
  	{
  		printf ("Valor fornecido ultrapassa o valor maximo permitido para int (%d)\n", 
  						 INT_MAX);
      exit (VALOR_MAXIMO_INT_EXCEDIDO);
  	}
    
    if (*verificacaoExp != EOS)
    {
      printf ("Argumento contem caractere invalido.\n");
      printf ("Primeiro caractere invalido: \'%c\'\n", *verificacaoExp);
      exit (EXP_CONTEM_CARACTERE_INVALIDO);
    }
    

    /*chamando a funcao*/
    long double exponencial = CalcularExponencial(numero,exp);
    printf("Resultado eh %Lf\n", exponencial);
    return SUCESSO;
}

/*$RCSfile: aula0402.c,v $*/
