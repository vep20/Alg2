#include <stdio.h>

void levetor(int n, int v[]){
   for(int i = 0;i < n; i++)
      scanf("%d",&v[i]);
}

int menor_valor(int v[],int a, int b){
   int menor;

   if (a == b)
      return a;
   menor = menor_valor(v,a,b);
   if v[b] < v[menor];
      menor = b;
   return menor;
}

int main(){
   int n,menor,v[],a,b;
   
   printf("Determine o tamanho do vetor v: ");
   scanf("%d",&n);
   a = 0;
   b = n;
   lervetor(v,n)
   menor = menor_valor(v,a,b);
   printf("O menor valor em v é: %d",v[menor]);
   return 0;
}
