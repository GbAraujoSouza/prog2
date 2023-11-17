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