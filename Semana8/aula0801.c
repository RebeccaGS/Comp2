
/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: algoritmos de conversao de bytes: 16; 32; 64, e seus respectivos metodos de desconversao.

$Author$
$Date$
$Log$ */

#include "aula0801.h"
#include <string.h>
#include <stdio.h>

tipoErros CodificarBase16(byte *base10, unsigned long long numeroDeBytes, char *base16)
{
    /* definindo variaveis*/
    char *guiaBase16 = "0123456789ABCDEF";
    unsigned long long i, n = 0;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numeroDeBytesInvalido;

    if (base10 == NULL)
        return bytesPassadosVazio;

    /* percorrer de 1 em 1 nos elementos na base 16 */
    for (i = 0; i < numeroDeBytes; i++)
    {
        /* pra caso 1, onde ha necessidade de transicionar a pos em 4 antes de &00001111 */
        base16[n++] = guiaBase16[(base10[i] >> 4) & 0x0F];
        
        /* pra caso 2, onde pos ja esta correta, necessitando apenas de &00001111 */
        base16[n++] = guiaBase16[base10[i] & 0x0F];
    }

    base16[n] = '\0';
    return ok;
}


/* ------------------------------------------------- 
------------------------------------------------- */
tipoErros DecodificarBase16 (char *base16, byte *base10, unsigned long long *numeroEmBase10){

    /* definindo variaveis*/
    char *tabelaBase16 = "0123456789ABCDEF";
    short i, n = 0, a, auxiliar1 = -1, auxiliar2 = -1;

    if (base16 == NULL){
        return bytesPassadosVazio;
    }
    if (numeroEmBase10 == 0){
        return numeroDeBytesInvalido;
    }

    /* procurar de 2 em 2 */
    for (i = 0; base16[i] != '\0'; i = i + 2){
        for (a = 0; a < 16; a++){
            if (base16[i] == tabelaBase16[a]){
                auxiliar1 = a; /* a = posicao na tabela */
            }
        }
        if (auxiliar1 == -1){
            return foraDaRange;
        }
    
        for (a = 0; a < 16; a++){
            if (base16[i+1] == tabelaBase16[a]){
                auxiliar2 = a; /* a = posicao na tabela */
            }
        }    
        if (auxiliar2 == -1){
            return foraDaRange;
        }
        base10[n++] = auxiliar1 << 4 | auxiliar2;
    }
    base10[n] = '\0';
    return ok;
}


/* ------------------------------------------------- 
----------------------------------------------------
------------------------------------------------- */

tipoErros CodificarBase32 (byte *base16, unsigned long long numeroDeBytes, tipoAlfabetoBase32 alfabeto, char *base32){
    /* definindo variaveis */
    char *Base32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
    char *Base32Estendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";
    unsigned short gruposDe5, restoBytes, grupo, indiceSaida, indiceEntrada, contador;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numeroDeBytesInvalido;

    if (numeroDeBytes == NULL)
        return bytesPassadosVazio;

    
    /* para auxiliar casos */
    gruposDe5 = numeroDeBytes/5; /* grupos de bytes sem sobrar caso */
    restoBytes = numeroDeBytes%5;
    
    indiceSaida = 0;
    indiceEntrada = 0;
    /* andar de 1 em 1 em cada grupo */
    for (grupo = 0; grupo < gruposDe5; grupo++){
        /* 1 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada] << 2) & 0x1C) | ((conjuntoDeBytes [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada+1] << 4) & 0x10) | ((conjuntoDeBytes [indiceEntrada+2] >> 4) & 0x0F)];
        /* 5 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada+2] << 1) & 0x1E) | ((conjuntoDeBytes [indiceEntrada+2] >> 7) & 0x01)];
        /* 6 */    
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+3] >> 2) & 0x1F];
        /* 7 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada+3] << 3) & 0x18 )|( (conjuntoDeBytes [indiceEntrada+4] >> 5) & 0x07)];
        /* 8 */
        saida[indiceSaida++] = Base32[conjuntoDeBytes [indiceEntrada+4] & 0x1F];

        indiceEntrada = indiceEntrada + 5;

    }

    /* se houverem casos restantes, completar com '=' */
    /* sobrou 1 byte - 2 '=' /// 00110000  */
    if (restoBytes == 4){
        /* 1 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada] << 2) & 0x1C) | ((conjuntoDeBytes [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada+1] << 4) & 0x10) | ((conjuntoDeBytes [indiceEntrada+2] >> 4) & 0x0F)];
        /* 5 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada+2] << 1) & 0x1E) | ((conjuntoDeBytes [indiceEntrada+2] >> 7) & 0x01)];
        /* 6 */    
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+3] >> 2) & 0x1F];
        /* 7 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+3] << 3) & 0x18];
        
        saida[indiceSaida++] = '=';
    }

    /* sobrou 2 bytes - 1 '=' /// 00111100 */
    else if (restoBytes == 3){
        /* 1 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada] << 2) & 0x1C) | ((conjuntoDeBytes [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada+1] << 4) & 0x10) | ((conjuntoDeBytes [indiceEntrada+2] >> 4) & 0x0F)];
        /* 5 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+2] << 1) & 0x1E];
        
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';

    }

    else if (restoBytes == 2){
        /* 1 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        saida[indiceSaida++] = Base32[((conjuntoDeBytes [indiceEntrada] << 2) & 0x1C) | ((conjuntoDeBytes [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada+1] << 4) & 0x10];
        
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';

    }

    else if (restoBytes == 1){
        /* 1 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        saida[indiceSaida++] = Base32[(conjuntoDeBytes [indiceEntrada] << 2) & 0x1c];
        
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';

    }
                                                                                                                                                                                            

    saida[indiceSaida] = '\0';
    return ok;
}

/* -------------------------------------------------  
------------------------------------------------- */

tipoErros DecodificarBase32 (char *base32, tipoAlfabetoBase32 alfabeto, byte *base16, unsigned long long *numeroEmBase16){
    
    /* definindo variaveis */
    char *guiaBase32Simples = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
    char *guiaBase32Estendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";
    char *guiaBase32;

    short auxiliar1 = -1,auxiliar2 = -1,auxiliar3 = -1,auxiliar4 = -1, auxiliar5 = -1,auxiliar6 = -1,auxiliar7 = -1,auxiliar8 = -1;
    unsigned short i, a, n = 0;

    /* tipoErros*/
    if (numeroEmBase16 == 0)
        return numeroDeBytesInvalido;

    if (base32 == NULL)
        return bytesPassadosVazio;

    if (alfabeto != 1 || alfabeto != 0)
        return finalLinhaInvalido;
    
    /* definindo alfabeto a ser usado */
    if (alfabeto == 1){
        guiaBase32 = guiaBase32Estendido;
    }
    else{
        guiaBase32 = guiaBase32Simples;
    }

    /* procurar de 8 em 8 */
    for (i = 0; base32[i] != '\0'; i = i + 8){
        for (a = 0; a < 64; a++){
            if (base32[i] == guiaBase32[a]){
                auxiliar1 = a; /* a = posicao na tabela */
            }
            if (base32[i+1] == guiaBase32[a]){
                auxiliar2 = a; 
            }
            if (base32[i+2] == guiaBase32[a]){
                auxiliar3 = a;
            }
            if (base32[i+3] == guiaBase32[a]){
                auxiliar4 = a;
            }
            if (base32[i+3] == guiaBase32[a]){
                auxiliar5 = a;
            }
            if (base32[i+3] == guiaBase32[a]){
                auxiliar6 = a;
            }
            if (base32[i+3] == guiaBase32[a]){
                auxiliar7 = a;
            }
            if (base32[i+3] == guiaBase32[a]){
                auxiliar8 = a;
            }
        }
        if (auxiliar1 == -1 || auxiliar2 == -1 || auxiliar3 == -1 || auxiliar4 == -1 || auxiliar5 == -1 || auxiliar6 == -1 || auxiliar7 == -1 || auxiliar8 == -1){
            return foraDaRange;
        }
    
        base16[n++] = (auxiliar1 << 3) | (auxiliar2 >> 2);
        base16[n++] = (auxiliar2 << 6 & 0xC0) | (auxiliar3 << 1) | (auxiliar4 >> 4);
        base16[n++] = (auxiliar4 << 4 & 0xF0) | (auxiliar5 >> 1);
        base16[n++] = (auxiliar5 << 7 & 0x80) | (auxiliar6 << 2) | (auxiliar7 >> 3);
        base16[n++] = (auxiliar7 << 5 & 0xE0) | (auxiliar8);
    }
    base16[n] = '\0';
    return ok;

}   
/* ------------------------------------------------- 
---------------------------------------------------- 
------------------------------------------------- */

tipoErros CodificarBase64 (byte *conjuntoDeBytes, unsigned long long numeroDeBytes, tipoFinalLinha finalLinha, char *saida){

    /* definindo variaveis */
    char *Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    unsigned short gruposDe3, restoBytes, grupo, indiceSaida, indiceEntrada, contador;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numeroDeBytesInvalido;

    if (conjuntoDeBytes == NULL)
        return bytesPassadosVazio;

    if (finalLinha != 1 || finalLinha != 0)
        return finalLinhaInvalido;
        
    /* para auxiliar casos */
    gruposDe3 = numeroDeBytes/3; /* grupos de bytes sem sobrar caso */
    restoBytes = numeroDeBytes%3;
    
    indiceSaida = 0;
    indiceEntrada = 0;
    /* andar de 1 em 1 em cada grupo */
    for (grupo = 0; grupo < gruposDe3; grupo++){
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] >> 2) & 0x3F];

        saida[indiceSaida++] = Base64[((conjuntoDeBytes [indiceEntrada] << 4) & 0x30 )|( (conjuntoDeBytes [indiceEntrada+1] >> 4) & 0x0F)];

        saida[indiceSaida++] = Base64[((conjuntoDeBytes [indiceEntrada+1] << 2) & 0x3C) |( (conjuntoDeBytes [indiceEntrada+2] >> 6) & 0x03)];

        saida[indiceSaida++] = Base64[conjuntoDeBytes [indiceEntrada+2] & 0x3F];

        indiceEntrada = indiceEntrada + 3;

        if (finalLinha == 1){
            contador = contador + 4;
            if (contador == 76){
                saida[indiceSaida++] = '\r';
                saida[indiceSaida++] = '\n';
                contador = 0;
            }
        }
    }

    /* se houverem casos restantes, completar com '=' */
    /* sobrou 1 byte - 2 '=' /// 00110000  */
    if (restoBytes == 1){
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] >> 2) & 0x3F];

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 4) & 0x30];
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';

        if (finalLinha == 1){
            contador = contador + 4;
        }
    }

    /* sobrou 2 bytes - 1 '=' /// 00111100 */
    else if (restoBytes == 2){
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] >> 2) & 0x3F];
        saida[indiceSaida++] = Base64[((conjuntoDeBytes [indiceEntrada] << 4) & 0x30) | ((conjuntoDeBytes [indiceEntrada+1] >> 4) & 0x0F)];

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 2) & 0x3C];
        saida[indiceSaida++] = '=';
    
        if (finalLinha == 1){
            contador = contador + 4;
        }
    }

    if (contador != 0 && finalLinha == 1){
        saida[indiceSaida++] = '\r';
        saida[indiceSaida++] = '\n';
    }

    saida[indiceSaida] = '\0';
    return ok;
}   

/* ------------------------------------------------- 
------------------------------------------------- */
tipoErros DecodificarBase64 (char *base64, tipoFinalLinha finalDeLinha, byte *base16, unsigned long long *numeroEmBase16){
    
    /* definindo variaveis */
    char *guiaBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    short auxiliar1 = -1,auxiliar2 = -1,auxiliar3 = -1,auxiliar4 = -1;
    unsigned short i, a, n = 0;

    /* tipoErros*/
    if (numeroEmBase16 == 0)
        return numeroDeBytesInvalido;

    if (base64 == NULL)
        return bytesPassadosVazio;

    if (finalDeLinha != 1 || finalDeLinha != 0)
        return finalLinhaInvalido;
    
    /* procurar de 4 em 4 */
    for (i = 0; base64[i] != '\0'; i = i + 4){
        for (a = 0; a < 64; a++){
            if (base64[i] == guiaBase64[a]){
                auxiliar1 = a; /* a = posicao na tabela */
            }
            if (base64[i+1] == guiaBase64[a]){
                auxiliar2 = a; 
            }
            if (base64[i+2] == guiaBase64[a]){
                auxiliar3 = a;
            }
            if (base64[i+3] == guiaBase64[a]){
                auxiliar4 = a;
            }
        }
        if (auxiliar1 == -1 || auxiliar2 == -1 || auxiliar3 == -1 || auxiliar4 == -1){
            return foraDaRange;
        }
    
        base16[n++] = (auxiliar1 << 2) | (auxiliar2 >> 4);
        base16[n++] = (auxiliar2 << 4 & 0xF0) | (auxiliar3 >> 2);
        base16[n++] = (auxiliar3 << 6 & 0xC0) | (auxiliar4);
    }
    base16[n] = '\0';
    return ok;

}   

/* $RCSfile$ */