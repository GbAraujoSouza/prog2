#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct {
TIPOCHAVE chave;
    //outros campos...
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

void exibirFila(FILA* f) {
    PONT end = f->inicio;
    printf("Fila: \" ");
    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox; }
    printf("\"\n"); }
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

    FILA par, impar;
    inicializarFila(&par);
    inicializarFila(&impar);

    int num;
    scanf("%d", &num);
    while(num != 0) {
        REGISTRO n;
        n.chave = num;
        if (num % 2 == 0) {
            inserirNaFila(&par, n);
        } else {
            inserirNaFila(&impar, n);
        }
        scanf("%d", &num);
    }

    while (tamanho(&par) > 0 && tamanho(&impar) > 0) {
        REGISTRO nPar, nImpar;
        excluirDaFila(&par, &nPar);
        excluirDaFila(&impar, &nImpar);
        
        printf("%d ", nImpar.chave);
        printf("%d ", nPar.chave);
    }

    if (tamanho(&impar) > 0) {
        printf("%d\n", impar.inicio->reg.chave);
    }
    if(tamanho(&par) > 0) {
        printf("%d\n", par.inicio->reg.chave);
    }

    return 0;
}