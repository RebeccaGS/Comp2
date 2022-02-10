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

#include "aula0504.h"
#include <stdio.h> /* incluir NULL */
#include <string.h>

#define EOS				      					'\0'

tipoErros
GerarDigitosVerificadoresRg(char *entrada , char *saida)
{
    /* definir variaveis usadas*/
    unsigned short somaDosProdutos = 0;
    unsigned short peso = 2;
    byte indice;
        
    /* Verificar se entrada e saidas estao vazios */
    if (entrada == NULL)
    {
        return argumentoNulo;
    }

    if (saida == NULL)
    {
        return argumentoNulo;
    }

    if (strlen(entrada) != COMPRIMENTO_RG+1){
        return tamanhoIncorreto;
    }
        
    if (entrada[2] != '.' || entrada[6] != '.'){
        return formatacaoIncorreta;
    }
        
    /* calculo do ultimo digito*/
    for (indice = 0; indice < COMPRIMENTO_RG + 1; indice++)
    {
        if (indice != 2 && indice != 6){
            /*verifica se fora da range, se letra.. */
            if (entrada[indice] > '9' || entrada[indice] < '0')
            {
                return digitoInvalido;
            }
            somaDosProdutos = somaDosProdutos + (entrada[indice] - '0') * peso;
            peso++;
        }
    }
    /* passa ultimo digito pra saida*/
    *saida = (11 - somaDosProdutos % 11) + '0'; 
    return ok;
}


tipoErros
ValidarRg (char *rg){    
    /* definir variaveis usadas*/
    char rg_valido [COMPRIMENTO_RG+1];
    char saida;
    unsigned short indice;

    /* if (rg == NULL) */
    if (rg == NULL)
    {
        return argumentoNulo;
    }

    /*verifica se fora da range, se letra.. */
    if (rg[8] > '9' || rg[8] < '0')
    {
        return digitoInvalido;
    }
    
    if (rg[2] != '.' || rg[6] != '.' || rg[10] != '-'){
        return formatacaoIncorreta;
    }

    /* fazer uma copia com os primeiros 8 digitos */
    for (indice = 0; indice < 10; indice++){
        rg_valido[indice] = rg[indice];
    }
    rg_valido[10]=EOS;
    /* manda envia a copia para calculo do ultimo digito*/
    tipoErros retorno = GerarDigitosVerificadoresRg (rg_valido,&saida);

    if (retorno != ok){
        return retorno;
    }

    /* verifica se ultimo digito da original eh igual a digito calculado */
    if (rg[11] != saida){
        return rgInvalido;
    }   
    return ok;
}

/* $RCSfile$ */
