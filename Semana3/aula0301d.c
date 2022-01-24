/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Funcao calcula MDC utilizando o while
$Author: rebecca.simao $
$Date: 2022/01/03 18:04:11 $
$Log: aula0301d.c,v $
Revision 1.2  2022/01/03 18:04:11  rebecca.simao
Revisado

Revision 1.1  2021/12/17 00:54:06  rebecca.simao
Initial revision
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
    while (min != 0)
        {
            auxiliar = max;
            max = min;
            min = auxiliar%min;
        }
    return max;
}

/*$RCSfile: aula0301d.c,v $*/
