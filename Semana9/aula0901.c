// #include <stdio.h>
// #ifdef __linux__
// #include <stdio_ext.h>
// #endif
// #include <stdlib.h>
// #include <string.h>
// #include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aula0901.h"

#define ERRO_ABRINDO_ARQUIVO                    1


tipoErros
ExibirConteudoArquivo (char *nomeArquivo){
    /* declarar variaveis */
    FILE *leitura;
    char numeroBytesLidos;
    bytes *guardaLeitura;
    
    /* abrir o arquivo e verificar se NULL*/
    if ((leitura = fopen(nomeArquivo, "r")) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo: \"%s\"\n", nomeArquivo);
        printf("Erro #%i ", errno);
        printf("- %s\n",strerror(errno));
        return erroAbrirNomeArquivo;
    }
		
	while (fread(linhaAtual, TAMANHO_MAXIMO_LINHA, arquivo)) {
	
		indiceCaractereLinhaAtual = 0;

		do {
			caractereAtual = linhaAtual[indiceCaractereLinhaAtual];
			conteudoArquivo[indiceCaractereAtual] = caractereAtual;

			indiceCaractereLinhaAtual++;
			indiceCaractereAtual++;
		} while (linhaAtual[indiceCaractereLinhaAtual] != ENTER);
	}

	conteudoArquivo[indiceCaractereAtual] = '\0';
    
    return ok;

}

    // //-------------------------------------------------
    // {
    // /* ler o arquivo ja printando linha a linha */
    // do {
    //     numeroBytesLidos = fread(guardaLeitura,leitura,"r");
    //     printf("%c", lendo);
 
    // } while (lendo != EOF);
 
    // /* fechar o arquivo*/
    // fclose(arquivoRequisitado);
    //     FILE *leitura, *escrita;
    //     char nome[COMPRIMENTO_MAXIMO_NOME + 2]; /* +2: \:n + \0 -> + 3: \r + \n + \0 */
    //     unsigned numeroLinhas = 0;

    //     if (argc != NUMERO_ARGUMENTOS)
    //     {
    //         printf("Uso: %s <nome-arquivo-origem> <nome-arquivo-destino\n", argv[0]);
    //         exit(NUMERO_ARGUMENTOS_INVALIDO);
    //     }

    //     /*
    //     leitura = fopen (argv [1], "r");
    //     if (leitura == NULL)
    //     */
    //     if ((leitura = fopen(argv[1], "r")) == NULL)
    //     {
    //         printf("Nao foi possivel abrir o arquivo: \"%s\"\n", argv[1]);
    //         printf("Erro #%i - %s\n", errno, strerror(errno));
    //         exit(ERRO_ABRINDO_ARQUIVO);
    //     }

    //     if ((escrita = fopen(argv[2], "w")) == NULL)
    //     {
    //         printf("Nao foi possivel abrir o arquivo: \"%s\"\n", argv[2]);
    //         printf("Erro #%i - %s\n", errno, strerror(errno));
    //         fclose(leitura);
    //         exit(ERRO_ABRINDO_ARQUIVO);
    //     }

    //     while (fgets(nome, COMPRIMENTO_MAXIMO_NOME + 2, leitura) != NULL)
    //     {
    //         fprintf(escrita, "%s", nome);
    //         numeroLinhas++;
    //     }

//         if (ferror(leitura))
//         {
//             printf("Erro lendo o conteudo do arquivo origem.\n");
//             printf("Erro #%i - %s\n", errno, strerror(errno));
//             fclose(leitura);
//             fclose(escrita);
//             remove(argv[2]);
//             exit(ERRO_LENDO_ARQUIVO);
//         }

//         fclose(leitura);
//         fclose(escrita);

//         printf("\n\nArquivo copiado com sucesso. %u linhas copias.\n\n", numeroLinhas);
//         return OK;
//     }

//     //-------------------------------------------------

//     return ok;
// }



#define _XOPEN_SOURCE_			600

#include <stdio.h>
#include <stdlib.h>

#include "aula08.h"

#define TAMANHO_MAXIMO_LINHA		4000
#define QUANTIDADE_LINHAS		1000

#define QUANTIDADE_BYTES_LINHA		80

#define ENTER				'\n'
#define EOS				'\0'

tipoErros ExibirConteudoArquivo (char *original) {
	
	FILE *arquivo;

	unsigned indice, indiceConteudo;

	unsigned indiceCaractereAtual = 0;

	unsigned indiceCaractereLinhaAtual;

	char caractereAtual;

	char linhaAtual[TAMANHO_MAXIMO_LINHA];
	
	char conteudoArquivo[TAMANHO_MAXIMO_LINHA * QUANTIDADE_LINHAS];

	unsigned comeco, fim, faltaEspaco;

	printf ("\n\n");

	if (!original) {
		return originalNulo;
	}

	/* Tentando abrir o arquivo */
	if (!(arquivo = fopen (original, "r"))) {
		return erroAbrirArquivoOriginal;
	}
	
	
	while (fgets(linhaAtual, TAMANHO_MAXIMO_LINHA, arquivo)) {
	
		indiceCaractereLinhaAtual = 0;

		do {
			caractereAtual = linhaAtual[indiceCaractereLinhaAtual];
			conteudoArquivo[indiceCaractereAtual] = caractereAtual;

			indiceCaractereLinhaAtual++;
			indiceCaractereAtual++;
		} while (linhaAtual[indiceCaractereLinhaAtual] != ENTER);
	}

	conteudoArquivo[indiceCaractereAtual] = EOS;

	comeco = 0;

	for (indiceConteudo = 0; conteudoArquivo[indiceConteudo] != EOS; indiceConteudo++){
		
		fim = indiceConteudo;
	
		if ((indiceConteudo + 1) % 80 == 0  || conteudoArquivo[indiceConteudo + 1] == EOS) {
			faltaEspaco = 0;
			printf ("%012X-%012X | ", comeco, fim);

			for (indice = comeco; indice < fim+1; indice++) {
				printf ("%02X ", conteudoArquivo[indice]);
				faltaEspaco++;
			}

			while (faltaEspaco % 80 != 0) {
				printf ("   ");
				faltaEspaco++;
			}

			printf ("| ");

			for (indice = comeco; indice < fim+1; indice++) {
				if (conteudoArquivo[indice] <= 0x20 || conteudoArquivo[indice] >= 0X7F) {
					printf (".");
				} else {
					printf ("%c", conteudoArquivo[indice]);
				}
			}

			comeco = fim + 1;

			printf ("\n");
		}
	}

	printf ("\n\n");


	fclose (arquivo);

	return ok;
}
