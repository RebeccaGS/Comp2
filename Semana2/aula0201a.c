/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: funcao principal para calculo do termo na serie fibonacci

$Author: rebecca.simao $
$Date: 2022/01/03 17:39:02 $
$Log: aula0201a.c,v $
Revision 1.1  2022/01/03 17:39:02  rebecca.simao
Initial revision

Revision 1.1  2021/12/14 00:19:52  rebecca.simao
Initial revision
*/


#include "aula0201.h"

/*fib = 0 1 1 2 3 5 8*/

ull CalcularTermoSerieFibonacci(us num){ 
    if (num <= 1) {return num;}
    return CalcularTermoSerieFibonacci(num-1) + CalcularTermoSerieFibonacci(num-2); 
}

/*$RCSfile: aula0201a.c,v $*/
