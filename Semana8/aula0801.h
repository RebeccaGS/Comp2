/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simao
Descricao: prototipo das funcoes e definicoes do roteiro 08

$Author$
$Date$
$Log$ */

#ifndef   _AULA08_
#define   _AULA08_    ""@(#)aula08.h $Revision$""

typedef unsigned char byte;

typedef enum {ok = 0, numeroDeBytesInvalido = 1, bytesPassadosVazio = 2, foraDaRange = 3,
                            caracterInvalido = 4, finalLinhaInvalido = 5} tipoErros;
typedef enum {basico = 0, estendido = 1} tipoAlfabetoBase32;
typedef enum {desabilitado = 0, habilitado = 1} tipoFinalLinha;


tipoErros
CodificarBase16 (byte *, unsigned long long, char *);

tipoErros
DecodificarBase16 (char *, byte * , unsigned long long *);

tipoErros
CodificarBase32 (byte *, unsigned long long , tipoAlfabetoBase32, char *);

tipoErros
DecodificarBase32 (char *, tipoAlfabetoBase32, byte *, unsigned long long *);

tipoErros
CodificarBase64 (byte *, unsigned long long, tipoFinalLinha, char *);

tipoErros
DecodificarBase64 (char *, tipoFinalLinha , byte *, unsigned long long *);

#endif
/* $RCSfile$ */
