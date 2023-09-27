#include "ordenacao.h"

void getNome(char nome[]);

unsigned int getGRR();

int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes);

int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes);

long insertionSort(int vetor[], int tam);

long selectionSort(int vetor[], int tam);

long mergeSort(int vetor[], int tam);

long quickSort(int vetor[], int tam);

long heapSort(int vetor[], int tam);