/*
Inclua, no arquivo "aula0701.h", a definição do protótipo da função DesenharReta.
Esta função deverá receber uma matriz de pixels (tipoPixel) correspondendo ao monitor,
suas dimensões reais (numeroMaximoLinhas e numeroMaximoColunas) e os valores (linha e coluna)
correspondentes a dois pontos (as duas extremidadades da reta desejada). Se todos os argumentos
forem válidos, a função deverá "acender" todos os pixels necessários para desenhar a reta 
desejada. A função deverá retornar ok (ZERO) ou o código de erro correspondente (todas as
possíveis condições de erro detectáveis na função).

Caso um pixel necessário para desenhar a reta esteja defeituoso, a função deverá retornar o
código de erro correspondente. Antes de desenhar a reta (marcar os pixels correspondentes à
reta com o valor correspndete a aceso (tipoPixel), verifique todos os pontos necessários).
As retas não serão necessariamente horizontais ou verticais e dada a simplicidade do 
dispositivo, poderão apresentar pequenas imperfeições.

tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS ][ NUMERO_MAXIMO_COLUNAS],
                       unsigned numeroMaximoLinhas,
                       unsigned numeroMaximoColunas,
                       unsigned linhaA,
                       unsigned colunaA,
                       unsigned linhaB,
                       unsigned colunaB);

Inclua, no arquivo "aula0701.c", a implementação da função DesenharReta.

Crie o arquivo "aula0704.c" contendo o o programa de testes para a função DesenharReta. O programa deverá receber,  através dos argumentos de linha de comando, o tempo de congelamento da exibição (us), as dimensões reais do monitor (número de linhas e número de colunas), o percentual de pixels com defeito, o percentual de pixels apagados e os valores correspondentes aos pontos A e B (extremidades da reta). A partir dos percentuais, o programa deverá executar a função GerarDistribuicaoInicial visando preencher a matriz com os dados correspondentes. A seguir deverá executar as funções MostrarMonitor, LimparMonitor, DesenharReta e MostrarMonitor.

./aula0704 <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados> <linha-ponto-1> <coluna-ponto-1> <linha-ponto-2> <coluna-ponto-2>
./aula0704 5 100 200 10 70 30 5 10 70

*/

#include "aula0701.h"
