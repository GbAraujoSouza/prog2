#include <stdio.h>
#include <string.h>

#define MAX 80

void inverteString(char *str);

int main(int argc, char *argv[]) {

    char *arqEntrada = argv[1];
    char *arqSaida = argv[2];
    FILE *pArqEntrada, *pArqSaida;
    pArqEntrada = fopen(arqEntrada, "r");
    pArqSaida = fopen(arqSaida, "w");

    char linha[MAX];
    fgets(linha, MAX, pArqEntrada);
    while (!feof(pArqEntrada)) {
        // inverter a linha
        inverteString(linha);
        //escrever a linha na saida
        fputs(linha, pArqSaida);
        fgets(linha, MAX, pArqEntrada);
    }

    fclose(pArqEntrada);
    fclose(pArqSaida);
    

    return 0;
}

void inverteString(char *string) {
    for (int i = 0, j = strlen(string) - 2; i < strlen(string) / 2; i++, j--) {
        char temp = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = temp;
    }
}