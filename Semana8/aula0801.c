
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

tipoErros CodificarBase16(byte *conjuntoDeBytes, unsigned long long numeroDeBytes, char *saida)
{
    /* definindo variaveis*/
    char *tabelaBase16 = "0123456789ABCDEF";
    unsigned long long i, indiceSaida;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numBytesInvalido;

    if (conjuntoDeBytes == NULL)
        return bytesPassadosVazio;

    /* percorrer de 1 em 1 nos elementos na base 16 */
    indiceSaida = 0;
    for (i = 0; i < numeroDeBytes; i++)
    {
        /* pra caso 1, onde ha necessidade de transicionar a pos em 4 antes de &00001111 */
        saida[indiceSaida++] = tabelaBase16[(conjuntoDeBytes[i] >> 4) & 0x0F];
        
        /* pra caso 2, onde pos ja esta correta, necessitando apenas de &00001111 */
        saida[indiceSaida++] = tabelaBase16[conjuntoDeBytes[i] & 0x0F];
    }

    saida[indiceSaida] = '\0';
    return ok;
}


/* ------------------------------------------------- 
------------------------------------------------- */
tipoErros DecodificarBase16 (char *base16, byte *base10, unsigned long long *numeroEmBase10){
    
    /* definindo variaveis*/
    char *tabelaBase16 = "0123456789ABCDEF";
    unsigned short i;

    /* procurar de 2 em 2 */
    for (i = 0; base16[i] != '\0'; i = i + 2){
        //if (base16[i] != ); // fazer pra se base 16 for diferente de toda tabela base 16
        printf("%c%c \n",base16[i],base16[i+1]);
        numeroEmBase10++;
    }
    printf("%llu",numeroEmBase10); // ta errado
    return ok;
}


/* ------------------------------------------------- 
----------------------------------------------------
------------------------------------------------- */

tipoErros CodificarBase32 (byte *conjuntoDeBytes, unsigned long long numeroDeBytes, tipoAlfabetoBase32 alfabeto, char *saida){
    // 0 - Desabilitado e 1 - Habilitado
    /* definindo variaveis */
    char *Base32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
    char *Base32Estendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";
    unsigned short gruposDe5, restoBytes, grupo, indiceSaida, indiceEntrada, contador;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numeroDeBytesInvalido;

    if (conjuntoDeBytes == NULL)
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

tipoErros DecodificarBase32 (char *codificacaoBase32, tipoAlfabetoBase32 alfabeto, byte *saida, unsigned long long *numeroDeBytes);

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
// Como resolver final de linha
// tipoErros DecodificarBase64 (char *codificacaoBase64, tipoFinalLinha finalLinha, byte *saida, unsigned long long numeroDeBytes){
// /* definindo variaveis */
//     char *Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
//     unsigned short gruposDe4, restoBytes, grupo, indiceSaida, indiceEntrada, contador;

//     /* tipoErros*/
//     if (numeroDeBytes == 0)
//         return numeroDeBytesInvalido;

//     if (codificacaoBase64 == NULL)
//         return bytesPassadosVazio;

//     if (finalLinha != 1 || finalLinha != 0)
//         return finalLinhaInvalido;
        
//     /* para auxiliar casos */
//     gruposDe4 = numeroDeBytes/4; /* grupos de bytes sem sobrar caso */
//     restoBytes = numeroDeBytes%4;
    
//     indiceSaida = 0;
//     indiceEntrada = 0;
//     /* andar de 1 em 1 em cada grupo */
//     for (grupo = 0; grupo < gruposDe4; grupo++){
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada] << 2) & 0xFC) | (codificacaoBase64 [indiceEntrada+1] & 0x03)];
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada+1] << 2) & 0xF0) | (codificacaoBase64 [indiceEntrada+2] & 0x0F)];
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada+2] << 2) & 0xC0) | (codificacaoBase64 [indiceEntrada+3] & 0x0F)];
//     }

//     /* se houverem casos restantes, completar com '=' */
//     if (restoBytes == 1){
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada] << 2) & 0xFC) | (codificacaoBase64 [indiceEntrada+1] & 0x03)];
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada+1] << 2) & 0xF0) | (codificacaoBase64 [indiceEntrada+2] & 0x0F)];
//         saida[indiceSaida++] = Base64[(codificacaoBase64 [indiceEntrada+2] << 2) & 0xC0];
//     }

//     else if (restoBytes == 2){
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada] << 2) & 0xFC) | (codificacaoBase64 [indiceEntrada+1] & 0x03)];
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada+1] << 2) & 0xF0) | (codificacaoBase64 [indiceEntrada+2] & 0x0F)];
    
//         saida[indiceSaida++] = '=';

//     }

//     else if (restoBytes == 1){
//         saida[indiceSaida++] = Base64[((codificacaoBase64 [indiceEntrada] << 2) & 0xFC) | (codificacaoBase64 [indiceEntrada+1] & 0x03)];
            
//         saida[indiceSaida++] = '=';
//         saida[indiceSaida++] = '=';
    
//     }


//     saida[indiceSaida] = '\0';
//     return ok;
// }   

/* $RCSfile$ */