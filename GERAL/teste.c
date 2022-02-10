#include <stdio.h>


int roundfloat(float);

int main(){
    printf("%d",roundfloat(1.5));
    printf("%d",roundfloat(1.4));
    printf("%d",roundfloat(1.6));
    return 0;
}


int roundfloat(float numero){  
    int intProx = (int) numero;
    if(numero - intProx < intProx + 1 - numero)
      return intProx;
    else
      return intProx + 1;
}