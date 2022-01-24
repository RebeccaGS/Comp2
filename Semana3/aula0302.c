/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Funcao que testa a aula0301c.c, que por sua vez calcula MDC utilizando WHILE

$Author: rebecca.simao $
$Date: 2022/01/03 19:07:24 $
$Log: aula0302.c,v $
Revision 1.2  2022/01/03 19:07:24  rebecca.simao
Revisada 2

Revision 1.1  2022/01/03 18:06:22  rebecca.simao
Initial revision

Revision 1.1  2021/12/17 00:56:43  rebecca.simao
Initial revision
*/


#include "aula0301.h"

#include <stdio.h> 
#include <stdlib.h>
#include <errno.h>

#define SUCESSO	                                       0 						     
#define NUMERO_ARGUMENTOS_INVALIDO					   1 /*so 1 arg ou mais de 2*/
#define ARGUMENTO_CONTEM_CARACTERE_NEGATIVO		       2 /*tirar neg*/
#define ARGUMENTO_INVALIDO							   4 /*numero fora da range*/
#define ARGUMENTO_NAO_NUMERO                           5 
#define BASE_INVALIDA                                  6 
#define ARGUMENTO_CONTEM_CARACTERE_INVALIDO            7 
#define EOS                                            '\0'

int main(int argc,char** argv)
{ 
    ull x, y;
    char* pEnd;

    if (argc != 3){
        printf("%s", "Digite 2 numeros validos\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    if (argv[1][0] == '-' || argv[2][0] == '-'){
        printf("%s", "Apenas numeros positivos\n");
        exit (ARGUMENTO_CONTEM_CARACTERE_NEGATIVO);
    }

    x = strtoul(argv[1], &pEnd, 10);
    
    if (errno == ERANGE){
        printf("%s", "Valor fora da range\n");
        exit (ARGUMENTO_INVALIDO);
    }

    y = strtoul(argv[2], &pEnd, 10);
    
    if (errno == ERANGE){
        printf("%s", "Valor fora da range\n");
        exit (ARGUMENTO_INVALIDO);
    }
    
    if (*pEnd != EOS)
    {
    printf ("Argumento contem caractere invalido.\n");
    printf ("Primeiro caractere invalido: \'%c\"\n", *pEnd);
    exit (ARGUMENTO_CONTEM_CARACTERE_INVALIDO);
    }
    
    if (argv[1][0]<'0' || argv[1][0]>'9' || argv[2][0]<'0' || argv[2][0]>'9'){
        printf("%s", "Apenas numeros\n");
        exit (ARGUMENTO_NAO_NUMERO);
    }
    
    if (errno== EINVAL)
    {
    printf ("Base invalida\n");
    exit (BASE_INVALIDA);
    }

    ull MDC = CalcularMaximoDivisorComum (x,y);
    printf("MDC is %llu\n", MDC);
    return SUCESSO;
}


/*$RCSfile: aula0302.c,v $*/
