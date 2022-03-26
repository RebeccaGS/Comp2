/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: Funcao calcula MDC utilizando do ... while
*/


#include "aula0301.h"

#define min(x, y) (x < y ? x : y)
#define max(x, y) (x < y ? y : x)

ull CalcularMaximoDivisorComum (ull num1, ull num2){
    ull max = max(num1,num2);
    ull min = min(num1,num2);
    int auxiliar;
    
    /*confere se pelo menos um dos dois é 0*/
    if (num1 == 0 && num2 == 0)
        return 0;
    else if (num2 == 0)
        return num1;
    else if (num1 == 0)
        return num2;
    do
       {
            auxiliar = max;
            max = min;
            min = auxiliar%min;
       }
    while (min != 0);
    return max;
}

/*$RCSfile: aula0301b.c,v $*/

