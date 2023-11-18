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

bool insere(LISTA* l, REGISTRO reg, int pos) {
    if (pos<0 || pos>tamanho(l)) return false;
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    int i;
    ELEMENTO* p;
    if (pos == 0){
        novo->prox = l->inicio;
        l->inicio = novo;
    }else{
        p = l->inicio;
        for (i = 0; i < pos - 1; i++) p = p->prox;
        novo->prox = p->prox;
        p->prox = novo;
    }
    return true;
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

void concatenaListas(LISTA* l1, LISTA* l2) {
    PONT end = l1->inicio;
    while (end->prox != NULL){
        end = end->prox;
    }
    end->prox = l2->inicio;
}

bool iguaisListas(LISTA* l1, LISTA* l2) {
    if (tamanho(l1) != tamanho(l2))
        return false;

    PONT pLista1 = l1->inicio;
    PONT pLista2 = l2->inicio;

    while (pLista1 != NULL) {
        if (pLista1->reg.chave != pLista2->reg.chave) {
            return false;
        }
        pLista1 = pLista1->prox;
        pLista2 = pLista2->prox;
    }
    return true;
}

int main () {

    LISTA l1, l2;
    inicializarLista(&l1);
    inicializarLista(&l2);

    // preencher lista 1
    printf("Lista 1 (tam 5): ");
    for (int i = 0; i < 5; i++) {
        REGISTRO r;
        scanf("%d", &r.chave);
        insere(&l1, r, i);
    }
    // preencher lista 2
    printf("Lista 2 (tam 5): ");
    for (int i = 0; i < 5; i++) {
        REGISTRO r;
        scanf("%d", &r.chave);
        insere(&l2, r, i);
    }

    exibirLista(&l1);
    exibirLista(&l2);

    // Exemplo Concatenar:
    // concatenaListas(&l1, &l2);
    // puts("Nova lista concatenada: ");
    // exibirLista(&l1);

    // Exemplo listas iguais
    if (iguaisListas(&l1, &l2)) {
        puts("Listas iguais");
    } else {
        puts("Listas diferentes");
    }

    reinicializarLista(&l1);
    reinicializarLista(&l2);

    return 0;
}