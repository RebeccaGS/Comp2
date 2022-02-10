/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: converte base 10 em 16.

$Author$
$Date$
$Log$ */

//  - Algoritmos de Codificação Base16, Base32 e Base64.
#include "aula0801.h"
#include <string.h>
#include <stdio.h>

// int *LISTA = (int *) malloc(sizeof(int));
//  if(!LISTA){
//   printf("Sem memoria disponivel!\n");
//   exit(1);

// FALTA:
// INVERTER: ta chegando 02B10E ; devia tar 201BE0 - como inverter?

tipoErros
CodificarBase16 (byte *bytes/* numero de bytes a codificar */, unsigned long long numerosBytes /* os bytes */, char *base16/* convertido */){
    unsigned short indice;
    unsigned short resto;

    //for (indice = numerosBytes; indice > 0; indice--){
    for (indice = 0; indice < numerosBytes; indice++){
        byte dividendo = bytes[indice];
        while (dividendo/16 != 0){
            resto = dividendo%16;
            if (resto < 9){
                strcat(base16[indice], resto); /* adiciona resto em resultado*/
            }
            else{
                char *restoAlterado = converteLetra(resto);
                strcat(base16[indice], restoAlterado); /* adiciona resto em resultado*/
            }
            dividendo = dividendo/16;
        }
        strrev(base16[indice]); /* inverter ordem dos restos que chegam */
    }
    return ok;
}


char converteLetra(unsigned short resto){ //tem *?
    if (resto == 10){
        return 'A';
    }
    else if (resto == 11){
        return 'B';
    }
    else if (resto == 12){
        return 'C';
    }
    else if (resto == 13){
        return 'D';
    }
    else if (resto == 14){
        return 'E';
    }
    else{
        return 'F';
    }
}




// nao: resultado = [resultado] + bytes[indice]/16;


/* $RCSfile$ */