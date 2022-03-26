/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: .h de 09*/

#ifndef   _AULA0901_
#define   _AULA0901_   "@(#)aula0901.h $Revision: 1.3 $"

typedef unsigned char byte;

typedef enum {ok = 0, arquivoVazio = 1, falhaCriacaoArquivoTemporario = 2, argumentosEmExcesso = 3} tipoErros;

tipoErros
ExibirConteudoArquivo (char * /* (E) */);

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *, char *);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *, char *);

#endif

/* $RCSfile: aula0901.h,v $ */