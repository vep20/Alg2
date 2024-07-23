#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
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

uint64_t insertionSort(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;
    int chave, j;

    auxNumComparacoes = 0;
    for(int i = 1; i < tam; i++){
        chave = vetor[i];
        j = i - 1;
        auxNumComparacoes++;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }

    return auxNumComparacoes;
}

void troca(int vetor[], int posicao1, int posicao2) {
    int temp;

    temp = vetor[posicao1];
    vetor[posicao1] = vetor[posicao2];
    vetor[posicao2] = temp;
}

// Função que auxilia a troca entre elementos nos indices do insertionSort
void insertion(int vetor[], int inicio, int fim, uint64_t* numComparacoes) {
    ssize_t procurado = buscaBinaria(vetor, fim, vetor[fim] , numComparacoes);
    int indice = fim;

    while (indice > procurado + 1){
        troca(vetor, indice, indice - 1);
        indice--;
    }   
    return;
}

// Função auxiliar para que seja possivel calcular o numero de comparações sem iniciar
// a variavel na main
uint64_t insertionSortRecAux(int vetor[], int inicio, int fim, uint64_t* numComparacoes){

    if(inicio > fim)
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

// Função recursiva para localizar o menor elemento em um vetor 
int minimoVetor(int vetor[], int inicio, int fim, uint64_t* numComparacoes){
    int menor;

    if(inicio == fim)
        return inicio;
    
    (*numComparacoes)++;
    menor = minimoVetor(vetor, inicio, fim - 1, numComparacoes);
    
    if(vetor[fim] < vetor[menor])
        menor = fim;

    return menor;   
}

uint64_t selectionSort(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;
    int menor;

    auxNumComparacoes = 0;
    for(size_t i = 0; i < tam - 1; i++){
        menor = minimoVetor(vetor, i, tam - 1, &auxNumComparacoes);
        // Troca da posição atual com o menor elemento dentro do vator
        auxNumComparacoes++;
        troca(vetor, i, menor);
    }

    return auxNumComparacoes;
}

// Função auxiliar para que seja possivel calcular o numero de comparações sem iniciar
// a variavel na main
uint64_t selectionSortRecAux(int vetor[], int inicio, int fim, uint64_t* numComparacoes){

    if(inicio >= fim)
        return 0;

    (*numComparacoes)++; 

    // Troca da posição atual com o menor elemento dentro do vator
    troca(vetor, inicio, minimoVetor(vetor, inicio + 1, fim, numComparacoes));
    selectionSortRecAux(vetor, inicio + 1, fim, numComparacoes);

    return *numComparacoes;
}

uint64_t selectionSortRec(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;
   
    auxNumComparacoes = 0;
    selectionSortRecAux(vetor, 0, tam - 1, &auxNumComparacoes);

    return auxNumComparacoes;
}

int* merge(int vetor[], int inicio, int meio, int fim) {
    if (inicio >= fim) {
        return vetor;
    }
    
    int tamanho = fim - inicio + 1;
    int indice_esquerda = inicio;
    int indice_direita = meio + 1;
    int indice_resultado = 0;

    int* vetor_temporario;
    vetor_temporario = malloc(sizeof(int) * tamanho);
      if (vetor_temporario == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return NULL;
    }

    while (tamanho > 0) {
        if (indice_direita > fim || (indice_esquerda <= meio && vetor[indice_esquerda] <= vetor[indice_direita])) {
            vetor_temporario[indice_resultado] = vetor[indice_esquerda];
            indice_esquerda++;
        } else {
            vetor_temporario[indice_resultado] = vetor[indice_direita];
            indice_direita++;
        }
        indice_resultado++;
        tamanho--;
    }

    // Copiar os elementos do vetor temporário de volta para o vetor original
    for (int i = 0; i < indice_resultado; i++) {
        vetor[inicio + i] = vetor_temporario[i];
    }

    free(vetor_temporario);
    return vetor;
}

uint64_t mergeSortRecAux(int vetor[], int inicio, int fim, uint64_t* numComparacoes){
    int meio;

    if(inicio <= fim)
        return 0;

    (*numComparacoes)++; 
    meio = (inicio + fim) / 2; 

    mergeSortRecAux(vetor, meio, fim, numComparacoes);
    mergeSortRecAux(vetor, meio + 1, fim, numComparacoes);
    merge(vetor, inicio, fim, meio);
    return *numComparacoes;
}

uint64_t mergeSortRec(int vetor[], size_t tam){
    uint64_t auxNumComparacoes;
    
    auxNumComparacoes = 0;
    mergeSortRecAux(vetor, 0, tam - 1, &auxNumComparacoes);
    return auxNumComparacoes;
}