#include <stdio.h>

int contaVogalVetor(char s[]);
int contaVogalPonteiro(char s[]);

int main()

{

    char s[] = "Gabriel de Araujo";

    int vogais = contaVogalPonteiro(s);

    printf("A string %s possui %d vogais\n", s, vogais);

    return 0;

}

int contaVogalVetor(char s[]){
    int vogais = 0;
    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == 'a' || 
            s[i] == 'A' ||
            s[i] == 'e' ||
            s[i] == 'E' ||
            s[i] == 'i' ||
            s[i] == 'I' ||
            s[i] == 'o' ||
            s[i] == 'O' ||
            s[i] == 'u' ||
            s[i] == 'U' ){

                vogais++;
            }

    return vogais;
    }
}

int contaVogalPonteiro(char *s) {

    int vogais = 0;
    for (int i = 0; *(s + i) != '\0'; i++) {

        if (*(s + i) == 'a' || 
            *(s + i) == 'A' ||
            *(s + i) == 'e' ||
            *(s + i) == 'E' ||
            *(s + i) == 'i' ||
            *(s + i) == 'I' ||
            *(s + i) == 'o' ||
            *(s + i) == 'O' ||
            *(s + i) == 'u' ||
            *(s + i) == 'U' ) {

                vogais++;
            }

    }
    return vogais;
}

