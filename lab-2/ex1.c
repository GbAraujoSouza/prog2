#include <stdio.h>
void misterio (char *n);
int main (void)
{
    char nome [41];
    fgets(nome, 41, stdin);
    misterio(nome);
    return 0;
}
void misterio (char *n) {
    while (*n != ' '){
        if (*n == '\0'){
            break;
        }
        n++;
    }
    puts(n);
}