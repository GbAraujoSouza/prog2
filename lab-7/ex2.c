#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef struct {
    char nome[50];
    int tempoChegada;
    int produtos;
} REGISTRO;
typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;
typedef struct {
    PONT inicio;
    PONT fim;
} FILA;
void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}
int tamanho(FILA* f) {
    PONT end = f->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
    end = end->prox; }
    return tam; }

bool inserirNaFila(FILA* f,REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = NULL;
    if (f->inicio==NULL) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    return true;
}
bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio==NULL) return false;
    *reg = f->inicio->reg;
    PONT apagar = f->inicio;
    f->inicio = f->inicio->prox;
    free(apagar);
    if (f->inicio == NULL) f->fim = NULL;
    return true; }

void reinicializarFila(FILA* f) {
    PONT end = f->inicio;
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    f->inicio = NULL;
    f->fim = NULL;
}

int main() {

    int rapidez, numClientes;
    scanf("%d", &rapidez);
    scanf("%d", &numClientes);

    FILA fila;
    inicializarFila(&fila);

    for (int i = 0; i < numClientes; i++) {
        REGISTRO pessoa;
        scanf("%s %i %i", pessoa.nome, &pessoa.tempoChegada, &pessoa.produtos);

        inserirNaFila(&fila, pessoa);
    }

    int tempo = 0;
    for (int i = 0; tamanho(&fila) > 0; i++) {
        REGISTRO cliente;
        excluirDaFila(&fila, &cliente);
        if (i == 0) {
            tempo += cliente.produtos * rapidez + 10 + cliente.tempoChegada;
        } else {
            if (tempo < cliente.tempoChegada) {
                tempo += (cliente.tempoChegada - tempo);
            }
            tempo += cliente.produtos * rapidez + 10;
        }
        

        printf("%s %d %d\n", cliente.nome, cliente.tempoChegada, tempo);
    }

    return 0;
}