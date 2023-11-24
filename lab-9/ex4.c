#include <stdio.h>

void bubble(int v[], int tam){
    int ult, i, aux, ordenado = 0;
    for (ult = tam-1; ult > 0; ult--) {
        if (ordenado) {
            break;
        }
        for (i = 0; i < ult; i++) {
            ordenado = 1;
            if (v[i] > v[i+1]) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                ordenado = 0;
            }
        }
    }
}

int main() {

    /*
        Para o melhor caso, a complexidade é O(n),
        pois o algoritmo deverá percorrer todo o array para verificar que está ordenado.
    */

    int arr[] = {4, 3, 2, 1};
    bubble(arr, 4);

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    puts("");

    return 0;
}