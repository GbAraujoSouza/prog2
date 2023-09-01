#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);

    int *v = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", v+i);
    }

    int maior = v[0];
    int *posicoes = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        *(posicoes + i) = -1;    
    }
    int k;
    for (int i = 0; i < n; i++) {
        if (*(v+i) > maior)
    }

    return 0;
}