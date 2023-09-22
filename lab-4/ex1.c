#include <stdio.h>

int main() {
    
    int numAlunos;
    char nomeArquivo[50];

    printf("Numero de alunos: ");
    scanf("%d", &numAlunos);

    printf("Arquivo de saida: ");
    scanf("%s", nomeArquivo);

    FILE* arquivoSaida;
    if ((arquivoSaida = fopen(nomeArquivo, "w")) == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return -1;
    }

    for (int aluno = 0; aluno < numAlunos; aluno++) {
        char nomeAluno[50];
        float p1, p2, trabalho;
        printf("Nome aluno #%d: ", aluno + 1);
        getchar();
        scanf("%[^\n]c", nomeAluno);

        printf("Nota P1 aluno #%d: ", aluno + 1);
        scanf("\n%f", &p1);

        printf("Nota P2 aluno #%d: ", aluno + 1);
        scanf("%f", &p2);

        printf("Nota Trabalho aluno #%d: ", aluno + 1);
        scanf("%f", &trabalho);

        // escrever no arquivo de saida
        fprintf(arquivoSaida, "%s %.1f %.1f %.1f\n", nomeAluno, p1, p2, trabalho);

        
    }

    fclose(arquivoSaida);
    
    return 0;
}