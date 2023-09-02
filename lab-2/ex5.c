#include <stdio.h>
#include <stdlib.h>

void printArray(int *a, int size);
void resetaArray(int *a, int size, int val);

int main() {

    int n;
scanf("%d", &n);

    // ler o array
    int *v = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", v+i);
    }

    
    int *posicoes = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        *(posicoes + i) = -1;    
    }

    int maior = v[0];
    int *k = posicoes;
    posicoes[0] = 0;
    for (int i = 1; i < n; i++) {
        if (*(v+i) > maior) {
            maior = *(v+i);
            resetaArray(posicoes, n, -1);
            posicoes[0] = i;
            k = posicoes;
        }
        else if (*(v+i) == maior) {
            k++;
            *k = i;
        }
    }

    printf("Maior numero: %d\n", maior);
    printf("Nas posições: ");
    for (int i = 0; i < n; i++) {
        if (*(posicoes+i) != -1) {
            printf("%d ", *(posicoes+i));
        }
    }
    puts("");

    return 0;
}

void printArray(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(a+i));
    }
    puts("");
}

void resetaArray(int *a, int size, int val) {
    for (int i = 0; i < size; i++) {
        *(a+i) = val;
    }
}