/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: algoritmos de conversao de bytes: 16; 32; 64.

$Author$
$Date$
$Log$ */

// ANOTACOES:
// tipoErros pra fora da range 0-255?
// basico e estendido igual 0 e 1?
// cod 16     /   implementado [CHECK] / TipoErros [CHECK] / FuncTeste [CHECK] / Funcionando [ ]                                                          
// decod 16   /   implementado [CHECK] / TipoErros [CHECK] / FuncTeste [ ] / Funcionando [ ]                                                                          
// cod 32     /   implementado [ ] / TipoErros [ ] / FuncTeste [ ] / Funcionando [ ]                                                                         
// decod 32   /   implementado [ ] / TipoErros [ ] / FuncTeste [ ] / Funcionando [ ]                                                                         
// cod 64     /   implementado [ ] / TipoErros [ ] / FuncTeste [ ] / Funcionando [ ]
// decod 64   /   implementado [ ] / TipoErros [ ] / FuncTeste [ ] / Funcionando [ ]                                                                        
// bsd        /   Funcionando  [ ]                                                                 
// gnu        /   Funcionando  [ ]                                                               


// tipoErros em alfabeto: alfabetoInvalido se diferente de 0 ou 1

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

tipoErros DecodificarBase16 (char *codificacaoBase16, byte *conjuntoDeBytes, unsigned long long *numeroDeBytes){
    
    /* definindo variaveis*/
    char *tabelaBase16 = "0123456789ABCDEF";
    unsigned long long i, indiceSaida;
    unsigned indiceTabelaBase16;
    unsigned long long numeroDeBytesNaString;
    byte *auxiliar;

    numeroDeBytesNaString = 0; /* para descobrir numero de elementos na string*/
    indiceSaida = 0; /* para auxiliar na incrementação de conjuntodebytes decodificados */

    if (codificacaoBase16 == NULL){
        return bytesPassadosVazio;
    }
    /* anda de 1 em 1 na string que contem os numeros na base 16 */
    for (i = 0; codificacaoBase16[i] != '\0'; i = i + 2)
    {
        auxiliar[0] = '/';
        auxiliar[1] = '/';
        
        /* anda indice a indice em tabelaBase16 buscando o elemento igual ao elemento passado na linha de comando*/
        for (indiceTabelaBase16 = 0; indiceTabelaBase16 < 16; indiceTabelaBase16++)
        {
            if (codificacaoBase16[i] == tabelaBase16[indiceTabelaBase16])
            {
                /* achado, define auxiliar como o indice desse elemento (pra converter ja o A pelo 10, por ex) */
                auxiliar[0] = indiceTabelaBase16;
            }
        }

        /* caso nao, elemento fora da range */
        if (auxiliar[0] == '/')
            return foraDaRange;

        for (indiceTabelaBase16 = 0; indiceTabelaBase16 < 16; indiceTabelaBase16++)
        {
            if (codificacaoBase16[i + 1] == tabelaBase16[indiceTabelaBase16])
            {
                auxiliar[1] = indiceTabelaBase16;
            }
        }

        if (auxiliar[1] == '/')
            return foraDaRange;

        conjuntoDeBytes[indiceSaida] = ((auxiliar[0] << 4) & 0xF0) | (auxiliar[1] & 0x0F);
        numeroDeBytesNaString++;
        indiceSaida++;
    }

    *numeroDeBytes = numeroDeBytesNaString;

    return ok;
}


/* ------------------------------------------------- 
----------------------------------------------------
---------------------------------------------------- 
------------------------------------------------- */

tipoErros CodificarBase32 (byte *conjuntoDeBytes, unsigned long long numeroDeBytes, tipoAlfabetoBase32 alfabeto, char *saida){
    // 0 - Desabilitado e 1 - Habilitado
    /* definindo variaveis */
    char Base32 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";
    char Base32Estendido = "0123456789ABCDEFGHIJKLMNOPQRSTUV=";
    unsigned short gruposDe3, restoBytes, grupo, indiceSaida, indiceEntrada, contador;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numeroDeBytesInvalido;

    if (conjuntoDeBytes == NULL)
        return bytesPassadosVazio;

    
    /* para auxiliar casos */
    gruposDe3 = numeroDeBytes/3; /* grupos de bytes sem sobrar caso */
    restoBytes = numeroDeBytes%3;
    
    indiceSaida = 0;
    indiceEntrada = 0;
    /* andar de 1 em 1 em cada grupo */
    for (grupo = 0; grupo < gruposDe3; grupo++){
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] >> 2) & 0x3F];

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 4) & 0x30 | (conjuntoDeBytes [indiceEntrada+1] >> 4) & 0x0F];

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada+1] << 2) & 0x3C | (conjuntoDeBytes [indiceEntrada+2] >> 6) & 0x03];

        saida[indiceSaida++] = Base64[conjuntoDeBytes [indiceEntrada+2] & 0x3F];

        indiceEntrada = indiceEntrada + 3;

    }

    /* se houverem casos restantes, completar com '=' */
    /* sobrou 1 byte - 2 '=' /// 00110000  */
    if (restoBytes == 1){
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] >> 2) & 0x3F];

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 4) & 0x30];
        saida[indiceSaida++] = '=';
        saida[indiceSaida++] = '=';

    }

    /* sobrou 2 bytes - 1 '=' /// 00111100 */
    else if (restoBytes == 2){
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] >> 2) & 0x3F];
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 4) & 0x30 | (conjuntoDeBytes [indiceEntrada+1] >> 4) & 0x0F];

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 2) & 0x3C];
        saida[indiceSaida++] = '=';

    }

    saida[indiceSaida] = '\0';
    return ok;
}

/* ------------------------------------------------- 
----------------------------------------------------
---------------------------------------------------- 
------------------------------------------------- */

tipoErros CodificarBase64 (byte *conjuntoDeBytes, unsigned long long numeroDeBytes, tipoFinalLinha finalLinha, char *saida){
    // 0 - Desabilitado e 1 - Habilitado
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

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 4) & 0x30 | (conjuntoDeBytes [indiceEntrada+1] >> 4) & 0x0F];

        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada+1] << 2) & 0x3C | (conjuntoDeBytes [indiceEntrada+2] >> 6) & 0x03];

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
        saida[indiceSaida++] = Base64[(conjuntoDeBytes [indiceEntrada] << 4) & 0x30 | (conjuntoDeBytes [indiceEntrada+1] >> 4) & 0x0F];

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

/* $RCSfile$ */