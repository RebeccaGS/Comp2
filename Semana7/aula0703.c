/*
Inclua, no arquivo "aula0701.h", a definição do protótipo da função LimparMonitor. Esta função deverá receber uma
matriz de pixels (tipoPixel) correspondendo ao monitor e suas dimensões reais (numeroMaximoLinhas e numeroMaximoColunas). Se todos os argumentos forem válidos, a função deverá "apagar" todos os pixels do dispositivo (na matriz
correspondente). Não deverão ser apagados os pixels marcados como defeituosos. A função deverá retornar ok (ZERO) ou
o código de erro correspondente (todas as possíveis condições de erro detectáveis na função).

Crie o arquivo "aula0703.c" contendo o o programa de testes para a função LimparMonitor. O programa deverá receber,  
através dos argumentos de linha de comando, o tempo de congelamento da exibição, as dimensões reais do monitor 
(número de linhas e número de colunas, o percentual de pixels com defeito e o percentual de pixels apagados. 
A partir destes percentuais, o programa deverá executar a função GerarDistribuicaoInicial visando preencher a 
matriz com os dados correspondentes. A seguir deverá executar as funções MostrarMonitor, LimparMonitor e 
MostrarMonitor novamente.

*/

#include "aula0701.h"
