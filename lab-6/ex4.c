#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    PONT topo;
} PILHA;

void inicializarPilha(PILHA* p);
int tamanho(PILHA* p);
bool estaVazia(PILHA* p);
void exibirPilha(PILHA* p);
bool inserirElemPilha(PILHA* p, REGISTRO reg);
bool excluirElemPilha(PILHA* p, REGISTRO* reg);
void reinicializarPilha(PILHA* p);
bool ehExpressaoValida(char expressao[]);
void inverteParenteses(REGISTRO* parenteses);

int main() {
    
    char expr[100];
    printf("Digite a expressão matemática: ");
    scanf("%s", expr);

    if (ehExpressaoValida(expr)) {
        puts("É expressao válida");
    }else {
        puts("Não é expressao válida");
    }
    return 0;
}

void inicializarPilha(PILHA* p) {
    p->topo = NULL;
}
int tamanho(PILHA* p) {
    PONT end = p->topo;
    int tam = 0;
    while (end != NULL) {
        tam++;
    end = end->prox; }
    return tam; 
}
bool estaVazia(PILHA* p) {
    if (p->topo == NULL)
        return true;
    return false;
}
void exibirPilha(PILHA* p) {
    PONT end = p->topo;
    printf("Pilha: \" ");
    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox; }
    printf("\"\n");
}

bool inserirElemPilha(PILHA* p, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}
bool excluirElemPilha(PILHA* p, REGISTRO* reg) {
    if ( p->topo == NULL) return false;
    *reg = p->topo->reg;
    PONT apagar = p->topo;
    p->topo = p->topo->prox;
    free(apagar);
return true;
}
void reinicializarPilha(PILHA* p) {
    PONT apagar;
    PONT posicao = p->topo;
    while (posicao != NULL) {
        apagar = posicao;
        posicao = posicao->prox;
        free(apagar);
    }
    p->topo = NULL;
}

bool ehExpressaoValida(char expressao[]) {
    PILHA p;
    inicializarPilha(&p);

    for (int i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') {
            REGISTRO parenteses;
            parenteses.chave = expressao[i];
            inserirElemPilha(&p, parenteses);
        } else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') {
            if (estaVazia(&p)) {
                return false;
            }

            REGISTRO c1, c2;
            excluirElemPilha(&p, &c1);
            inverteParenteses(&c1);
            excluirElemPilha(&p, &c2);
            if (c1.chave != c2.chave){
                return false;
            }
        }
    }
    return true;
}

void inverteParenteses(REGISTRO* parenteses) {
    if (parenteses->chave == '(') {
        parenteses->chave++;
    } else {
        parenteses->chave += 2;
    }
}