#include <stdio.h>

void bubble(int arr[], int tam);
void insertion(int arr[], int tam);
void selection(int arr[], int tam);

int main() {

     int v[] = {1, 2, 3, 4};
    // bubble(v, 4);
    // insertion(v, 4);
    selection(v, 4);

    for (int i = 0; i < 4; i++) {
        printf("%d ", v[i]);
    }
    puts("");

    return 0;
}

void bubble(int arr[], int tam) {
    for (int final = tam - 1; final > 0; final--) {
        for (int i = 0; i < final; i++) {
            if (arr[i] < arr[i+1]) {
                int tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }
}

void insertion(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        int j = i;
        int aux = arr[i];
        while (j > 0 && aux > arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = aux;
    }
}

void selection(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int indexMaior = i;
        for (int j = i; j < tam; j++) {
            if (arr[j] > arr[indexMaior]) {
                indexMaior = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[indexMaior];
        arr[indexMaior] = tmp;
    }
}