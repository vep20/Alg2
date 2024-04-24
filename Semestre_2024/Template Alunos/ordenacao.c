#include "ordenacao.h"
#include <stdio.h>
#include <string.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Victor Eduardo de Paula", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20203937; }

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes) {
    *numComparacoes = 0;

    for(size_t i = 0; i < tam; i++){
        //incrementa o valor de numero de comparações
        (*numComparacoes)++; 
        if(vetor[i] == valor)
            return i;
    }
    return -1;
}

// Função auxiliar para que seja possivel calcular o numero de comparações sem iniciar
// a variavel na main
ssize_t buscaSequencialRecAux(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes){ 

    if(tam == 0)
        return -1;
    
    (*numComparacoes)++;

    if(vetor[tam - 1] == valor)
        return tam - 1;

    return buscaSequencialRecAux(vetor,tam - 1, valor, numComparacoes);
}

ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes){
    
    *numComparacoes = 0;
    return buscaSequencialRecAux(vetor, tam, valor, numComparacoes);  
} 

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes){
    *numComparacoes = 0;
    int inicio, fim, busca;

    inicio = 0;
    fim = tam-1;

    while(inicio <= fim){
        busca = (inicio + fim) / 2;
        (*numComparacoes)++;

        if(valor == vetor[busca])
            return busca;
        else if(valor < vetor[busca])
            fim = busca - 1;
        else    
            inicio = busca + 1;

    }
    return -1;  
}

// Função auxiliar para que seja possivel calcular o numero de comparações sem iniciar
// a variavel na main
ssize_t buscaBinariaRecAux(int vetor[], int inicio, int fim, int valor,
                            uint64_t* numComparacoes){
    int meio;
        
    if(inicio > fim)
        return -1;
        
    (*numComparacoes)++;
    meio = (inicio + fim) / 2;

    if(valor == vetor[meio])
        return meio;
    else if(valor < vetor[meio])
        return buscaBinariaRecAux(vetor, inicio, meio - 1, valor, numComparacoes);
    return buscaBinariaRecAux(vetor, meio + 1, fim, valor, numComparacoes);
}

ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                            uint64_t* numComparacoes){

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
    }while(escolha < 1 || escolha > 4);

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
uint64_t insertionSortRecAux(int vetor[], int inicio, int fim, uint64_t* numComparacoes){

    if(inicio >= fim)
        return 0;

    (*numComparacoes)++;    
    
    insertionSortRecAux(vetor, inicio, fim - 1, numComparacoes);
    insertion(vetor, inicio, fim, numComparacoes);

    return *numComparacoes;  
}

uint64_t insertionSortRec(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;
   
    auxNumComparacoes = 0;
    insertionSortRecAux(vetor, 0, tam - 1, &auxNumComparacoes);
    return auxNumComparacoes;
}

uint64_t selectionSort(int vetor[], size_t tam){
    vetor[0] = 99;
    return -1;
}

uint64_t selectionSortRec(int vetor[], size_t tam){
    vetor[0] = 99;
    return -1;
}

uint64_t mergeSort(int vetor[], size_t tam){
    vetor[0] = 99;
    return -1;
}