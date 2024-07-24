#include "ordenacao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Victor Eduardo de Paula", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20203937; }

void copiaVetor(int vetor1[], int vetor2[], int inicio, int tamanho){

    for (int i = 0; i < tamanho; i++)
        vetor1[inicio + i] = vetor2[i];
}


int* merge(int vetor[], int inicio, int meio, int fim, uint64_t* numComparacoes) {
    
    if (inicio >= fim) 
        return vetor;
    
    int tamanho = fim - inicio + 1;
    int indice_esquerda = inicio;
    int indice_direita = meio + 1;
    int indice_resultado = 0;

    int* vetor_temporario = malloc(sizeof(int) * tamanho);
    if (vetor_temporario == NULL) {
        printf("Falha fatal. Impossível alocar memória.");
        return NULL;
    }

    while (indice_esquerda <= meio && indice_direita <= fim) {
        (*numComparacoes)++;
        if (vetor[indice_esquerda] <= vetor[indice_direita]) 
            vetor_temporario[indice_resultado++] = vetor[indice_esquerda++]; 
        
        else 
            vetor_temporario[indice_resultado++] = vetor[indice_direita++];
    }

     while (indice_esquerda <= meio) 
        vetor_temporario[indice_resultado++] = vetor[indice_esquerda++];
    

    while (indice_direita <= fim) 
        vetor_temporario[indice_resultado++] = vetor[indice_direita++];

    copiaVetor(vetor, vetor_temporario,inicio,tamanho);

    free(vetor_temporario);
    return vetor;
}

uint64_t mergeSortAux(int vetor[], int inicio, int fim, uint64_t* numComparacoes) {
    if (inicio >= fim) {
        return 0;
    }

    int meio = (inicio + fim) / 2;

    mergeSortAux(vetor, inicio, meio, numComparacoes);
    mergeSortAux(vetor, meio + 1, fim, numComparacoes);

    merge(vetor, inicio, meio, fim, numComparacoes);

    return *numComparacoes;
}

uint64_t mergeSort(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;
    
    auxNumComparacoes = 0;
    mergeSortAux(vetor, 0, tam - 1, &auxNumComparacoes);
    return auxNumComparacoes;
}

/*uint64_t quickSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t heapSort(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t quickSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    vetor[0] = 99;
    return -1;
}*/