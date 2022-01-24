/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: .h das funcoes com definicoes basicas da aula05

$Author$
$Date$
$Log$ */

#ifndef   _AULA0501_
#define   _AULA0501_    "@(#)aula0501.h $Revision$"
 
#define COMPRIMENTO_RG								9

typedef unsigned char byte;

typedef enum {ok = 0, argumentoNulo = 21, digitoInvalido = 22, rgInvalido = 23} tipoErros;

tipoErros
GerarDigitosVerificadoresRg (byte [COMPRIMENTO_RG]);

tipoErros
ValidarRg (byte [ ] /* entrada */);

#endif   

/* $RCSfile$ */

 