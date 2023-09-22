#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    FILE* tempos;
    if ((tempos = fopen("tempos.txt", "r")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return -1;
    }

    int A, C;
    fscanf(tempos, "%d %d\n", &A, &C);

    int **registro = (int**)malloc(A * sizeof(int*));
    if (registro == NULL) {
        printf("Erro ao alocar memoria\n");
    }

    int atleta = 0;
    while(!feof(tempos)) {
        int* corridas = (int*)malloc(C*sizeof(int));
        if (corridas == NULL) {
            printf("Erro ao alocar memoria\n");
        }
        for (int corrida = 0; corrida < C; corrida++){
            int horas, minutos, segundos, tempoTotal;
            fscanf(tempos, "%d %d %d", &horas, &minutos, &segundos);
            tempoTotal = (horas * 3600) + (minutos * 60) + segundos;
            corridas[corrida] = tempoTotal;
        }
        registro[atleta] = corridas;
        atleta++;
    }

    int menorTempo = INT_MAX, melhorIndex = 0; 
    for (int i = 0; i < A; i++)
    {
        int somaCorrida = 0;
        for (int j = 0; j < C; j++)
        {
            somaCorrida += *(*(registro + i) + j);
        }
        if (somaCorrida < menorTempo) {
            menorTempo = somaCorrida;
            melhorIndex = i;
        }
    }
    
    printf("%d\n", melhorIndex + 1);

    return 0;
}