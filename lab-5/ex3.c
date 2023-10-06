#include <stdio.h>

typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main() {

    FILE* pArquivo;
    if (!(pArquivo = fopen("./alunos.dat", "rb+"))) {
        puts("Erro ao abrir arquivo.");
        return -1;
    }

    int mediasAlteradas = 0, totalAlunos = 0;

    while (!feof(pArquivo))
    {
        puts("contagem");
        Taluno aluno;
        if (fread(&aluno, sizeof(Taluno), 1, pArquivo)){
            fseek(pArquivo, sizeof(int), SEEK_SET);
            if (aluno.media != (0.25 * aluno.nota[0] + 0.35 * aluno.nota[1] + 0.4 * aluno.nota[2])) {
                aluno.media = (0.25 * aluno.nota[0] + 0.35 * aluno.nota[1] + 0.4 * aluno.nota[2]);
                fwrite(&aluno.media, sizeof(int), 1, pArquivo);
                mediasAlteradas++;
            }
            totalAlunos++;

            printf("%s P1: %.2lf P2: %.2lf P3: %.2lf Media%.2lf \n", aluno.nome, aluno.nota[0], aluno.nota[1], aluno.nota[2], aluno.media);
        }
    }
    puts("");


    return 0;
}