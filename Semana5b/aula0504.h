/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: .h das funcoes com definicoes basicas da aula05 string*/


#ifndef   _AULA0504_
#define   _AULA0504_    "@(#)aula0504.h $Revision: 1.1 $"

#define COMPRIMENTO_RG								9

typedef unsigned char byte;

typedef enum {ok = 0, argumentoNulo = 21, digitoInvalido = 22, rgInvalido = 23, formatacaoIncorreta = 24, tamanhoIncorreto = 25} tipoErros;

tipoErros
GerarDigitosVerificadoresRg (char * /* entrada */ , char * /* saida - DV */);

tipoErros
ValidarRg (char *);

#endif   

/* $RCSfile: aula0504.h,v $ */
