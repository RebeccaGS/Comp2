/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: funcao principal para calculo do termo na serie fibonacci
*/


#include "aula0201.h"

/*fib = 0 1 1 2 3 5 8*/

ull CalcularTermoSerieFibonacci(us num){ 
    if (num <= 1) {return num;}
    return CalcularTermoSerieFibonacci(num-1) + CalcularTermoSerieFibonacci(num-2); 
}

/*$RCSfile: aula0201a.c,v $*/
