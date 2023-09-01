#include <stdio.h>
#include <stdlib.h>

void atualizaHorario(int minutos, int *horario);

int main() {

    int minutosPasados;
    scanf("%d", &minutosPasados);

    int *horario = (int *)calloc(2, sizeof(int));
    atualizaHorario(minutosPasados, horario);

    printf("horario -> %0d:%0d\n", *horario, *(horario+1));

    free(horario);

    return 0;
}

void atualizaHorario(int minutosPassados, int *horario) {
    int horas = minutosPassados / 60;
    int minutos = minutosPassados % 60;

    *horario = horas;
    *(horario+1) = minutos;
}