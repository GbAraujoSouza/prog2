#include <stdio.h>

int buscaBin(int arr[], int tam, int el);

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

    int pos = buscaBin(arr, tam, el);
    printf("Elemento encontrado na posicao: %d\n", pos);

    return 0;
}

int buscaBin(int arr[], int tam, int el) {
    int fim = tam-1;
    int ini = 0;
    int interacao = 1;
    while (ini <= fim) {
        int meio = (fim + ini)/2;
        if (arr[meio] < el){
            printf("%da. iteracao: %d\n", interacao++, meio - ini + 1);
            ini = meio + 1;
        }
        else {
            if (arr[meio] > el) {
                printf("%da. iteracao: %d\n",interacao++, fim - meio + 1);
                fim = meio - 1;
            }
            else {
                printf("%da. iteracao: %d\n",interacao++, fim - ini);
                return meio;
            }
        }
    }
    return -1;
}