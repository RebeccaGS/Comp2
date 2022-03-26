/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: calcular o valor da série harmônica alternada usando do...while
*/


/*
S(n) = 0 se n é igual a 0.  
S(n) = 1 - 1/22 + 1/33 - 1/44 + ... -1/nn se n é par
S(n) = 1 - 1/22 + 1/33 - 1/44 + ... +1/nn se n é ímpar
*/

#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada (unsigned short int termo){
    float resultado = 0;
    long double exponencial;
    int numero = 1;

    /*se termo = 0, serie = 0*/
    if (termo == 0)
        resultado = 0;
    /*se termo dif de 0*/
    else {
        /*se termo par*/
        do{ 
            exponencial = CalcularExponencial(numero,numero);
            /* numero par, sinal negativo*/
            if (numero%2 == 0)
                resultado = resultado - 1/exponencial;                               
            /* numero impar, sinal positivo*/
            else
                resultado = resultado + 1/exponencial;
            numero++;    
                
        } while (numero != termo+1);
    }
    
    return resultado;
}

/*$RCSfile: aula0403b.c,v $*/