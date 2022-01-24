/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: fibonacci usando do... while

$Author: rebecca.simao $
$Date: 2022/01/03 17:41:07 $
$Log: aula0201b.c,v $
Revision 1.1  2022/01/03 17:41:07  rebecca.simao
Initial revision

Revision 1.1  2021/12/14 02:31:39  rebecca.simao
Initial revision
*/


#include "aula0201.h"

/*fib = 0 1 1 2 3 5 8*/

ull CalcularTermoSerieFibonacci(us num){ 
    if (num > 1) {
        int indice = 0;
        int fibonacci = 0;
        int menos1 = 1;
        int menos2 = 0;
        do
        {
            fibonacci = menos1 + menos2;
            indice++;
            menos2 = menos1;
            menos1 = fibonacci; 
        }
        while (indice < num);
        return fibonacci;
    }    
    return num;
}

/*$RCSfile: aula0201b.c,v $*/
