#include <stdio.h>

void levetor(int v[]){
   for(int i = 0;i < 10; i++)
      scanf("%d",&v[i]);
}

int busca_menor(int v[], int tam){
    int aux = v[tam];
    for(int i = 1; i < tam; i++){
        if (v[i] < aux)
            aux = v[i];
    } 
    return aux;
}

int select_sort(int *v){
    
    for(int i = 0; i < 10; i++){
        int tam = i+1;
        v[i] = busca_menor(v,tam);
    }
    return *v;
}

void imprime_ordenado(int v[]){
    for (int i = 0; i < 10; i++)
        printf("v[%d] = %d ", i, v[i]);
    printf("\n");
}

int main(){
    int v[10];

    levetor(v);
    select_sort(v);
    imprime_ordenado(v);
    return 0;
}