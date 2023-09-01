#include <stdio.h>

void alteraSalario (float *salario, float aumentoPercentual);

int main() {

    float salario, aumentoPercentual; 
    printf("Salario: R$"); 
    scanf("%f", &salario);
    printf("Aumento percentual (%%): ");
    scanf("%f",&aumentoPercentual);

    printf("Salario original: R$%.2f\n", salario);
    alteraSalario(&salario, aumentoPercentual);
    printf("Salario atualizado: R$%.2f\n", salario);

return 0;

}

void alteraSalario (float *salario, float aumentoPercentual) {

    *salario *= (aumentoPercentual / 100) + 1;

}