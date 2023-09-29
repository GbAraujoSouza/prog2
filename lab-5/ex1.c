#include <stdio.h>
#include <stdlib.h>


int main() {

    char nomeArquivo[50];
    printf("Nome do arquivo: ");
    scanf("%s", nomeArquivo);
    FILE* pArquivo;
    int N;
    printf("N: ");
    scanf("%d", &N);

    if ((pArquivo = fopen(nomeArquivo, "wb+")) == NULL) {
        puts("Erro ao abrir o arquivo");
        return -1;
    }
    int* temp = (int*)malloc(N*sizeof(int));
    for (int i = N; i > 0; i--) {
        temp[N-i] = i;
    }
    fwrite(temp, sizeof(int), N, pArquivo);
    int* numeros = (int*)malloc(N*sizeof(int));
    if (!numeros) {
        puts("Erro de alocação de memória");
        return -1;
    }
    rewind(pArquivo);
    fread(numeros, sizeof(int), N, pArquivo);

    for (int i = 0; i < N; i++) {
        printf("%d ", numeros[i]);
    }
    puts("");

    fclose(pArquivo);


    return 0;
}