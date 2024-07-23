#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include "ordenacao.h"

void lerVetor(int vetor[], ssize_t tam){

    for (int i = 0; i < tam; i++){
        printf("v[%d]: ", i);
        scanf("%d",&vetor[i]);
    }
}

void gerarAleatorio(int vetor[], size_t tam) {
    srand(0); // Inicializa a semente do gerador de números aleatórios com 0    
        
    for (size_t i = 0; i < tam; i++) 
        // Gera números aleatórios dentro do intervalo de 0 a 99
        vetor[i] = rand() % 100; 
}


void imprime_vetor(int vetor[], int tam){

    for(int i = 0; i < tam; i++)
        printf("v[%d] = %d ", i, vetor[i]);
    printf("\n");           
} 

int main() {
    char nome[MAX_CHAR_NOME];
    size_t idxBusca;
    uint64_t numComp;
    ssize_t tamVetor;
    unsigned int implementação, definição;
    int* vetor;

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());
    printf("\n");

    printf("Defina o tamanho do seu vetor: ");
    scanf("%ld",&tamVetor);
    printf("\n");

    vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }
    
    do{
        printf ("Digite 1 - definir valores de elementos do vetor\n");
        printf ("Digite 2 - gerar elementos aleatorios no intervalor de int\n");
        scanf("%u", &implementação);

        if (implementação != 1 && implementação != 2){
            printf("\n");
            printf("Por favor, digite apenas 1 ou 2.\n");
            printf("\n");
        }
    }while (implementação != 1 && implementação != 2);

    printf("\n");
    if(implementação == 1)  
        lerVetor(vetor, tamVetor);
    else    
        gerarAleatorio(vetor, tamVetor);

    printf("\n");
    imprime_vetor(vetor, tamVetor);
    printf("\n");

    do{
        printf("Defina o que voce quer fazer com o vetor:\n");
        printf("1 - Busca sequencial interativa de um valor espefico\n");
        printf("2 - Busca sequencial recursiva de um valor espefico\n");
        printf("3 - Busca binaria interativa de um valor espefico\n");
        printf("4 - Busca binaria recursiva de um valor espefico\n");
        printf("5 - Ordenação insertionSort interativo\n");
        printf("6 - Ordenação insertionSort recursivo\n");
        printf("7 - Ordenação selectionSort interativo\n");
        printf("8 - Ordenação selectionSort recursivo\n");
        printf("9 - Ordenação mergeSort rescursivo\n");
        scanf("%d",&definição);
        if(definição < 1 || definição > 9){
            printf("\n");
            printf("Valor deve estar entre 1 e 9\n");
            printf("\n");
        }
    }while(definição < 1 || definição > 9);

    printf("\n");
    
    clock_t start, end; 
    double total;
    int procurado;
    switch (definição){
        case 1:          
            printf("Digite o valor procurado:");
            scanf("%d", &procurado);
            start = clock(); 
            idxBusca = buscaSequencial(vetor, tamVetor, procurado, &numComp);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(idxBusca == -1)
                printf("Valor não existe no vetor\n");
            else 
                printf("O valor %d esta no indice %zu do vetor\n", procurado, idxBusca);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            break;
        
        case 2:            
            printf("Digite o valor procurado:");
            scanf("%d", &procurado);
            start = clock(); 
            idxBusca = buscaSequencialRec(vetor, tamVetor, procurado, &numComp);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(idxBusca == -1)
                printf("Valor não existe no vetor\n");
            else 
                printf("O valor %d esta no indice %zu do vetor\n", procurado, idxBusca);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            break;

        case 3:
            printf("Digite o valor procurado:");
            scanf("%d", &procurado);
            start = clock(); 
            idxBusca = buscaBinaria(vetor, tamVetor, procurado, &numComp);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(idxBusca == -1)
                printf("Valor não existe no vetor\n");
            else 
                printf("O valor %d esta no indice %zu do vetor\n", procurado, idxBusca);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            break;

        case 4:
            printf("Digite o valor procurado:");
            scanf("%d", &procurado);
            start = clock(); 
            idxBusca = buscaBinariaRec(vetor, tamVetor, procurado, &numComp);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(idxBusca == -1)
                printf("Valor não existe no vetor\n");
            else 
                printf("O valor %d esta no indice %zu do vetor\n", procurado, idxBusca);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            break;

        case 5:
            start = clock(); 
            numComp = insertionSort(vetor,tamVetor);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(numComp == -1)
                printf("Sem elementos para ordenar");
            printf("Vetor ordenado:\n");
            imprime_vetor(vetor,tamVetor);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            printf("\n");
            break;
        
        case 6:
            start = clock(); 
            numComp = insertionSortRec(vetor,tamVetor);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(numComp == -1)
                printf("Sem elementos para ordenar");
            printf("Vetor ordenado:\n");
            imprime_vetor(vetor,tamVetor);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            printf("\n");
            break;

        case 7:
            start = clock(); 
            numComp = selectionSort(vetor,tamVetor);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(numComp == -1)
                printf("Sem elementos para ordenar");
            printf("Vetor ordenado:\n");
            imprime_vetor(vetor,tamVetor);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            printf("\n");
            break;

        case 8:
            start = clock(); 
            numComp = selectionSortRec(vetor,tamVetor);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(numComp == -1)
                printf("Sem elementos para ordenar");
            printf("Vetor ordenado:\n");
            imprime_vetor(vetor,tamVetor);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            printf("\n");
            break;

        case 9:
            start = clock(); 
            numComp = mergeSortRec(vetor,tamVetor);
            end = clock();
            total = ((double)end - start) / CLOCKS_PER_SEC;
            if(numComp == -1)
                printf("Sem elementos para ordenar");
            printf("Vetor ordenado:\n");
            imprime_vetor(vetor,tamVetor);
            printf("O numero de comparações é: %lu\n", numComp);
            printf("O tempo total do algoritmo é: %f", total);
            printf("\n");
            break;
    default:
        break;
    }
    
    printf("\n");

    free(vetor);
    return 0;
}

