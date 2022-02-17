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

#include "aula0801.h"
#include <string.h>
#include <stdio.h>

tipoErros CodificarBase16(byte *conjuntoDeBytes, unsigned long long numeroDeBytes, char *saida)
{
    /* definindo variaveis*/
    char *tabelaBase16 = "0123456789ABCDEF";
    unsigned long long i, indiceSaida;
    byte *auxiliar;

    /* tipoErros*/
    if (numeroDeBytes == 0)
        return numBytesInvalido;

    if (conjuntoDeBytes == NULL)
        return conjuntoDeBytesVazio;

    /* percorrer de 1 em 1 nos elementos na base 16 */
    indiceSaida = 0;
    for (i = 0; i < numeroDeBytes; i++)
    {
        /* pra caso 1, onde ha necessidade de transicionar a pos em 4 antes de &00001111 */
        auxiliar[0] = (conjuntoDeBytes[i] >> 4) & 0x0F;
        saida[indiceSaida] = tabelaBase16[auxiliar[0]];
        indiceSaida++;
        /* pra caso 2, onde pos ja esta correta, necessitando apenas de &00001111 */
        auxiliar[1] = conjuntoDeBytes[i] & 0x0F;
        saida[indiceSaida] = tabelaBase16[auxiliar[1]];
        indiceSaida++;
    }

    return ok;
}

/* $RCSfile$ */