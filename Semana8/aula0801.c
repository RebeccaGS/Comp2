
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

    if (base16 == NULL)
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
    if (numeroEmBase10 == NULL){
        return numeroDeBytesInvalido;
    }
    if (base10 == NULL)
        return bytesPassadosVazio;

    if (strlen(base16) % 2 != 0){
        return foraDaRange;
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
    *numeroEmBase10 = strlen(base16)/2;
    return ok;
}


/* ------------------------------------------------- 
----------------------------------------------------
------------------------------------------------- */

tipoErros CodificarBase32 (byte *base16, unsigned long long numeroDeBytes, tipoAlfabetoBase32 alfabeto, char *base32){
    /* definindo variaveis */
    char *guiaBase32Simples = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
    char *guiaBase32Estendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";
    unsigned short gruposDe5, restoBytes, grupo, indiceSaida, indiceEntrada, contador;
    char *guia;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numeroDeBytesInvalido;

    if (base16 == NULL)
        return bytesPassadosVazio;

    if (alfabeto != 0 && alfabeto != 1){
        return alfabetoInvalido;
    }

    if (alfabeto == 1){
        guia = guiaBase32Estendido;
    }
    else{
        guia = guiaBase32Simples;
    }
    /* para auxiliar casos */
    gruposDe5 = numeroDeBytes/5; /* grupos de bytes sem sobrar caso */
    restoBytes = numeroDeBytes%5;
    
    indiceSaida = 0;
    indiceEntrada = 0;
    /* andar de 1 em 1 em cada grupo */
    for (grupo = 0; grupo < gruposDe5; grupo++){
        /* 1 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada] << 2) & 0x1C) | ((base16 [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada+1] << 4) & 0x10) | ((base16 [indiceEntrada+2] >> 4) & 0x0F)];
        /* 5 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada+2] << 1) & 0x1E) | ((base16 [indiceEntrada+2] >> 7) & 0x01)];
        /* 6 */    
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+3] >> 2) & 0x1F];
        /* 7 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada+3] << 3) & 0x18 )|( (base16 [indiceEntrada+4] >> 5) & 0x07)];
        /* 8 */
        base32[indiceSaida++] = guia[base16 [indiceEntrada+4] & 0x1F];

        indiceEntrada = indiceEntrada + 5;

    }

    /* se houverem casos restantes, completar com '=' */
    /* sobrou 1 byte - 2 '=' /// 00110000  */
    if (restoBytes == 4){
        /* 1 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada] << 2) & 0x1C) | ((base16 [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada+1] << 4) & 0x10) | ((base16 [indiceEntrada+2] >> 4) & 0x0F)];
        /* 5 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada+2] << 1) & 0x1E) | ((base16 [indiceEntrada+2] >> 7) & 0x01)];
        /* 6 */    
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+3] >> 2) & 0x1F];
        /* 7 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+3] << 3) & 0x18];
        
        base32[indiceSaida++] = '=';
    }

    /* sobrou 2 bytes - 1 '=' /// 00111100 */
    else if (restoBytes == 3){
        /* 1 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada] << 2) & 0x1C) | ((base16 [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada+1] << 4) & 0x10) | ((base16 [indiceEntrada+2] >> 4) & 0x0F)];
        /* 5 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+2] << 1) & 0x1E];
        
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';

    }

    else if (restoBytes == 2){
        /* 1 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        base32[indiceSaida++] = guia[((base16 [indiceEntrada] << 2) & 0x1C) | ((base16 [indiceEntrada+1] >> 6) & 0x03)];
        /* 3 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+1] >> 1) & 0x1F];
        /* 4 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada+1] << 4) & 0x10];
        
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';

    }

    else if (restoBytes == 1){
        /* 1 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada] >> 3) & 0x1F];
        /* 2 */
        base32[indiceSaida++] = guia[(base16 [indiceEntrada] << 2) & 0x1c];
        
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';
        base32[indiceSaida++] = '=';

    }
                                                                                                                                                                                            

    base32[indiceSaida] = '\0';
    return ok;
}

/* -------------------------------------------------  
------------------------------------------------- */

tipoErros DecodificarBase32 (char *base32, tipoAlfabetoBase32 alfabeto, byte *base16, unsigned long long *numeroEmBase16){
    
    /* definindo variaveis */
    char *guiaBase32Simples = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
    char *guiaBase32Estendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";
    char *guiaBase32;
    int len;
    unsigned short numeroPads = 0;

    short auxiliar[8] = {-1,-1,-1,-1,-1,-1,-1,-1}; 
    unsigned short i, a, n = 0, aux;

    /* tipoErros*/
    if (numeroEmBase16 == NULL)
        return numeroDeBytesInvalido;

    if (base32 == NULL)
        return bytesPassadosVazio;

    if (alfabeto != 1 && alfabeto != 0)
        return alfabetoInvalido;
    
    if (strlen(base32) % 8 != 0){
        return foraDaRange;
    }
    /* definindo alfabeto a ser usado */
    if (alfabeto == 1){
        guiaBase32 = guiaBase32Estendido;
    }
    else{
        guiaBase32 = guiaBase32Simples;
    }

    len = strlen(base32);

    /* procurar de 8 em 8 */
    for (i = 0; i < (len-8); i = i + 8){
        
        for (aux = 0; aux < 8; aux++){
            for (a = 0; a < 33; a++){
                if (base32[i+aux] == guiaBase32[a]){
                    auxiliar[aux] = a; /* a = posicao na tabela */
                }
            }
            if (auxiliar[aux] == -1){
                return foraDaRange;
            }
        }
        
        base16[n++] = (auxiliar[0] << 3) | (auxiliar[1] >> 2);
        base16[n++] = (auxiliar[1] << 6 & 0xC0) | (auxiliar[2] << 1) | (auxiliar[3] >> 4);
        base16[n++] = (auxiliar[3] << 4 & 0xF0) | (auxiliar[4] >> 1);
        base16[n++] = (auxiliar[4] << 7 & 0x80) | (auxiliar[5] << 2) | (auxiliar[6] >> 3);
        base16[n++] = (auxiliar[6] << 5 & 0xE0) | (auxiliar[7]);
    
        numeroEmBase16 = numeroEmBase16 + 5;
    }
    

    for (; i < len; i = i + 8){
        /* conferencia de pads */
        for (aux = 0; aux < 8; aux++){
            if (base32[i+aux] != '='){
                for (a = 0; a < 33; a++){
                    if (base32[i+aux] == guiaBase32[a]){
                        auxiliar[aux] = a; /* a = posicao na tabela */
                    }
                }
            }
            else{
                numeroPads++;
            }
        } 
    }

    if (numeroPads == 2 || numeroPads == 5 || numeroPads == 7 || numeroPads == 8){
        return numeroPadsInvalido;
    }

    if (numeroPads == 0){
        base16[n++] = (auxiliar[0] << 3) | (auxiliar[1] >> 2);
        base16[n++] = (auxiliar[1] << 6 & 0xC0) | (auxiliar[2] << 1) | (auxiliar[3] >> 4);
        base16[n++] = (auxiliar[3] << 4 & 0xF0) | (auxiliar[4] >> 1);
        base16[n++] = (auxiliar[4] << 7 & 0x80) | (auxiliar[5] << 2) | (auxiliar[6] >> 3);
        base16[n++] = (auxiliar[6] << 5 & 0xE0) | (auxiliar[7]);
        numeroEmBase16 = numeroEmBase16 + 5;
    }

    if (numeroPads == 1){
        base16[n++] = (auxiliar[0] << 3) | (auxiliar[1] >> 2);
        base16[n++] = (auxiliar[1] << 6 & 0xC0) | (auxiliar[2] << 1) | (auxiliar[3] >> 4);
        base16[n++] = (auxiliar[3] << 4 & 0xF0) | (auxiliar[4] >> 1);
        base16[n++] = (auxiliar[4] << 7 & 0x80) | (auxiliar[5] << 2) | (auxiliar[6] >> 3);
        numeroEmBase16 = numeroEmBase16 + 4;
    }

    else if (numeroPads == 3){
        base16[n++] = (auxiliar[0] << 3) | (auxiliar[1] >> 2);
        base16[n++] = (auxiliar[1] << 6 & 0xC0) | (auxiliar[2] << 1) | (auxiliar[3] >> 4);
        base16[n++] = (auxiliar[3] << 4 & 0xF0) | (auxiliar[4] >> 1);
        numeroEmBase16 = numeroEmBase16 + 3;
    }

    else if (numeroPads == 4){
        base16[n++] = (auxiliar[0] << 3) | (auxiliar[1] >> 2);
        base16[n++] = (auxiliar[1] << 6 & 0xC0) | (auxiliar[2] << 1) | (auxiliar[3] >> 4);
        numeroEmBase16 = numeroEmBase16 + 2;
    }

    else if (numeroPads == 6){
        base16[n++] = (auxiliar[0] << 3) | (auxiliar[1] >> 2);
        numeroEmBase16 = numeroEmBase16 + 1;
    }

    return ok;

}   
/* ------------------------------------------------- 
---------------------------------------------------- 
------------------------------------------------- */

tipoErros CodificarBase64 (byte *base16, unsigned long long numeroDeBytes, tipoFinalLinha finalLinha, char *base64){

    /* definindo variaveis */
    char *guiaBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    unsigned short gruposDe3, restoBytes, grupo, indiceSaida, indiceEntrada, contador;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numeroDeBytesInvalido;

    if (base16 == NULL)
        return bytesPassadosVazio;

    if (finalLinha != 1 && finalLinha != 0)
        return finalLinhaInvalido;

    /* para auxiliar casos */
    gruposDe3 = numeroDeBytes/3; /* grupos de bytes sem sobrar caso */
    restoBytes = numeroDeBytes%3;
    
    indiceSaida = 0;
    indiceEntrada = 0;
    /* andar de 1 em 1 em cada grupo */
    for (grupo = 0; grupo < gruposDe3; grupo++){
        base64[indiceSaida++] = guiaBase64[(base16 [indiceEntrada] >> 2) & 0x3F];

        base64[indiceSaida++] = guiaBase64[((base16 [indiceEntrada] << 4) & 0x30 )|( (base16 [indiceEntrada+1] >> 4) & 0x0F)];

        base64[indiceSaida++] = guiaBase64[((base16 [indiceEntrada+1] << 2) & 0x3C) |( (base16 [indiceEntrada+2] >> 6) & 0x03)];

        base64[indiceSaida++] = guiaBase64[base16 [indiceEntrada+2] & 0x3F];

        indiceEntrada = indiceEntrada + 3;

        if (finalLinha == 1){
            contador = contador + 4;
            if (contador == 76){
                base64[indiceSaida++] = '\r';
                base64[indiceSaida++] = '\n';
                contador = 0;
            }
        }
    }

    /* se houverem casos restantes, completar com '=' */
    /* sobrou 1 byte - 2 '=' /// 00110000  */
    if (restoBytes == 1){
        base64[indiceSaida++] = guiaBase64[(base16 [indiceEntrada] >> 2) & 0x3F];

        base64[indiceSaida++] = guiaBase64[(base16 [indiceEntrada] << 4) & 0x30];
        base64[indiceSaida++] = '=';
        base64[indiceSaida++] = '=';

        if (finalLinha == 1){
            contador = contador + 4;
        }
    }

    /* sobrou 2 bytes - 1 '=' /// 00111100 */
    else if (restoBytes == 2){
        base64[indiceSaida++] = guiaBase64[(base16 [indiceEntrada] >> 2) & 0x3F];
        base64[indiceSaida++] = guiaBase64[((base16 [indiceEntrada] << 4) & 0x30) | ((base16 [indiceEntrada+1] >> 4) & 0x0F)];

        base64[indiceSaida++] = guiaBase64[(base16 [indiceEntrada] << 2) & 0x3C];
        base64[indiceSaida++] = '=';
    
        if (finalLinha == 1){
            contador = contador + 4;
        }
    }

    if (contador != 0 && finalLinha == 1){
        base64[indiceSaida++] = '\r';
        base64[indiceSaida++] = '\n';
    }

    base64[indiceSaida] = '\0';
    return ok;
}   

/* ------------------------------------------------- 
------------------------------------------------- */
tipoErros DecodificarBase64 (char *base64, tipoFinalLinha finalDeLinha, byte *base16, unsigned long long *numeroEmBase16){
    
    /* definindo variaveis */
    char *guiaBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    unsigned short i, a, n = 0;
    int tamanhoBase64 = strlen(base64);
    unsigned short numeroPads = 0, aux;

    short auxiliar[4] = {-1,-1,-1,-1};
    *numeroEmBase16 = 0;
    /* tipoErros*/
    if (numeroEmBase16 == NULL)
        return numeroDeBytesInvalido;

    if (base64 == NULL)
        return bytesPassadosVazio;

    if (finalDeLinha != 1 && finalDeLinha != 0)
        return finalLinhaInvalido;
    
    if (finalDeLinha == 1){
        tamanhoBase64 = tamanhoBase64 - 2;
        base64[tamanhoBase64] = '\0';
    }
    if (strlen(base64) % 4 != 0){
        return foraDaRange;
    }

    /* procurar de 4 em 4 */
    for (i = 0; i < (tamanhoBase64-4); i = i + 4){
        for (aux = 0; aux < 4; aux++){
            for (a = 0; a < 64; a++){
                if (base64[i+aux] == guiaBase64[a]){
                    auxiliar[aux] = a; /* a = posicao na tabela */
                }
            }
            if (auxiliar[aux] == -1){
                return foraDaRange;
            }
        }
    
        base16[n++] = (auxiliar[0] << 2) | (auxiliar[1] >> 4);
        base16[n++] = (auxiliar[1] << 4 & 0xF0) | (auxiliar[2] >> 2);
        base16[n++] = (auxiliar[2] << 6 & 0xC0) | (auxiliar[3]);
        *numeroEmBase16 = *numeroEmBase16 + 3;
    }

    for (; i < tamanhoBase64; i = i + 4){
        /* conferencia de pads */
        for (aux = 0; aux < 4; aux++){
            if (base64[i+aux] != '='){
                for (a = 0; a < 64; a++){
                    if (base64[i+aux] == guiaBase64[a]){
                        auxiliar[aux] = a; /* a = posicao na tabela */
                    }
                }
            }
            else{
                numeroPads++;
            }
        }    
    }

    if (numeroPads == 3 || numeroPads == 4){
        return numeroPadsInvalido;
    }

    if (numeroPads == 0){
        base16[n++] = (auxiliar[0] << 2) | (auxiliar[1]>> 4);
        base16[n++] = (auxiliar[1] << 4 & 0xF0) | (auxiliar[2] >> 2);
        base16[n++] = (auxiliar[2] << 6 & 0xC0) | (auxiliar[3]);
        *numeroEmBase16 = *numeroEmBase16 + 3;
    }

    if (numeroPads == 1){
        base16[n++] = (auxiliar[0] << 2) | (auxiliar[1]>> 4);
        base16[n++] = (auxiliar[1] << 4 & 0xF0) | (auxiliar[2] >> 2);
        *numeroEmBase16 = *numeroEmBase16 + 2;
    }

    else if (numeroPads == 2){
        base16[n++] = (auxiliar[0] << 2) | (auxiliar[1]>> 4);
        *numeroEmBase16 = *numeroEmBase16 + 1;
    }
    return ok;
}   

/* $RCSfile$ */
