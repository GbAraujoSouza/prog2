#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main ()
{
    int *i, j;
    float *notas;
    char *nome;
    //coloque na variável *i o valor 10 de duas formas distintas ...
    // j = 10;
    // i = &j;
    // printf("i= %p, *i= %d, j= %d\n", i, *i, j);
    // ---
    i = &j;
    *i = 10;
    printf("i= %p, *i= %d, j= %d\n", i, *i, j);
    //carregue na variável ’notas’ 5 valores distintos de notas ...
    // notas = (float *)malloc(5 * sizeof(float));
    // // notas = realloc(notas, 5 * sizeof(float));
    // for (int i = 0; i < 5; i++) {
    //     scanf("%f", notas+i);
    // }
    // for (int i = 0; i < 5; i++) {
    //     printf("%.1f ", *(notas+i));
    // }
    // puts("");
    //carregue na variável ’nome’ o seu primeiro e ultimo nome
    // usando somente letras minúsculas ...
    nome = (char *)malloc(16 * sizeof(char));
    strcpy(nome, "gabriel araujo");
    //altere as letras iniciais do seu nome para letras maiúsculas ...
    *nome = toupper(*nome);
    for (int l = 0; *(nome+l) != '\0'; l++) {
        if ((int)*(nome+l) == (int)' ')
            *(nome+l+1) = toupper(*(nome+l+1));
    }

    printf("Meu nome é %s\n", nome);
    return 0;
}