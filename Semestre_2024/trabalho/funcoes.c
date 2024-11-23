#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> /*zerar matriz*/
#include "funcoes.h"

/*Retorna um número aleatório entre min e max, inclusive*/
long aleat(long min, long max){
    long n_aleat;

    /*Forma de gerar numeros aleatorios entre min e max includos eles mesmos*/
    n_aleat = rand() % (max - min + 1) + min;
    return n_aleat;
}


void zera_matriz(int linhas, int colunas, int matriz[linhas][colunas]){
    memset(matriz, 0, sizeof(int) * linhas * colunas);
}

void cria_vetor(int vet[], int tam){

    for (int i = 1; i < tam; i++){
        vet[i] = aleat(0, 2048); /*posição 0 guardada para sentinela*/
    }
}

void imprime_vetor(int vet[], int tam){

    if (!vet) /*verifica se vetor não esta vazio*/
        return;

    printf("vet[");
    printf("%d", vet[1]);/*para que não haja espaços em branco antes e depois*/
    for (int i = 2; i < tam; i++){
        printf(" %d", vet[i]);
        if (i % 35 == 0)
            printf("\n");
    }
    printf("]");
    printf("\n");
}

int buscaBinaria(int vet[], int tam, int valor, int *numComparacoes){
    *numComparacoes = 0;
    int inicio, fim, busca;

    inicio = 1;
    fim = tam - 1;

    while (inicio <= fim){
        busca = (inicio + fim) / 2;
        (*numComparacoes)++;

        if (valor == vet[busca])
            return busca; /*retorna imediatamente a função caso encontre o elemento */
        else if (valor < vet[busca])
            fim = busca - 1;
        else
            inicio = busca + 1;
    }

    return -1;
}

int buscaSequencial(int vet[], int tam, int valor, int *numComparacoes){
    int i;

    *numComparacoes = 0;
    vet[0] = valor;
    i = tam -1;

    while (vet[i] != valor){
        (*numComparacoes)++;
        i--;
    }
   
   if(!i)
        return -1;/*se a busca parou no sentinela, então elemento não esta no vetor*/
    return i;
}

short escolheEsp(){
    short escolha;
    do{
        printf("Escolha o espaçamento:\n");
        printf("1 - Espaçamento usando knuth\n");
        printf("2 - Espaçamento usando metodo original\n");
        scanf("%hd", &escolha);

        if (escolha < 1 || escolha > 2 )
            printf("\nValor deve ser 1 ou 2\n\n");

    } while (escolha < 1 || escolha > 2);

    return escolha;
}

short escolhePivo(){
    short escolha;

      do{
        printf("Escolha a posição do pivo:\n");
        printf("1 - Pivo em posição mediana\n");
        printf("2 - Pivo na primeira posição\n");
        scanf("%hd", &escolha);

        if (escolha < 1 || escolha > 2 )
            printf("\nValor deve ser 1 ou 2\n\n");

    } while (escolha < 1 || escolha > 2);

    return escolha;
}

void troca(int vet[], int posicao1, int posicao2){
    int temp;

    temp = vet[posicao1];
    vet[posicao1] = vet[posicao2];
    vet[posicao2] = temp;
}

int insertionSort(int vet[], int tam, int *permutacao){
    int auxNumComparacoes;
    int chave, j;

    auxNumComparacoes = 0;
    for (int i = 1; i < tam; i++){
        chave = vet[i];
        j = i - 1;
        while (j >= 1 && vet[j] > chave){
            auxNumComparacoes++;
            troca(vet, j, j + 1);
            (*permutacao)++;
            j--;
        }
        if (j >= 1)
            auxNumComparacoes++;
        vet[j + 1] = chave;
    }

    return auxNumComparacoes;
}

void particao(int vet[], int esq, int dir, int *pos_pivo, short tipoPivo, int *comparacoes, int *permutacao){
    int i, j, pivo, meio;
    
    if (tipoPivo == 1){
        /*escolha de pivo como mediana no vetor entre as posições
          inicial, meio e final*/;
        meio = (esq + dir) / 2;

        if (vet[esq] > vet[meio]) {
            troca(vet, esq, meio);
            (*permutacao)++;
        }
        if (vet[esq] > vet[dir]) {
            troca(vet, esq, dir);
            (*permutacao)++;
        }
        if (vet[meio] > vet[dir]) {
            troca(vet, meio, dir);
            (*permutacao)++;
        }

        pivo = vet[meio];
        troca(vet, esq, meio);  /*move o pivô para a posição inicial*/
        (*permutacao)++;
    }

    else 
        pivo = vet[esq]; /*pivo inicial no primeiro elemento*/

    i = esq;
    j = dir; /*variaveis que serão modificados na função*/

    while (i < j){
        while (vet[i] <= pivo && i < dir){
            (*comparacoes)++;
            i++;
        }
        while (vet[j] > pivo){
            (*comparacoes)++;
            j--;
        }
        if (i < j){ /*troca o elementos atual para a posição de menor indice, 
                    se for menor*/ 
            troca(vet, i, j);
            (*permutacao)++; 
        }   
    }
    troca(vet, esq, j); /*coloca o pivo na posição correta*/
    (*permutacao)++;
    *pos_pivo = j; /*Atualiza posição*/
}


/*Visto que o quick é recursivo, utilizado uma função auxiliar para realizar os procedimentos
  e retornar um numero, sem depender de uma main*/
int quickSortAux(int vet[], int esq, int dir, short tipoPivo, int *comparacoes, int *permutacao){
    int posPivo;

    if (esq < dir){
        particao(vet, esq, dir, &posPivo, tipoPivo, comparacoes, permutacao);/*partilha e posiciona*/
        quickSortAux(vet, esq, posPivo - 1, tipoPivo, comparacoes, permutacao);
        quickSortAux(vet, posPivo + 1, dir, tipoPivo, comparacoes, permutacao);
    }

    return *comparacoes;
}

int quickSort(int vet[], int tam, short tipoPivo, int *permutacao){
    int auxNumComparacoes;

    if (tipoPivo != 1 && tipoPivo != 2)
        return -1; /*erro e retorno*/ 

    auxNumComparacoes = 0;
    quickSortAux(vet, 1, tam - 1, tipoPivo, &auxNumComparacoes, permutacao);/*chama a função recursiva*/
    return auxNumComparacoes;
}

int shellsort(int vet[], int tam, short tipoEspacamento, int *permutacao){
    int auxNumComparacoes, i, j, aux, k;

    if (tipoEspacamento != 1 && tipoEspacamento != 2)
        return -1; /*erro e retorno*/

    if (tipoEspacamento == 1){/*metodo knuth, aprendido em aula*/
        k = 1;
        do{
            k = 3 * k + 1;/*utiliza um espaçamento de medio caso*/
        } while (k < tam);
    }

    else 
        k = (tam - 1) / 2;/*metodo original*/

    auxNumComparacoes = 0;
    do{
        if (tipoEspacamento == 1)      
            k /= 3;
        else
            k /= 2;
            
        for (i = k + 1; i < tam; i++){
            aux = vet[i];
            j = i;

            while(j >= k){
                auxNumComparacoes++;
                if (vet[j - k] > aux){
                    troca(vet, j, j - k);
                    (*permutacao)++;
                }
                else
                    break;
            
                j-=k;
            }
            
            vet[j] = aux;
        }
    } while (k >= 1);

    return auxNumComparacoes;
}

void mediaEdesvio(int vet[], int tam, double *media, double *desvio){
    double somaQuad;
    int soma;

    soma = 0;
    for (int i = 1; i < tam; i++)
        soma += vet[i];
    *media = (double) soma / (tam - 1);

    somaQuad = 0;
    for (int i = 1; i < tam; i++)
        somaQuad += pow(vet[i] - *media, 2);/*calculo da variancia, usando a função da raiz
                                                quadrada de math.h*/
    *desvio = sqrt(somaQuad / (tam - 1));/*desvio padrão = raiz quadrada da variancia*/
}