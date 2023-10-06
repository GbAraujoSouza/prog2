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
int calcula(int n1, int n2, char operacao);


int main(int argc, char* argv[]) {

    if (argc != 2){
        puts("Erro! Utilize <nome do programa> <nome do arquivo>");
        return -1;
    }

    FILE* pArquivo;
    char nomeArquivo[100];
    strcpy(nomeArquivo, argv[1]);
    if (!(pArquivo = fopen(nomeArquivo, "r"))) {
        puts("Erro ao abrir o arquivo");
        return -1;
    }

    PILHA p;
    inicializarPilha(&p);


    while(!feof(pArquivo)) {
        // pegar caractere do arquivo
        char c = fgetc(pArquivo);

        // se inteiro, armazenar numero na pilha
        if (isdigit(c)) {
            REGISTRO reg;
            reg.chave = ((int)c) - 48;
            inserirElemPilha(&p, reg);
        } else if (ispunct(c)){
            // se caractere de operação, excluir dois últimos,
            // fazer operação,
            // armazenar resultado na pilha
            REGISTRO n1, n2;
            int resultado;
            excluirElemPilha(&p, &n2);
            excluirElemPilha(&p, &n1);
            resultado = calcula(n1.chave, n2.chave, c);
            REGISTRO regResultado;
            regResultado.chave = resultado;
            inserirElemPilha(&p, regResultado);

            printf("%d %c %d = %d\n", n1.chave, c, n2.chave, resultado);
        }
        
    }

    printf("Resultado: %d\n", p.topo->reg.chave);

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
int calcula(int n1, int n2, char operacao) {
    switch (operacao) {
    case '+':
        return n1 + n2;
        break;
    case '-':
        return n1 - n2;
        break;
    case '*':
        return n1 * n2;
        break;
    case '/':
        return n1 / n2;
    break;
    
    }
}