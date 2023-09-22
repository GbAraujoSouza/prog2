#include <stdio.h>

int main() {

    FILE* arquivoNotas, *arquivoMedias;
    char nomeArquivoNotas[50], nomeArquivoMedias[50];

    printf("Arquivo com as notas: ");
    scanf("%s", nomeArquivoNotas);

    printf("Arquivo de saida com as médias: ");
    scanf("%s", nomeArquivoMedias);

    if ((arquivoNotas = fopen(nomeArquivoNotas, "r")) == NULL) {
        printf("Erro ao abrir arquivo de notas\n");
        return -1;
    }
    if (((arquivoMedias = fopen(nomeArquivoMedias, "w")) == NULL)) {
        printf("Erro ao abrir arquivo das medias\n");
        return -1;
    }

    while (!feof(arquivoNotas))
    {
        char nome[50];
        float p1, p2, trabalho;
        fscanf(arquivoNotas, "%[a-zA-Z a-zA-Z] %f %f %f\n", nome, &p1, &p2, &trabalho);
        fprintf(arquivoMedias, "%s%.1f\n", nome, (((p1 + p2)/2)*0.8 + trabalho * 0.2));
    }
    
    fclose(arquivoMedias);
    fclose(arquivoNotas);

    return 0;
}