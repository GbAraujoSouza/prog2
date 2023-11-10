#include <stdio.h>

void buscaMenorMaiorBin(int arr[], int tam, int el, int* menor, int* maior);

int main (){

    int tam;
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tam);

    int arr[tam];
    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < tam; i++) {
        scanf("%d", &arr[i]);
    }

    int el;
    printf("Digite o elemento procurado: ");
    scanf("%d", &el);

    int maiores, menores;
    buscaMenorMaiorBin(arr, tam, el, &menores, &maiores);

    printf("Elem. MAIORES que %d: %d\n", el, maiores);
    printf("Elem. MENORES que %d: %d\n", el, menores);

    return 0;
}

void buscaMenorMaiorBin(int arr[], int tam, int el, int* menor, int* maior) {
    int fim = tam-1;
    int ini = 0;
    *menor = 0;
    *maior = 0;
    int interacao = 1;
    while (ini <= fim) {
        int meio = (fim + ini)/2;
        if (arr[meio] < el){
            *menor += meio - ini + 1;
            ini = meio + 1;
        }
        else {
            if (arr[meio] > el) {
                *maior += fim - meio + 1;
                fim = meio - 1;
            }
            else {
                *menor += meio - ini;
                *maior += fim - meio;
                return;
            }
        }
    }
}