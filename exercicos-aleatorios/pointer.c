#include <stdio.h>

int main() {

    int salary;
    int* pSalary;

    scanf("%d", &salary);
    pSalary = &salary;

    printf("Original Salary: %d\n", *pSalary);

    *pSalary *= 2;

    printf("New Salary: %d\n", *pSalary);

    return 0;
}