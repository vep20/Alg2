#include <stdio.h>

int somatorio(int n){

    if (n % 10 == 0)
        return n;
    else 
        return n % 10 + somatorio(n/10);
}

int main(){
    int n, soma;

    printf("Digite um numero para ter seus caracteres somados: ");
    scanf("%d",&n);
    soma = somatorio(n);
    printf("Somatorio = %u\n", soma);
    return 0;
}

