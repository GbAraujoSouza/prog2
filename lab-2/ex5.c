#include <stdio.h>
#include <stdlib.h>

void printArray(int *p, int size);

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
    int *k = posicoes;
    for (int i = 0; i < n; i++) {
        if (*(v+i) >= maior) {
            maior = *(v+i);
            *k = i;
            k++;
        }
    }

    printArray(v, n);
    printf("Maior elemento é %d\n", maior);
    printf("Nas posições: ");
    for (int i = 0; i < n; i++) {
        if (*(posicoes+i) != -1)
            printf("%d ", *(posicoes+i));
    }
    puts("");
    printArray(posicoes, n);

    return 0;
}

void printArray(int *p, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p+i));
    }
    puts("");
}