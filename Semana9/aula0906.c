/* Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor:
descricao: usando long
*/

#include <stdio.h>
#include <stdlib.h> /* getopt() */
#include <unistd.h>
#include "aula0901.c"
#include <getopt.h>

#define _XOPEN_SOURCE													500
#define   ARGUMENTOS_INSUFICIENTES            1
#define   OK                                  0

/* func que contem informacoes para uso do programa */
void mostrar_infos() {
    printf("\
            d | D | --dos - converter um arquivo texto do formato Unix para o formato Microsoft (DOS).\n\
            h | H | --help - exibir uma mensagem contendo as informações sobre o uso do programa.\n\
            s | S | -- show - exibir o conteúdo do arquivo.\n\
            u | U | --unix - converter um arquivo texto do formato Microsoft para o formato Unix.\n");
    exit(-1) ;
} 

int main(int argc, char **argv){

    /* definindo variaveis */
    int optind, i;
    tipoErros retorno;

    /* opcoes struct */
    const struct option long_options[] = {
        {"dos",  0,  NULL, 'd'},
        {"help", 0,  NULL, 'h'},
        {"show", 0,  NULL, 's'},
        {"unix", 0,  NULL, 'u'},
        {NULL,   0,  NULL,       0},
        };
    
    /* getopt_long retorna opcao escolhida ou -1, quando no encerramento do looping */
    while((optind = getopt_long(argc, argv, "hHdDsSuU", long_options, NULL)) > 0 ){
        switch (optind) {

           /* d | D - converter um arquivo texto do formato Unix para o formato Microsoft (DOS). */
            case 'd':
            case 'D':
                if (argv[optind] == NULL){
                    exit(ARGUMENTOS_INSUFICIENTES);
                }
                
                retorno = ConverterArquivoFormatoUnixParaFormatoDos (argv[optind],argv[optind + 1]);
                
                if (retorno != ok)
                    printf ("Erro executando a funcao. Erro numero %u.\n", retorno);
                
                break;

            /* h | H - exibir uma mensagem contendo as informações sobre o uso do programa. */    
            case 'h':
            case 'H':
                mostrar_infos();
                break;

            /* s | S - exibir o conteúdo do arquivo. */
            case 's':
            case 'S':
            
                if (argv[optind] == NULL){
                    exit(ARGUMENTOS_INSUFICIENTES);
                }
                
                retorno = ExibirConteudoArquivo (argv[optind]);
                
                if (retorno != ok)
                    printf ("Erro executando a funcao. Erro numero %u.\n", retorno);
                
                break;

            /* u | U - converter um arquivo texto do formato Microsoft para o formato Unix. */
            case 'u':
            case 'U':
                if (argv[optind] == NULL){
                    exit(ARGUMENTOS_INSUFICIENTES);
                }
                
                retorno = ConverterArquivoFormatoDosParaFormatoUnix (argv[optind],argv[optind + 1]);
                
                if (retorno != ok)
                    printf ("Erro executando a funcao. Erro numero %u.\n", retorno);
                break;
            
            default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: `%c'\n", optind) ;
                return -1 ;
        }
    }

    /* Mostra os argumentos em excesso */
    if (argv[optind] != NULL) {
        printf("Argumentos em excesso: ") ;
        for(i = optind; argv[i] != NULL; i++) {
            printf(" %s\n", argv[i]) ;
        }
        return argumentosEmExcesso;
    }

    return OK;
}

/* $RCSfile: aula0906.c,v $ */

