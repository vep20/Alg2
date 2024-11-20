// Funções utilizadas para o desenvolvimento do trabalho de Alg2, semestre 2024/2
// Victor Eduarado de Paula - GRR20203937

#ifndef Funcoes
#define Funcoes

/*Recebe uma valor max e min para gerar numeros aleatórios.*/
long aleat(long min, long max);

/*Função de inserção de elementos aleatórios em um vetor.*/
void cria_vetor(int vet[], int tam);

/*Função para impressão de todos os elementos em um vetor.*/
void imprime_vetor(int vet[], int tam);

/*Função que busca um elementos de forma ingenua em um vetor.
  Retorna o indice do vetor onde o elemento se encontra ou -1 caso 
  não encontre. Utiliza um sentinela para realizar o procedimento
  Tambem retorna o numero de comparações em um ponteiro.*/
int buscaSequencial(int vet[], int tam, int valor, int *numComparacoes);

/*Função que busca um elementos de forma mais eficaz em um vetor.
  Retorna o indice do vetor onde o elemento se encontra ou -1 caso 
  não encontre.
  Tambem retorna o numero de comparações em um ponteiro.*/
int buscaBinaria(int vet[], int tam, int valor, int *numComparacoes);

/*Função de troca de elementos em um vetor*/
void troca(int vet[], int posicao1, int posicao2);

/*Função de ordenação quadratica. Ordena o vetor e retorna o numero 
  de comparações necessarias para realizar o procedimento.*/
int insertionSort(int vet[], int tam, int *permutacao);

/*Função que partilha o vetor*/
void particao(int vet[], int esq, int dir, int *pos_pivo, short tipoPivo, int *comparacoes, int *permutcao);

/*Função de ordenação realizada com auxilio da função de partição.
  Ordena o vetor e retorna o numero 
  de comparações necessarias para realizar o procedimento.*/
int quickSort(int vet[], int tam, short tipoPivo, int *permutacao);

/*Função de ordenação que utiliza espaçamentos entre os elementos, usando subvetores,
  os quais executam o melhor caso do InsertionSort*/
int shellsort(int vet[], int tam, short tipoEspacamento, int *permutacao);

void mediaEdesvio(int vet[], int tam, double *media, double *desvio);

/*Função que adiciona 0 em todos os elementos de uma matriz*/
void zera_matriz(int linhas, int colunas, int matriz[linhas][colunas]);

/*FUnção que escolhe um espaçamento para utilizar no algoritmo de ordenação ShellSort*/
short escolheEsp();

/*FUnção que escolhe um pivo para utilizar no algoritmo de ordenação QuickSort*/
short escolhePivo();

#endif 