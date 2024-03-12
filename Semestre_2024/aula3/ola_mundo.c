#include <stdio.h>

void ola_mundo(int n){

    if (n == 0)
        return;

    else {
        printf("ola mundo %d\n",n);
        ola_mundo(n-1);
    }

}

int main(){
    int n;

    scanf("%d",&n);
    ola_mundo(n);
    return 0; 
}