#include <stdio.h>

int insert_sort(int v[], int a, int b){

   return 
}


void le_vetor(int v[], int n){
  
   for(int i = 0; i < n; i++){
      scanf("%d", v[i]);
      insert_sort(v,0,i);
   }
}

void imprime_vetor(int v[], int n){

     for(int i = 0; i < n; i++){
         printf("%d\n", v[i]);  
}

int main(){
   int quant, v[];

   printf("Difina quantas posições terá seu vetor");
   scanf("%d", &quant);
   le_vetor(v,quant);
   imprime_vetor(v, quant);
   retun 0;
}
