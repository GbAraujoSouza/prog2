#include <stdio.h>
#define DIM 9

void inicM(int matriz[][DIM], int valorInicial);
void mostraM(int matriz[][DIM]);
void incluiElem(int matriz[][DIM], int i, int j, int num);

int main() {

    int M[DIM][DIM];
    inicM(M, 0);
    incluiElem(M, 1, 1, 5);
    mostraM(M);

    return 0;
}

void inicM(int matriz[][DIM], int valorInicial) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            *(*(matriz + i) + j) = valorInicial;
        }
    }
}

void mostraM(int matriz[][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
             printf("%d ", *(*(matriz + i) + j));
        }
        puts("");
    }
}

void incluiElem(int matriz[][DIM], int i, int j, int num) {

    *(*(matriz + i) + j) = num;

}