#include <stdio.h>

int somatorio(unsigned n){
    
    if (n <= 0)
        return n;

    return n + somatorio(n-1);   
}

int main(){
    unsigned int n, soma;

    printf("Digite um numero para o ser somado com seus antecessores: ");
    scanf("%u",&n);
    soma = somatorio(n);
    printf("Somatorio = %u\n", soma);

    return 0;
}