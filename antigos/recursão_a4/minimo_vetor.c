#include <stdio.h>

void levetor(int v[], int n){
   for(int i = 0;i < n; i++)
      scanf("%d",&v[i]);
}

int menor_valor(int v[],int a, int b){
   int menor;

   if (a == b)
      return a;
   menor = menor_valor(v,a,b-1);

   if(v[b] < v[menor])
      menor = b;
   return menor;
}

int main(){
   int n,menor,a,b;
   
   printf("Determine o tamanho do vetor v: ");
   scanf("%d",&n);
   int v[n];
   a = 0;
   b = n;
   levetor(v,n);
   menor = menor_valor(v,a,b);
   printf("O menor valor em v é: %d\n",v[menor]);
   return 0;
}
