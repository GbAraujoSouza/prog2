#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    double nota[3];
    double media;
} Taluno;

int main() {

     FILE* pArquivo;
     if (!(pArquivo = fopen("./alunos.dat", "wb+"))) {
         puts("Erro ao criar o arquivo");
         return 0;
     }

    // variavel nome para verificar se usuario teclou enter
    char nome[100];
    
    do {
        // inicializar aluno temporario
        Taluno aluno;
        aluno.media = 0;

        // ler o nome do aluno
        printf("Nome: ");
        fgets(nome, sizeof(nome), stdin);
        if (nome[0] == '\n') {
            break;
        }
        strcpy(aluno.nome, nome);

        // Aparentemente, o fgets está armazenando um \n ao final da string nome.
        // o trecho abaixo resolve esse problema
        size_t newline_pos = strcspn(aluno.nome, "\n");
        if (aluno.nome[newline_pos] == '\n') {
            aluno.nome[newline_pos] = '\0';
        }

        // ler as notas e calcular a média
        for (int i = 0; i < 3; i++) {
            printf("P%d: ", i + 1);
            scanf("%lf", aluno.nota + i);
            aluno.media += *(aluno.nota + i);
        }
        aluno.media /= 3;

        // getchar para limpar o \n deixado em buffer pelo scanf
        getchar();
        
        // gravar no arquivo
        fwrite(&aluno, sizeof(Taluno), 1, pArquivo);


    } while (nome[0] != '\n');
    
    fclose(pArquivo);

    return 0;
}