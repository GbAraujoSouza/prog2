#include <stdio.h>
float max(float v[], int n);

int main() {

    float v[] = {-561, 2,-349, 4, 5, 6, 7, 8, 9, 10 }; int n = 5;

    float maiorElemento = max(v, n); printf("maior elemento do array: %.2f\n", maiorElemento);
    
    return 0;
}

float max(float v[], int n) {

    float maior = v[0];
    for (int i = 0; i < n; i++) {

        if (*(v + i) > maior) {
             maior = *(v + i);
        }
    }
    return maior;
}