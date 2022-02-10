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

    for (indice = numerosBytes; indice > 0; indice--){
        while (bytes[indice]/16 != 0){
            resto = bytes[indice]%16;
            if (resto < 9){
                base16 = resto;  /* adiciona resto em resultado*/
            }
            else{
                char *restoAlterado = converteLetra(resto);
                base16 = restoAlterado; /* adiciona resto em resultado*/
                // FALTA INVERTER: ta chegando 02B10E ; devia tar 201BE0 - como inverter?
            }
        }
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