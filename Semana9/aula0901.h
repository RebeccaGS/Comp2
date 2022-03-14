#ifndef   _AULA0901_
#define   _AULA0901_   "@(#)aula0901.h $Revision$"

typedef unsigned char byte;

typedef enum {ok = 0, arquivoVazio = 1, falhaCriacaoArquivoTemporario = 2, argumentosEmExcesso = 3} tipoErros;

tipoErros
ExibirConteudoArquivo (char * /* (E) */);

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *, char *);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *, char *);

#endif

