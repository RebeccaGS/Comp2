/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: Calcular exponencial usando recursividade
*/

#include "aula0401.h" 

#define INFINITY    1.0/0.0
     
long double
CalcularExponencial (double numero, int exp){
    int sinal = 1;
    /*se expoente eh 0, retorna 1*/ /*caso base*/
    if(exp == 0)
        return 1.0;
        
    /*se num 0 e exp > 0, retorna 0*/
    if(numero == 0 && exp>0)
        return 0.0;
        
    /*proceder com numero negativo*/
    if(numero<0){
        numero = -numero;
        if(exp%2!=0)
            sinal = -1;
    }
    
    long double j;
    /*expoente negativo*/
    if(exp < 0){
        /*retorna infinito no 0 elevado a neg*/
        if (numero == 0)
            return INFINITY;
        /*para expoentes neg e numero dif de 0*/
        else{
            /*inverte sinal do expoente e inverte o numero*/
            exp = -exp;
            numero=1/numero;
        }
    }

    /*se par*/
    if (exp%2 == 0){
        j = CalcularExponencial (numero, exp/2);
        return sinal*j*j;
    }

    /*caso nao, eh impar*/
    j = CalcularExponencial (numero, (exp-1)/2);
    return sinal*j*j*numero;

}
/*$RCSfile: aula0401a.c,v $*/



