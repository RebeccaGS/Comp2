/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: Rebecca Gomes Simão
Descricao: Exibir nome passado por argumento centralizado

$Author: rebecca.simao $
$Date: 2022/01/03 17:34:15 $
$Log: aula0103.c,v $
Revision 1.1  2022/01/03 17:34:15  rebecca.simao
Initial revision

Revision 1.1  2021/12/10 05:15:50  rebecca.simao
Initial revision
*/




#include <stdio.h>

/*criar funcao principal*/
int main ()
{
    int d;
    /*espaco, 100 hifens, espaco e Tamanhos dos Modificadores de Sinal combinados com Modificadores de Largura*/
    printf("\n");
    for (    d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n");
    printf("\n");
    printf("Tamanhos dos Modificadores de Sinal combinados com Modificadores de Largura");
    printf("\n");

    /*signed com short e propriedades*/
    printf("%-90s","Signed combinado com Short:");
    printf("%lu ",sizeof(signed short));
    char* tamanho = (sizeof(signed short) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*signed com long e propriedades*/
    printf("%-90s","Signed combinado com Long:");
    printf("%lu ",sizeof(signed long));
    tamanho = (sizeof(signed long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*signed com long long e propriedades*/
    printf("%-90s","Signed combinado com Long long:");
    printf("%lu ",sizeof(signed long long));
    tamanho = (sizeof(signed long long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*unsigned com short e propriedades*/
    printf("%-90s","Unsigned combinado com Short:");
    printf("%lu ",sizeof(unsigned short));
    tamanho = (sizeof(unsigned short) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*unsigned com long e propriedades*/
    printf("%-90s","Unsigned combinado com Long:");
    printf("%lu ",sizeof(unsigned long));
    tamanho = (sizeof(unsigned long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*unsigned com long long e propriedades*/
    printf("%-90s","Unsigned combinado com Long long:");
    printf("%lu ",sizeof(unsigned long));
    tamanho = (sizeof(unsigned long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");



    /*espaco, 100 hifens, espaco e Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal*/
    printf("\n");
    for ( d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n");
    printf("\n");
    printf("Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal");
    printf("\n");

    /*Signed com char e propriedades*/
    printf("%-90s","Signed combinado com Char:");
    printf("%lu ",sizeof(signed char));
    tamanho = (sizeof(signed char) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*Signed com int e propriedades*/
    printf("%-90s","Signed combinado com Int:");
    printf("%lu ",sizeof(signed int));
    tamanho = (sizeof(signed int) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*Unsigned com char e propriedades*/
    printf("%-90s","Unsigned combinado com Char:");
    printf("%lu ",sizeof(unsigned char));
    tamanho = (sizeof(unsigned char) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*Unsigned com int e propriedades*/
    printf("%-90s","Unsigned combinado com Int:");
    printf("%lu ",sizeof(unsigned int));
    tamanho = (sizeof(unsigned int) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");



    /*espaco, 100 hifens, espaco e Tamanhos dos Tipos Basicos combinados com Modificadores de Largura*/
    printf("\n");
    for (d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n");
    printf("\n");
    printf("Tamanhos dos Tipos Basicos combinados com Modificadores de Largura");
    printf("\n");

    /*int com short e propriedades*/
    printf("%-90s","Int combinado com Short:");
    printf("%lu ",sizeof(int short));
    tamanho = (sizeof(int short) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int com long e propriedades*/
    printf("%-90s","Int combinado com long:");
    printf("%lu ",sizeof(int long));
    tamanho = (sizeof(int long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int com long long e propriedades*/
    printf("%-90s","Int combinado com long long:");
    printf("%lu ",sizeof(int long long));
    tamanho = (sizeof(int long long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*double com long e propriedades*/
    printf("%-90s","Double combinado com long:");
    printf("%lu ",sizeof(double long));
    tamanho = (sizeof(double long) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");


    /*espaco, 100 hifens, espaco e Tamanhos dos Tipos Basicos combiandos com Modificadores de Sinal e com Modificadores de Largura*/
    printf("\n");
    for (d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n");
    printf("\n");
    printf("Tamanhos dos Tipos Basicos combiandos com Modificadores de Sinal e com Modificadores de Largura");
    printf("\n");

    /*int com short com signed e propriedades*/
    printf("%-90s","Int combinado com short e signed:");
    printf("%lu ",sizeof(int short signed));
    tamanho = (sizeof(int short signed) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int com long com signed e propriedades*/
    printf("%-90s","Int combinado com long e signed:");
    printf("%lu ",sizeof(int long signed));
    tamanho = (sizeof(int long signed) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int com long long com signed e propriedades*/
    printf("%-90s","Int combinado com long long e signed:");
    printf("%lu ",sizeof(int long long signed));
    tamanho = (sizeof(int long long signed) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int com short com unsigned e propriedades*/
    printf("%-90s","Int combinado com short e unsigned:");
    printf("%lu ",sizeof(int short unsigned));
    tamanho = (sizeof(int short unsigned) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int com long com unsigned e propriedades*/
    printf("%-90s","Int combinado com long e unsigned:");
    printf("%lu ",sizeof(int long unsigned));
    tamanho = (sizeof(int long unsigned) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*int com long long com unsigned e propriedades*/
    printf("%-90s","Int combinado com long long e unsigned:");
    printf("%lu ",sizeof(int long long signed));
    tamanho = (sizeof(int long long unsigned) != 1) ? "bytes": "byte";
    printf("%s",tamanho);
    printf("\n");

    /*final*/
    printf("\n");
    for (d = 0; d < 100; d++)
        {         
            printf("-");       
        }
    printf("\n");
    printf("\n");
    
    return 0;
}

/*$RCSfile: aula0103.c,v $*/

