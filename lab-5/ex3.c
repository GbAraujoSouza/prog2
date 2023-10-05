#include <stdio.h>

typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main() {

    FILE* pArquivo;
    if (!(pArquivo = fopen("./alunos.dat", "rb"))) {
        puts("Erro ao abrir arquivo.");
        return -1;
    }

    while (!feof(pArquivo))
    {
        puts("contagem");
        Taluno a;
        if (fread(&a, sizeof(Taluno), 1, pArquivo)){
            printf("%s P1: %.2lf P2: %.2lf P3: %.2lf Media%.2lf \n", a.nome, a.nota[0], a.nota[1], a.nota[2], a.media);
        }
    }
    puts("");


    return 0;
}