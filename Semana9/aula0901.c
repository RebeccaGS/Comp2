/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: funcs de 09*/


#include <stdio.h>
#include <stdlib.h>
#include "aula0901.h"
#include <string.h>
#include <time.h>


#define  CARRIAGE_RETURN       '\r' /* DOS: \n\r || UNIX: \n */
#define  LINE_FEED             '\n'
#define _WITH_GETLINE
#define  _GNU_SOURCE

#define _XOPEN_SOURCE													500

tipoErros
ExibirConteudoArquivo (char *nomeArquivo){
    
    FILE *leitura;
    char *bytesLidos;
    int tamanhoArquivo, i;

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
    while (!feof(leitura)){ /* anda ate final do arquivo*/  
        getline(&bytesLidos, &tamanhoArquivo, leitura); /* le arq linha a linha */
        printf("%08X | ", bytesLidos[0]);
        for (i = 1; i < 17; i++){
            if (i >= strlen(bytesLidos)){
                printf("   ");
            }
            else{
                printf("%02X ", bytesLidos[i]);
            }
        }
        printf("| ");
        for (i = 0; bytesLidos[i] != '\0'; i++){
            if (bytesLidos[i] < 0x20 || bytesLidos[i] > 0x7F){
                printf(".");
            }
            else{
                printf("%c", bytesLidos[i]);
            }
        }
        printf("\n");
    }    
    
    /* fechar arquivo */
    fclose(leitura);

    return ok;
}


tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, char *convertido){

    FILE *leitura, *escrita;
    char *bytesLidos, *nomeTemporario, *tempo= NULL;
    int tamanhoArquivo;
    short fileTemp = -1, temporario = 0;
    short ano,mes,dia,hora,minuto,segundos;
    /* abre arquivo para leitura e escrita */
    leitura = fopen(original, "rb"); /* rb: le em bytes */
    if (leitura == NULL){
		return arquivoVazio;
	}
    
    if (convertido == NULL){
        /* organizando tempo no nome */
        time_t s;
        struct tm* current_time;
        s = time(NULL);
        current_time = localtime(&s);

        ano = current_time->tm_year + 1900;
        mes = current_time->tm_mon + 1;
        dia = current_time->tm_mday;
        hora = current_time->tm_hour;
        minuto = current_time->tm_min;
        segundos = current_time->tm_sec;

        nomeTemporario = original;
        sprintf(tempo,".backup-%04d%02d%02d_%02d%02d%02d.XXXXXX",ano,mes,dia,hora,minuto,segundos);
        strcat(nomeTemporario,tempo);

        /* criando temporario */
        fileTemp = mkstemp(nomeTemporario);
        escrita = fdopen(fileTemp, "w");

        if (fileTemp<0){
            return falhaCriacaoArquivoTemporario;
        }
        temporario = 1;
	}
    else{
        escrita = fopen(convertido, "a"); 
    }

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
        fputc('\r',escrita);
    }

    if (temporario == 1){
        unlink(nomeTemporario);
    }
    
    fclose(escrita);
    fclose(leitura);    
    return ok;
}


tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, char *convertido){

    FILE *leitura, *escrita;
    char *bytesLidos, *nomeTemporario, *tempo= NULL;
    int tamanhoArquivo;
    short fileTemp = -1, temporario = 0;
    short ano,mes,dia,hora,minuto,segundos;

    /* abre arquivo para leitura e escrita */
    leitura = fopen(original, "rb"); /* rb: le em bytes */
    if (leitura == NULL){
		return arquivoVazio;
	}
    
    if (convertido == NULL){
        /* organizando tempo no nome */
        time_t s;
        struct tm* current_time;
        s = time(NULL);
        current_time = localtime(&s);

        ano = current_time->tm_year + 1900;
        mes = current_time->tm_mon + 1;
        dia = current_time->tm_mday;
        hora = current_time->tm_hour;
        minuto = current_time->tm_min;
        segundos = current_time->tm_sec;

        nomeTemporario = original;
        sprintf(tempo,".backup-%04d%02d%02d_%02d%02d%02d.XXXXXX",ano,mes,dia,hora,minuto,segundos);
        strcat(nomeTemporario,tempo);

        /* criando temporario */
        fileTemp = mkstemp(nomeTemporario);
        escrita = fdopen(fileTemp, "w");

        if (fileTemp<0){
            return falhaCriacaoArquivoTemporario;
        }
        temporario = 1;
	}
    else{
        escrita = fopen(convertido, "a"); 
    }

    /* descobrir tamanho do arquivo */
    fseek(leitura, 0, SEEK_END);          /* ir ate final do arquivo */
    tamanhoArquivo = ftell(leitura);      /* falar quantos bytes foram andados */
    rewind(leitura);                      /* retornar ao inicio do arquivo para le-lo */

    /* alocar memoria */
    bytesLidos = malloc(tamanhoArquivo * sizeof(bytesLidos));

    /* le arquivos em for, se achar um /n, reescreve add um /r */
    while (!feof(leitura)){ /* anda ate final do arquivo*/  
        getline(&bytesLidos, &tamanhoArquivo, leitura); /* le arq linha a linha */
        bytesLidos[strlen(bytesLidos)-1] = '\0';
        fputs(bytesLidos,escrita);
    }

    if (temporario == 1){
        unlink(nomeTemporario);
    }

    fclose(leitura);
    fclose(escrita);
    return ok;
}

/* $RCSfile: aula0901.c,v $ */
