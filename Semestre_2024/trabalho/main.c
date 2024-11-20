#include <stdio.h>
#include <stdlib.h>
#include <time.h> /*gerar numeros aleatorios*/
#include "funcoes.h"

#define MAX 1024

void imprimeResultados(int comparacoes[7][1000], int trocas[7][1000]){
    const char* nomes[] = {
        "ShellSort (espaçamento 1)",
        "ShellSort (espaçamento 2)",
        "QuickSort (pivô 1)",
        "QuickSort (pivô 2)",
        "InsertionSort",
        "Busca Binária",
        "Busca Sequencial"
    };

    for (int i = 0; i < 7; i++) {
        printf("\nResultados para: %s\n", nomes[i]);
        /*calculo e exibição de média e desvio padrão*/
        double mediaComp, desvCom, mediaPer = 0, desvPer = 0;
        mediaEdesvio(comparacoes[i], 3, &mediaComp, &desvCom);
        if (i < 5) {
            mediaEdesvio(trocas[i], 3, &mediaPer, &desvPer);
        }
        printf("Média e desvio das comparações: %.2f, %.2f\n", mediaComp, desvCom);
        if (i < 5) {
            printf("Média e desvio das permutações: %.2f, %.2f\n", mediaPer, desvPer);
        }
    }
}


void programaAleatorio(int comparacoes[7][1000], int trocas[7][1000], int vet[], int tam) {
    int valorAlet, idBusc;

    zera_matriz(7, 1000, comparacoes);
    zera_matriz(7, 1000, trocas);
    for (int i = 1; i < 1000; i++){
        /*Shellsort usando espaçamento aprendido em aula*/
        printf("Ordenado com ShellSort, espaçamento 1:\n");
        printf("Criando vetor aleatorio:\n");
        cria_vetor(vet, tam);
        imprime_vetor(vet, tam);
        comparacoes[0][i] = shellsort(vet, tam, 1, &trocas[0][i]);
        imprime_vetor(vet, tam);
        printf("Comparações: %d\n", comparacoes[0][i]);
        printf("Permutações(trocas): %d\n\n", trocas[0][i]);

        /*Shellsort usando espaçamento original*/
        printf("Ordenado com ShellSort, espaçamento 2:\n");
        printf("Criando vetor aleatorio:\n");
        cria_vetor(vet, tam);
        imprime_vetor(vet, tam);
        comparacoes[1][i] = shellsort(vet, tam, 2, &trocas[1][i]);
        imprime_vetor(vet, tam);
        printf("Comparações: %d\n", comparacoes[1][i]);
        printf("Permutações(trocas): %d\n\n", trocas[1][i]);

        /*QuickSort com pivo em melhor posição*/
        printf("Ordenado com QuickSort, pivo 1:\n");
        printf("Criando vetor aleatorio:\n");
        cria_vetor(vet, tam);
        imprime_vetor(vet, tam);
        comparacoes[2][i] = quickSort(vet, tam, 1, &trocas[2][i]);
        imprime_vetor(vet, tam);
        printf("Comparações: %d\n", comparacoes[2][i]);
        printf("Permutações(trocas): %d\n\n", trocas[2][i]);

        /*QuickSort com pivo em posição inicial. aprendido em aula*/
        printf("Ordenado com QuickSort, pivo 2:\n");
        printf("Criando vetor aleatorio:\n");
        cria_vetor(vet, tam);
        imprime_vetor(vet, tam);
        comparacoes[3][i] = quickSort(vet, tam, 2, &trocas[3][i]);
        imprime_vetor(vet, tam);
        printf("Comparações: %d\n", comparacoes[3][i]);
        printf("Permutações(trocas): %d\n\n", trocas[3][i]);

        /*InsertionSort*/
        printf("Ordenado com InsertionSort:\n");
        printf("Criando vetor aleatorio:\n");
        cria_vetor(vet, tam);
        imprime_vetor(vet, tam);
        comparacoes[4][i] = insertionSort(vet, tam, &trocas[4][i]);
        imprime_vetor(vet, tam);
        printf("Comparações: %d\n", comparacoes[4][i]);
        printf("Permutações(trocas): %d\n\n", trocas[4][i]);

        printf("Utilizando vetor ordenado anteriormente para realizar busca binaria:\n");
        printf("Gerando um valor aleatorio para ser pesquisado: ");
        valorAlet = aleat(0,2048);
        printf("%d\n", valorAlet);
        idBusc = buscaBinaria(vet, tam, valorAlet, &comparacoes[5][i]);
        if (idBusc == -1)
            printf("Valor não existe no vetor\n");
        else
            printf("O valor %d esta no indice %d do vetor\n", valorAlet, idBusc);
        printf("Comparações: %d\n\n", comparacoes[5][i]);

        printf("Utilizando busca sequencial:\n");
        printf("Criando vetor aleatorio:\n");
        cria_vetor(vet, tam);
        imprime_vetor(vet, tam);
        printf("Gerando um valor aleatorio para ser pesquisado: ");
        valorAlet = aleat(0,2048);
        printf("%d\n", valorAlet);
        idBusc = buscaSequencial(vet, tam, valorAlet, &comparacoes[6][i]);
        if (idBusc == -1)
            printf("Valor não existe no vetor\n");
        else
            printf("O valor %d esta no indice %d do vetor\n", valorAlet, idBusc);
        printf("Comparações: %d\n\n", comparacoes[6][i]);

    }

    imprimeResultados(comparacoes, trocas);
    
}

void programaManual(int vet[], int tam){
    int compara, permuta, valorProc, idBusc;
    short escolha2, escolha3, escolha4;

    printf("Criando vetor aleatorio:\n");
    cria_vetor(vet, tam);
    imprime_vetor(vet, tam);
    printf("\n");

    do{
        printf("Defina o que voce quer fazer com o vetor:\n");
        printf("1 - Busca sequencial de um valor especifico\n");
        printf("2 - Busca binaria de um valor especifico\n");
        printf("3 - Ordenação usando ShellSort\n");
        printf("4 - Ordenação usando QuickSort\n");
        printf("5 - Ordenação usando InsetionSort\n");        
        scanf("%hd",&escolha2);

        if(escolha2 < 1 || escolha2 > 5)
            printf("\nValor deve estar entre 1 e 5\n\n");
    } while(escolha2 < 1 || escolha2 > 5);

    switch (escolha2){
        case 1:
            printf("Digite o valor procurado ou '-1' se quiser que numero seja gerado aleatoriamente:");
            scanf("%d", &valorProc);
            if (valorProc == -1){
                valorProc = aleat(0, 2048);
                printf("O valor que será procurado é: %d\n", valorProc);
            }
            idBusc = buscaSequencial(vet, tam, valorProc, &compara);
            if (idBusc == -1)
                printf("Valor não existe no vetor\n");
            else
                printf("O valor %d esta no indice %d do vetor\n", valorProc, idBusc);
            printf("Comparações: %d\n", compara);
        break;

        case 2:
            do{
                printf("Escolha um algoritmo para ordenar o vetor:\n");
                printf("1 - Ordenação usando ShellSort\n");
                printf("2 - Ordenação usando QuickSort\n");
                printf("3 - Ordenação usando InsetionSort\n"); 
                scanf("%hd",&escolha3);

                if(escolha3 < 1 || escolha3 > 3)
                    printf("\nValor deve estar entre 1 e 3\n\n");
            } while (escolha3 < 1 || escolha3 > 3);

            switch (escolha3){
                case 1:/*ShellSort*/
                    escolha4 = escolheEsp();
                    permuta = 0;
                    compara = shellsort(vet, tam, escolha4, &permuta);
                break;
            
                case 2:/*QuickSort*/
                    escolha4 = escolhePivo();
                    permuta = 0;
                    compara = quickSort(vet, tam, escolha4, &permuta);
                break;

                case 3:
                    permuta = 0;
                    compara = insertionSort(vet, tam, &permuta);
                break;
                default:
                    break;
            }
            printf("Vetor apos ordenação:\n");
            imprime_vetor(vet, tam);
            printf("Digite o valor procurado ou '-1' se quiser que numero seja gerado aleatoriamente:");
            scanf("%d", &valorProc);
            if (valorProc == -1){
                valorProc = aleat(0, 2048);
                printf("O valor que será procurado é: %d\n", valorProc);
            }
            idBusc = buscaBinaria(vet, tam, valorProc, &compara);
            if (idBusc == -1)
                printf("Valor não existe no vetor\n");
            else
                printf("O valor %d esta no indice %d do vetor\n", valorProc, idBusc);
            printf("Comparações ordenação escolhida + buscaBinaria: %d\n", compara);
            printf("Permutações(trocas) na ordenação escolhida: %d\n\n", permuta);
        break;

        case 3:
            permuta = 0; 
            escolha3 = escolheEsp();
            compara = shellsort(vet, tam, escolha3, &permuta);
            imprime_vetor(vet, tam);
            printf("Comparações: %d\n", compara);
            printf("Permutações(trocas): %d\n\n", permuta);
        break;

        case 4:
            permuta = 0;
            escolha3 = escolhePivo();
            compara = quickSort(vet, tam, escolha3, &permuta);
            imprime_vetor(vet, tam);
            printf("Comparações: %d\n", compara);
            printf("Permutações(trocas): %d\n\n", permuta);
        break;

        case 5:
            permuta = 0;
            compara = insertionSort(vet, tam, &permuta);
            imprime_vetor(vet, tam);
            printf("Comparações: %d\n", compara);
            printf("Permutações(trocas): %d\n\n", permuta);
        break;
        default:
            break;
    }
}


int main(){
    int comparacoes[7][1000], trocas[7][1000];/*matrizes para facilitar calculos de media e desvio*/
    int vet[MAX];
    short escolha1;
    char saida;
    srand(time(NULL));

    do{
        do{
            printf ("Digite 1 caso queira que o programa rode aleatoriamente\n" 
                    "ou 2 caso queria realizar as ecolhas manualmente: ");
            scanf("%hd", &escolha1);

            if(escolha1 != 1 && escolha1 != 2)
                printf("\nPor favor, digite apenas 1 ou 2.\n\n");
        } while (escolha1 != 1 && escolha1 != 2);
        
        printf("\n");

        if (escolha1 == 1){/*executa o programa 2 vezes*/
            programaAleatorio(comparacoes, trocas, vet, MAX);
        }

        else{
            programaManual(vet, MAX);
        }

        printf("\n");
        printf ("Digite 's' caso queira finalizar o programa ou qualquer outra caracter para continuar:");
        scanf("%s", &saida);
        printf("\n");
    } while (saida != 's');
    return 0;
}