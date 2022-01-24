/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: Codigo que calcula ultimo numero do RG e verifica validação

$Author$
$Date$
$Log$ */

/* recebe 8 digitos - tratamento de erro */
/* deve ser printado assim: XX.XXX.XXX-X */
/* return eh o nono digito */

#include "aula0501.h"
#include <stdio.h> /* incluir NULL */

tipoErros
GerarDigitosVerificadoresRg(byte rg[COMPRIMENTO_RG])
{
    /* definir variaveis usadas*/
    unsigned short somaDosProdutos = 0;
    unsigned short peso = 2;
    byte indice;

    /* verificar se rg ta vazio */
    if (rg == NULL)
    {
        return argumentoNulo;
    }

    /* calculo do ultimo digito*/
    for (indice = 0; indice < COMPRIMENTO_RG - 1; indice++)
    {
        /*verifica se fora da range, se letra.. */
        if (rg[indice] > 9 || rg[indice] < 0)
        {
            return digitoInvalido;
        }
        somaDosProdutos = somaDosProdutos + rg[indice] * peso;
        peso++;
    }
    /* passa ultimo digito pra rg[indice]*/
    rg[indice] = 11 - somaDosProdutos % 11;
    return ok;
}

tipoErros
ValidarRg (byte rg[COMPRIMENTO_RG] /* entrada */){    
    /* definir variaveis usadas*/
    byte rg_valido [COMPRIMENTO_RG];
    unsigned short indice;

    /* if (rg == NULL) */
    if (rg == NULL)
    {
        return argumentoNulo;
    }

    /* fazer uma copia com os primeiros 8 digitos */
    for (indice = 0; indice < 8; indice++){
        rg_valido[indice] = rg[indice];
    }

    /* manda envia a copia para calculo do ultimo digito*/
    tipoErros retorno = GerarDigitosVerificadoresRg (rg_valido);

    if (retorno != ok){
        return retorno;
    }

    /* verifica se ultimo digito da original eh igual a digito calculado */
    if (rg_valido[8] != rg[8]){
        return rgInvalido;
    }   
    return ok;
}

/* $RCSfile$ */