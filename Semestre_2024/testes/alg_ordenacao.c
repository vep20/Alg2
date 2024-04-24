#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

int buscaSequencialRecAux(int vetor[], size_t tam, int valor,
                           int* numComparacoes) { 

    if (tam == 0)
        return -1;
    
    (*numComparacoes)++;

    if (vetor[tam - 1] == valor)
        return tam - 1;

    return buscaSequencialRecAux(vetor,tam - 1, valor, numComparacoes);
}

int buscaSequencialRec(int vetor[], size_t tam, int valor,
                           int* numComparacoes) {
    
    *numComparacoes = 0;
    return buscaSequencialRecAux(vetor,tam, valor, numComparacoes);  
}

int buscaBinaria(int vetor[], size_t tam, int valor,
                        int* numComparacoes) {
    *numComparacoes = 0;
    int a, b, busca;

    a = 0;
    b = tam-1;
    while(a <= b){
        busca = (a + b) / 2;
        (*numComparacoes)++;
        if(valor == vetor[busca])
            return busca;
        else if(valor < vetor[busca])
            b = busca - 1;
        else    
            a = busca + 1;
    }
    return -1;  
}

int buscaBinariaRecAux(int vetor[], int a, int b, int valor,
                        int* numComparacoes) {
    int meio;
    
    if(a > b)
        return -1;
    
    (*numComparacoes)++;
    meio = (a + b) / 2;

    if(valor == vetor[meio])
        return meio;
    else if(valor < vetor[meio])
        return buscaBinariaRecAux(vetor, a, meio - 1, valor, numComparacoes);
    return  buscaBinariaRecAux(vetor, meio + 1, b, valor, numComparacoes);
}

int buscaBinariaRec(int vetor[], int tam, int valor,
                        int* numComparacoes) {

    *numComparacoes = 0;
    return buscaBinariaRecAux(vetor, 0, tam - 1, valor, numComparacoes); 
}

void troca(int v[], int a, int b){
    int aux;

    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

size_t escolheBusca(){
    size_t escolha;

     do{
        printf("Digite 1: busca sequencial interativa\n");
        printf("Digite 2: busca sequencial recursiva\n");
        printf("Digite 3: busca binaria interativa\n");
        printf("Digite 4: busca binaria recursiva\n");
        scanf("%lu", &escolha);
        if(escolha < 1 || escolha > 4)
            printf("Numero invalido\n");
    }while(escolha != 1 || escolha > 4);

    return escolha;
}

// Função que auxilia a troca entre elementos nos indices do insertionSort
void insertion(int vetor[], int inicio, int fim, uint64_t* numComparacoes){
    size_t escolheB, procurado;

    escolheB = escolheBusca();

    switch (escolheB){
        case 1:
            procurado = buscaSequencial(vetor, fim, vetor[fim], numComparacoes);
            break;
        case 2:
            procurado = buscaSequencialRec(vetor, fim, vetor[fim], numComparacoes);
            break;
        case 3:
            procurado = buscaBinaria(vetor, fim, vetor[fim], numComparacoes);
            break;
        case 4:
            procurado = buscaBinariaRec(vetor, fim, vetor[fim], numComparacoes);    
            break;    
    default:
        break;
    }
    for(int i = fim; i > procurado + 1; i--)
        troca(vetor,i,i-1);
}

uint64_t insertionSort(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;

    auxNumComparacoes = 0;
    for(int i = 1; i < tam; i++)
        insertion(vetor, 0, i, &auxNumComparacoes);

    return auxNumComparacoes;
}

// Função auxiliar para que seja possivel calcular o numero de comparações sem iniciar
// a variavel na main
void insertionSortRecAux(int vetor[], int inicio, int fim, uint64_t* numComparacoes){

    if(inicio >= fim)
        return;

    (*numComparacoes)++;    
    
    insertionSortRecAux(vetor, inicio, fim - 1, numComparacoes);
    insertion(vetor, inicio, fim, numComparacoes);  

}

uint64_t insertionSortRec(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;
   
    auxNumComparacoes = 0;
    insertionSortRecAux(vetor, 0, tam - 1, &auxNumComparacoes);
    return auxNumComparacoes;
}


int main(){
    int v[5] = {1,2,3,4,5};

    int x = 3, comp = 0, busca;
    
    busca = buscaBinariaRec(v,5,x,&comp);

    printf("valor esta no indice: %d\n", busca);
    printf("numero de comparações %d\n", comp);

    return 0;
}