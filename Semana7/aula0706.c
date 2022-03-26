/*
Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
Descricao: testes para preencher poligono
*/

#ifdef __linux__
#define _XOPEN_SOURCE  500
#endif


#include "aula0701.h"
#include <stdlib.h>
#include <unistd.h> /* useconds_t */
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <float.h>

#define OK										0
#define NUMERO_ARGUMENTOS_INVALIDO              1
#define BASE_INVALIDA                           2
#define VALOR_MAXIMO_EXCEDIDO                   3
#define CONTEM_CARACTERE_INVALIDO               4
#define ERRO_CHAMADA_FUNCAO                     5

#define EOS				      					'\0'

int main (int argc, char **argv) {

    /* definir variaveis usadas */
    useconds_t tempoEspera;
    tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
    unsigned numeroMaximoLinhas;
    unsigned numeroMaximoColunas;
    float percentualDefeituosos;
    float percentualApagados;
    unsigned short i = 1, a; /* indice dos for */
    char *verificacao;
    unsigned linha, coluna;
    unsigned numeroVertices, linhasVertices [NUMERO_MAXIMO_LINHAS], colunasVertices [NUMERO_MAXIMO_COLUNAS];


    /* se possui os iniciais args */
    if (argc < 11){
        printf("%s", "<tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <linha-ponto> <coluna-ponto> <numero                    -vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . <linha-vertice-N> <coluna-vertice-N>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* pegar argumentos a serem usados */
    tempoEspera = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("tempo de espera invalido.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para tempo de espera ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Tempo de espera contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    numeroMaximoLinhas = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Numero maximo de linhas invalido.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para numero maximo de linhas ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Numero maximo de linhas contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }


    numeroMaximoColunas = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Numero maximo de colunas invalido.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para numero maximo de colunas ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Numero maximo de colunas contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }

    if(sscanf(argv[i], "%f", &percentualDefeituosos) == 0){
        printf ("Percentual de defeituosos contem caractere invalido.\n");
        printf ("Input invalido: \'%s\'\n", argv[i]);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    i++;
    
    if (errno == ERANGE){
  		printf ("Valor fornecido para percentual de defeituosos ultrapassa o valor maximo permitido para unsigned short (%f)\n",FLT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    

    if(sscanf(argv[i], "%f", &percentualApagados) == 0){
        printf ("Percentual de apagados contem caractere invalido.\n");
        printf ("Input invalido: \'%s\'\n", argv[i]);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    i++;
    
    if (errno == ERANGE){
  	  	printf ("Valor fornecido para percentual de apagados ultrapassa o valor maximo permitido para unsigned short (%f)\n",FLT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}

    
    linha = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Linha invalida.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para linha ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Linha contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    
    coluna = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Coluna invalida.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para coluna ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("coluna contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    
    numeroVertices = strtoul(argv[i++], &verificacao, 10);
    if (errno == EINVAL){
  		printf ("Numero vertices invalido.\n");
        exit (BASE_INVALIDA);
    }
    if (errno == ERANGE){
  		printf ("Valor fornecido para numero de vertices ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
        exit (VALOR_MAXIMO_EXCEDIDO);
  	}
    
    if (*verificacao != EOS){
        printf ("Numero maximo de vertices contem caractere invalido.\n");
        printf ("Caractere invalido: \'%c\'\n", *verificacao);
        exit (CONTEM_CARACTERE_INVALIDO);
    }
    
    for(a = 0; a < numeroVertices; a++){
        linhasVertices[a] = strtoul(argv[i++], &verificacao, 10);
        if (errno == EINVAL){
            printf ("Quantidade de linhas dos vertices invalidas.\n");
            exit (BASE_INVALIDA);
        }
        if (errno == ERANGE){
            printf ("Valor fornecido para quantidade de linhas dos vertices ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
            exit (VALOR_MAXIMO_EXCEDIDO);
        }
        if (*verificacao != EOS){
            printf ("Quantidade de linhas dos vertices contem caractere invalido.\n");
            printf ("Caractere invalido: \'%c\'\n", *verificacao);
            exit (CONTEM_CARACTERE_INVALIDO); 
        }
        colunasVertices[a] = strtoul(argv[i++], &verificacao, 10);
        if (errno == EINVAL){
            printf ("Quantidade de colunas dos vertices invalidas.\n");
            exit (BASE_INVALIDA);
        }
        if (errno == ERANGE){
            printf ("Valor fornecido para quantidade de colunas dos vertices ultrapassa o valor maximo permitido para unsigned short (%d)\n",UINT_MAX);
            exit (VALOR_MAXIMO_EXCEDIDO);
        }
        if (*verificacao != EOS){
            printf ("Quantidade de linhas dos colunas contem caractere invalido.\n");
            printf ("Caractere invalido: \'%c\'\n", *verificacao);
            exit (CONTEM_CARACTERE_INVALIDO); 
        }     
    }
    
    
    /* se possui os args */
    if (argc != 9 + 2*numeroVertices){
        printf("%s", "<tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <numero-vertices> <linha-vertice-1>                       <coluna-vertice-1><linha-vertice-N><coluna-vertice-N>\n");
        exit (NUMERO_ARGUMENTOS_INVALIDO);
    }

    /* enviar argumentos */
    tipoErros retorno = GerarDistribuicaoInicial(monitor,numeroMaximoLinhas, numeroMaximoColunas,percentualDefeituosos, percentualApagados);
    if (retorno != ok){
        printf ("Erro executando a funcao GerarDistribuicaoInicial. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    retorno = LimparMonitor(monitor,numeroMaximoLinhas, numeroMaximoColunas);
    if (retorno != ok){
        printf ("Erro executando a funcao LimparMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
        }  
    
    retorno = DesenharPoligono (monitor, numeroMaximoLinhas,numeroMaximoColunas,numeroVertices,linhasVertices,colunasVertices);
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }
    
    retorno = PreencherPoligono (tempoEspera,monitor,numeroMaximoLinhas,numeroMaximoColunas,linha,coluna);
    if (retorno != ok){
        printf ("Erro executando a funcao PreencherPoligono. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }                

    retorno = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
    if (retorno != ok){
        printf ("Erro executando a funcao MostrarMonitor. Erro numero %u.\n", retorno);
        exit(ERRO_CHAMADA_FUNCAO);
    }

    return OK;
}

/* $RCSfile: aula0706.c,v $ */

