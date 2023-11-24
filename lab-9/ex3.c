#include <stdio.h>

void bubble(int arr[], int tam) {

    if (tam < 2) {
        return;
    }

    for (int i = 0; i < tam - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            int tmp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = tmp;
        }
    }
    return bubble(arr, tam-1);
}

void insertion(int arr[], int tam) {
    if (tam <= 1) {
        return;
    }

    insertion(arr, tam - 1);

    int k = arr[tam - 1];
    int j = tam - 2;

    while (j >= 0 && arr[j] > k) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = k;
}

void selection(int arr[], int tam) {
    if (tam <= 1) {
        return;
    }

    int maiorIndex = 0;
    for (int i = 0; i < tam; i++) {
        if (arr[maiorIndex] < arr[i]) {
            maiorIndex = i;
        }
    }
    
    int tmp = arr[maiorIndex];
    arr[maiorIndex] = arr[tam - 1];
    arr[tam - 1] = tmp;

    selection(arr, tam - 1);
}

int main() {

    int arr[] = {4, 3, 2, 1};
    selection(arr, 4);

    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    puts("");


    return 0;
}