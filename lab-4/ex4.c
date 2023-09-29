#include <stdio.h>
#include <string.h>

int main() {

    char nomeArquivo[50];
    printf("Nome do arquivo: ");
    scanf("%s", nomeArquivo);

    char palavra[50];
    printf("Palavra: ");
    scanf("%s", palavra);

    // ler arquivo
    FILE* arquivo;
    if ((arquivo = fopen(nomeArquivo, "r")) == NULL) {
        printf("Erro ao abrir arquivo\n");
        return -1;
    }

    // ler linha por linha e usar a função strstr para checar se a palavra está na linha
    // a função strstr retorno um ponteiro NULL caso a linha nao contenha a palavra
    int count = 0;
    while(!feof(arquivo)) {
        char linha[100];
        fscanf(arquivo, "%[a-zA-Z a-zA-Z]%*c", linha);
        if(!(strstr(linha, palavra) == NULL)) {
            count++;
        }
    }
    printf("%d\n", count);

    fclose(arquivo);

    return 0;
}