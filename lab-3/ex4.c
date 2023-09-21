#include <stdio.h>
#include <string.h>

#define MAX 80

void inverteString(char *str);

int main(int argc, char *argv[]) {

    if (argc != 3) {
        puts("ERRO! Utilização do programa: ./ex4 <arquivo de entrada> <arquivo de saída>");
        return -1;
    }

    char *arqEntrada = argv[1];
    char *arqSaida = argv[2];

    FILE *pArqEntrada, *pArqSaida;

    if ((pArqEntrada = fopen(arqEntrada, "r")) == NULL) {
        puts("Não foi possível abrir o arquivo de entrada");
        return -1;
    }
    if ((pArqSaida = fopen(arqSaida, "w")) == NULL) {
        puts("Não foi possível abrir o arquivo de saída");
        return -1;
    }

    char linha[MAX];
    fgets(linha, MAX, pArqEntrada);
    while (!feof(pArqEntrada)) {
        // inverter a linha
        inverteString(linha);
        //escrever a linha na saída
        fputs(linha, pArqSaida);
        fgets(linha, MAX, pArqEntrada);
    }

    fclose(pArqEntrada);
    fclose(pArqSaida);
    

    return 0;
}

void inverteString(char *string) {
    // no trecho "strlen(string) - 2" diminuímos por 2 pos nao queremos inverter o caractere '\n'
    for (int i = 0, j = strlen(string) - 2; i < strlen(string) / 2; i++, j--) {
        char temp = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = temp;
    }
}