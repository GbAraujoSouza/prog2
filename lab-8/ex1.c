#include <stdio.h>

void buscaSeqOrdRep(int arr[], int tam, int el, int *pos, int *quant);

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

    int pos = -1, qnt = 0;
    buscaSeqOrdRep(arr, tam, el, &pos, &qnt);

    printf("Posicao da primeita ocorrencia: %d\n", pos);
    printf("Quantidade de ocorrencias: %d\n", qnt);

    return 0;
}

void buscaSeqOrdRep(int arr[], int tam, int el, int *pos, int *quant) {
    int achouElem = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[i] >= el) {
            if (arr[i] == el && achouElem){
                *quant += 1;
            }
            else if (arr[i] == el && !achouElem) {
                *pos = i;
                *quant += 1;
                achouElem = 1;
            }
            else {
                break;
            }
        }
    }
    if (!achouElem) {
        *pos = -1;
        *quant = 0;
    }
}