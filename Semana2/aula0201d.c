/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: fibonacci usando while

$Author: rebecca.simao $
$Date: 2022/01/03 17:41:46 $
$Log: aula0201d.c,v $
Revision 1.1  2022/01/03 17:41:46  rebecca.simao
Initial revision

Revision 1.1  2021/12/14 02:35:35  rebecca.simao
Initial revision
*/


#include "aula0201.h"

/*fib = 0 1 1 2 3 5 8*/

ull CalcularTermoSerieFibonacci(us num){
    if (num > 1) {
        int fibonacci = 0;
        int menos1 = 1;
        int menos2 = 0;
        int indice = 0;
        while (indice < num)
        {
            fibonacci = menos1 + menos2;   
            menos2 = menos1;
            menos1 = fibonacci; 
            indice++;
        }
        return fibonacci;
    } 
    return num;   
}

/*$RCSfile: aula0201d.c,v $*/
