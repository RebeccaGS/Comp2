/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: contem o código fonte de um programa de testes para a função de fibonacci

$Author: rebecca.simao $
$Date: 2022/01/03 17:42:08 $
$Log: aula0202.c,v $
Revision 1.1  2022/01/03 17:42:08  rebecca.simao
Initial revision

Revision 1.1  2021/12/14 00:17:59  rebecca.simao
Initial revision
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
