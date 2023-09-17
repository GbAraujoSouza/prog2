#include <stdio.h>
#include <stdlib.h>

int main() {

    int L,C,M,N, **plantacao;
    scanf("%d %d %d %d", &L, &C, &M, &N);

    // inicialização da matriz como ponteiro de ponteiros
    plantacao = (int **)malloc(L * sizeof(int *));
    if (!plantacao) {
        puts("Erro na alocação de memoria!");
        return -1;
    }
    for (int linha = 0; linha < L; linha++) {
        *(plantacao + linha) = (int *)malloc(C * sizeof(int));
        if (! (*(plantacao + linha))) {
            puts("Erro na alocação de memoria!");
            return -1;
        }
    }

    // Leitura da matriz
    for (int linha = 0; linha < L; linha++) {
        for (int col = 0; col < C; col++) {
            scanf("%d", *(plantacao + linha) + col);
        }    
    }

    // varredura da matriz por lote para achar a maior soma possivel
    int maiorSoma = 0;
    for (int linha = 0; linha < L; linha += M) {
        for (int col = 0; col < C; col += N) {
            int somaCorrente = 0;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    somaCorrente += *(*(plantacao + linha + i) + col + j);
                }
            }
            if (somaCorrente > maiorSoma) {
                maiorSoma = somaCorrente;
            }
        }
    }

    printf("%d\n", maiorSoma);

    return 0;
}