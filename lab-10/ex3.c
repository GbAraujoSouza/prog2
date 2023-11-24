#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;
typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

void inicializarLista(LISTA* l){
    l->inicio = NULL;
}

int tamanho(LISTA* l) {
    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA* l) {
    PONT end = l->inicio;
    printf("Lista: \" ");
    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool insere(LISTA* l, REGISTRO reg) {
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    ELEMENTO* p = l->inicio;
    if (tamanho(l) == 0) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else if (tamanho(l) == 1) {
        if (p->reg.chave > novo->reg.chave) {
            novo->prox = l->inicio;
            l->inicio = novo;
        } else {
            p->prox = novo;
            novo->prox = NULL;
        }
    } else {
        while(p->prox != NULL && p->prox->reg.chave < novo->reg.chave) {
            p = p->prox;
        }
        novo->prox = p->prox;
        p->prox = novo;
    }
}

bool exclui(LISTA* l, int pos) {
    if (pos<0 || pos>tamanho(l)-1) return false;
    int i;
    ELEMENTO* p;
    ELEMENTO* apagar;
    if (pos == 0) {
        apagar = l->inicio;
        l->inicio = apagar->prox;
    }else {
        p = l->inicio;
        for (i=0;i<pos-1;i++) p = p->prox;
            apagar = p->prox;
            p->prox = apagar->prox; }
            free(apagar);
            return true;
}

void reinicializarLista(LISTA* l) {
    PONT end = l->inicio;
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

int main() {

    LISTA li;
    inicializarLista(&li);

    int tam;
    printf("tamanho do vetor: ");
    scanf("%d", &tam);
    for (int i = 0; i < tam; i++)
    {
        REGISTRO r;
        scanf("%d", &r.chave);
        insere(&li, r);

        exibirLista(&li);
    }
    
    

    return 0;
}