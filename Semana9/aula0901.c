// fread -> leitura de arquivo qualquer
// fwrite -> escrita de arquivo qualquer

// fgets -> leitura de arquivo texto - vetor onde guardar oq leu (char*)
// fprintf -> escrita de arquivo texto

// tem o txt em fopen?

// FALTAM
// 01 -> tipoErros // Print correto // erro em testes
// 02 ->
// 03 -> 

#include <stdio.h>
#include <stdlib.h>
#include "aula0901.h"

#define  CARRIAGE_RETURN       '\r' /* DOS: \n\r || UNIX: \n */
#define  LINE_FEED             '\n'
 
tipoErros
ExibirConteudoArquivo (char *nomeArquivo){
    
    FILE *leitura;
    char *bytesLidos;
    int tamanhoArquivo;

    /* abre arquivo para leitura */
    leitura = fopen(nomeArquivo, "rb"); /* rb: le em bytes */
    if (leitura == NULL){
		return arquivoVazio;
	}

    /* descobrir tamanho do arquivo */
    fseek(leitura, 0, SEEK_END);          /* ir ate final do arquivo */
    tamanhoArquivo = ftell(leitura);      /* falar quantos bytes foram andados */
    rewind(leitura);                      /* retornar ao inicio do arquivo para le-lo */

    /* alocar memoria */
    bytesLidos = malloc(tamanhoArquivo * sizeof(bytesLidos));

    /* ler arquivo */
    fread(bytesLidos, tamanhoArquivo, 1, leitura); 
  
    /* imprime arquivo */
    printf("%s \n", bytesLidos);

    /* fechar arquivo */
    fclose(leitura);

    return ok;
}

// documentacao: https://phoenixnap.com/kb/convert-dos-to-unix
// formato dos tem /n/r formato unix tem /n 
tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, char *convertido){

    FILE *leitura, *escrita;
    char *bytesLidos;
    int tamanhoArquivo;

    /* abre arquivo para leitura e escrita */
    leitura = fopen(original, "rb"); /* rb: le em bytes */
    if (leitura == NULL){
		return arquivoVazio;
	}

    escrita = fopen(convertido, "a");  
    // if (escrita == NULL){             
	// 	return arquivoVazio;
	// }

    /* descobrir tamanho do arquivo */
    fseek(leitura, 0, SEEK_END);          /* ir ate final do arquivo */
    tamanhoArquivo = ftell(leitura);      /* falar quantos bytes foram andados */
    rewind(leitura);                      /* retornar ao inicio do arquivo para le-lo */

    /* alocar memoria */
    bytesLidos = malloc(tamanhoArquivo * sizeof(bytesLidos));

    /* le arquivos em for, se achar um /n, reescreve add um /r */
    while (!feof(leitura)){ /* anda ate final do arquivo*/  
        getline(&bytesLidos, &tamanhoArquivo, leitura); /* le arq linha a linha */
        fputs(bytesLidos,escrita);
        //fwrite(bytesLidos, 1, sizeof(bytesLidos), escrita); // sizeof... ou tamanhoArquivo?
        // le arquivo linha a linha SEMPRE parando no \n ou final de arquivo ou..?
        fputc('\r',escrita);
    }

    fclose(leitura);
    fclose(escrita);
    return ok;
}


tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, char *convertido);
    //     /* le arquivos em for, se achar um /r, reescreve retirando ele */


