#include <stdio.h>

int compressor(int n1, int n2, int n3){
    int resultado;

    n1 = n1 * 1000000;
    n2 = n2 * 1000;
    resultado = n1 + n2 + n3;
    return resultado; 
}

int main(){
    int x,y,z,n_comprimido;

    printf("Digite 3 numeros inteiros\n");
    scanf("%d %d %d",&x,&y,&z);
    n_comprimido = compressor(x,y,z);
    printf("%d\n", n_comprimido);
}