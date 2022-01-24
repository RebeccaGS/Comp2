/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simão
Descricao: Calcular exponencial usando recursividade
$Author: rebecca.simao $
$Date: 2022/01/10 05:34:53 $
$Log: aula0401a.c,v $
Revision 1.3  2022/01/10 05:34:53  rebecca.simao
versao com erros corrigidos
implementacao 0 elevado a pos
numero neg elevado a impar
numero neg elevado a expoente par

Revision 1.2  2022/01/10 00:46:07  rebecca.simao
versao atualizada.

Revision 1.1  2022/01/10 00:15:23  rebecca.simao
Initial revision
*/

#include "aula0401.h" 
#include <stdio.h> 
#include <math.h>

#if defined (__STRICT_ANSI__) && defined (__linux__)
    #define   INFINITY    1.0/0.0
#endif

long double
CalcularExponencial (double numero, int exp){
    long double j;
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



