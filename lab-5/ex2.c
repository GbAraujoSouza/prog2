#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main() {

    // FILE* pArquivo;
    // if (!(pArquivo = fopen("./alunos.dat", "wb+"))) {
    //     puts("Erro ao criar o arquivo");
    //     return 0;
    // }

    char nome[100];
    do
    {
        printf("Nome: ");
        fgets(nome, 100, stdin);
    } while (nome[0] != '\n');
    


    return 0;
}