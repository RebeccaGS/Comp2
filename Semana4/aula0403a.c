/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: REBECCA GOMES SIMAO
Descricao: calcular o valor da série harmônica alternada usando recursividade
$Author$
$Date$
$Log$*/

/*
S(n) = 0 se n é igual a 0.
S(n) = 1 - 1/22 + 1/33 - 1/44 + ... -1/nn se n é par
S(n) = 1 - 1/22 + 1/33 - 1/44 + ... +1/nn se n é ímpar
*/

#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada (unsigned short int termo){

    /*se termo = 0, serie = 0*/
    if (termo == 0)
        return 0;
    /*se termo dif de 0*/
    if (termo%2 == 0){
        return CalcularSerieHarmonicaAlternada (termo - 1) - 1/CalcularExponencial(termo,termo);
    }
    /*impar*/
    return CalcularSerieHarmonicaAlternada (termo - 1) + 1/CalcularExponencial(termo,termo);
}

/*$RCSfile$*/