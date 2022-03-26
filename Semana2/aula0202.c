/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: contem o código fonte de um programa de testes para a função de fibonacci
*/


#include "aula0201.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


int main(int argc,char* argv[])
{ 
    int a;
    char* ptr;
    us num = strtoul(argv[1], &ptr, 10);
    ull prev = 0;
    for (a = 0; a <= num; a++){
        int valor = CalcularTermoSerieFibonacci(a);      
        if (valor < prev){
            printf("%s","Valor excede o máximo.");
            break;
        }
        prev = valor;
        
    }
    return 0; 

}


/*$RCSfile: aula0202.c,v $*/
