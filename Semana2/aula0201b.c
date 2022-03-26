/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: fibonacci usando do... while
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
