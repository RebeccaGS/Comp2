/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simão
Descricao: Calcular exponencial usando recursividade
$Author$
$Date$
$Log$*/

#include "aula0401.h"

#define INFINITY              0

long double
CalcularExponencial (double numero, int expoente){

    int expoenteusado = 0;
    long double resultado = 1;

    /*se expoente eh 0, retorna 1*/
    if(expoente == 0)
        return 1.0;

    /*expoente negativo*/
    if(expoente < 0){
        /*retorna infinito no 0 elevado a neg*/
        if (numero == 0)
            return INFINITY;
        /*para expoentes neg e numero dif de 0*/
        else{
            /*inverte sinal do expoente e inverte o numero*/
            expoenteusado = -expoente;
            numero=1/numero;
        }
    }

    else /*caso nao, nao precisa inverter sinal*/
        expoenteusado = expoente;

    /*multiplica numero por ele mesmo ate o expoente chegar a 0,
    sendo resultado inicial = 1*/
    do
    {
        resultado = resultado * numero;	/* resultado *= numero */
        expoenteusado--;
    }while(expoenteusado != 0);
    
    return resultado;

}

/*$RCSfile: $*/
