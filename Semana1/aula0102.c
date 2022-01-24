
/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simão
Descricao: Exibir nome passado por argumento centralizado

$Author: rebecca.simao $
$Date: 2022/01/03 17:28:13 $
$Log: aula0102.c,v $
Revision 1.2  2022/01/03 17:28:13  rebecca.simao
versao corrigida

Revision 1.1  2022/01/03 15:26:41  rebecca.simao
Initial revision

Revision 1.1  2021/12/10 03:10:35  rebecca.simao
Initial revision
*/


#include <stdio.h>

/*criar funcao principal*/
int main ()
{
    int d;
    /*espaco, 100 hifens e espaco*/
    printf("\n");
    for (d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n\nTamanhos dos Tipos Basicos\n");

    /*Void*/
    printf("%-90s","void:");
    printf("%lu ",sizeof(void));
    char* tamanho = (sizeof(void) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*Char*/
    printf("%-90s","char:");
    printf("%lu ",sizeof(char));
    tamanho = (sizeof(char) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int*/
    printf("%-90s","int:");
    printf("%lu ",sizeof(int));
    tamanho = (sizeof(int) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*float*/
    printf("%-90s","float:");
    printf("%lu ",sizeof(float));
    tamanho = (sizeof(float) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*double*/
    printf("%-90s","double:");
    printf("%lu ",sizeof(double));
    tamanho = (sizeof(double) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*espaco, 100 hifens e espaco*/
    printf("\n");
    for (d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n\nTamanhos dos Modificadores de Sinais\n");

    /*signed*/
    printf("%-90s","signed:");
    printf("%lu ",sizeof(signed));
    tamanho = (sizeof(signed) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*unsigned*/
    printf("%-90s","unsigned:");
    printf("%lu ",sizeof(unsigned));
    tamanho = (sizeof(unsigned) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*espaco, 100 hifens e espaco*/
    printf("\n");
    for (d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n\nTamanhos dos Modificadores de Largura\n");

    /*Short*/
    printf("%-90s","short:");
    printf("%lu ",sizeof(short));
    tamanho = (sizeof(short) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*long*/
    printf("%-90s","long:");
    printf("%lu ",sizeof(long));
    tamanho = (sizeof(long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*long long*/
    printf("%-90s","long long:");
    printf("%lu ",sizeof(long long));
    tamanho = (sizeof(long long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*final*/
    printf("\n");
    for (d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n\n");    
    return 0;
}

/*$RCSfile: aula0102.c,v $*/
