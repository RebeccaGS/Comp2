/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: prototipo de testes para calcular o valor da série harmônica alternada
$Author$
$Date$
$Log$*/



#include "aula0401.h"

#include <stdio.h> 
#include <stdlib.h>

#define SUCESSO	                                       0 	

int main(int argc,char* argv[]){
    /*definindo e pegando os argumentos*/
    unsigned short int termo;

    char* ptr;
    termo = strtol(argv[1], &ptr, 10);

    /*chamando a funcao*/
    float resultado = CalcularSerieHarmonicaAlternada (termo);
    printf("Resultado eh %f\n", resultado);
    return SUCESSO;
}

/*$RCSfile$*/