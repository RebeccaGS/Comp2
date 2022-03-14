#include <stdio.h>
#include <stdlib.h> /* getopt() */
#include <unistd.h>
#include "aula0901.c"

// ler sobre optind naquele site https://daemoniolabs.wordpress.com/2011/10/07/usando-com-as-funcoes-getopt-e-getopt_long-em-c/
// roteiro: precisa de argumento ou nao afinal?
// testar!!

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
    char *nomeArquivo = NULL, *original = NULL, *convertido = NULL;
    tipoErros retorno;

    /* opcoes struct */
    struct option opcoesLongas[5] = {
        {"dos",  0,  NULL, 'd'|'D'},
        {"help", 0,  NULL, 'h'|'H'},
        {"show", 0,  NULL, 's'|'S'},
        {"unix", 0,  NULL, 'u'|'U'},
        {NULL,   0,  NULL,       0},
    };
    
    /* getopt retorna opcao escolhida ou -1, quando no encerramento do looping */
    while((optind = getopt(argc, argv, "hHd:D:s:S:u:U:", stopcoes, NULL)) > 0 ){
        switch (optind) {

            /* d | D - converter um arquivo texto do formato Unix para o formato Microsoft (DOS). */
            case 'd'|'D':
                retorno = ConverterArquivoFormatoUnixParaFormatoDos (original,convertido);
                
                if (retorno != ok)
                    printf ("Erro executando a funcao. Erro numero %u.\n", retorno);
                break;

            /* h | H - exibir uma mensagem contendo as informações sobre o uso do programa. */    
            case 'h'|'H':
                mostrar_infos();
                break;

            /* s | S - exibir o conteúdo do arquivo. */
            case 's'|'S':
                retorno = ExibirConteudoArquivo (nomeArquivo);
                
                if (retorno != ok)
                    printf ("Erro executando a funcao. Erro numero %u.\n", retorno);
                break;

            /* u | U - converter um arquivo texto do formato Microsoft para o formato Unix. */
            case 'u'|'U':
                retorno = ConverterArquivoFormatoDosParaFormatoUnix (original,convertido);
                
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

    return ok;
}
