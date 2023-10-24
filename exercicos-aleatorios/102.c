#include <stdio.h>

typedef struct {
  char nome[50];
  float renda;
  int nascimento;
} Tcliente;

void leCliente(Tcliente* cliente) {
  scanf("%s", cliente->nome);
  scanf("%f", cliente->renda);
  scanf("%i", cliente->nascimento);
}

void printCliente(Tcliente* cliente) {
  printf("nome: %s\n", cliente->nome);
  printf("renda: %.2f", cliente->renda);
  printf("nascimento: %i", cliente->nascimento);
}

int main ()
{
  printf ("Hello World");

  return 0;
}