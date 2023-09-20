#include <stdio.h>

int fatorial_recursivo(int n){
   
   if (n <= 0)
      return 1;
   return n * fatorial_recursivo(n-1);
}


int main(){
   int n;

   printf("Determine qual fatorial será calculado: ");
   scanf("%d", &n);
   printf("%d\n",fatorial_recursivo(n));
   return 0;
}

