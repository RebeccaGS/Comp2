/*Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL270 - Computacao II - Turma 2021/2
Prof. Marcelo Luiz Drumond Lanza
Autor: 
Descricao: Exibir nome passado por argumento centralizado
*/


#include <stdio.h>
#include <string.h> /*necessário para strlen*/

/*criar funcao principal*/
int main(int argc,char* argv[])
{     
    /*criar para quando faltar argumentos*/
    if(argc != 2){
        printf ("\nUso: ./aula0101 <nome>\n");
        return -1;
    }
    int numChars = strlen(argv[1]);
    /*informar para quando exceder 50 caracteres*/
    if(numChars>50){
        printf ("Uso: ./aula0101 <nome>");
        return -1;
    }

    
    /*quando tudo certo, printar o nome centralizado*/
    if(argc == 2)
    {
        printf("\n");

        /*repeticao de 10 vezes de numeros de 0 a 7*/
        int a = 0;
        while (a<8){
            int b = 1;
            while (b<11){
                printf("%i", a);
                b++;
            }
            a++;
        }
        printf("\n");

        /*repeticao de 8 vezes de numeros de 0 a 9*/
        int d = 0;
        while (d<8){
            int c = 0;
            while (c<10){
                printf("%i", c);
                c++;
            }
            d++;
        }

        printf("\n");
        printf("\n");

        /*numero de espacos no inicio*/
        int spacesinicial;
        spacesinicial = (80 - numChars - 2)/2;
        int spacesfinal = spacesinicial;
        while (spacesinicial != 0){
            printf (" ");
            spacesinicial--;
        }

        /*printar nome entre aspas*/
        printf ("\"%s\"", argv[1]);

        /*numero de espacos no final*/       
        while (spacesfinal != 0){
            printf (" ");
            spacesfinal--;
        }

        printf("\n");
        printf("\n");

        int e = 0;
        while (e<80){
            printf("-");
            e++;
        }

        printf("\n");
        printf("\n");
    }        
    return 0;
}


/*$RCSfile: aula0101.c,v $*/
