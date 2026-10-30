#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_NOME 31

int Validar_letra(char nome[]) {

    if (isdigit(nome[0])) {
        return 1;
    }
    int tamanho = strlen(nome);
    if (tamanho > MAX_NOME) {return 1;}
    for(int i = 0; i < tamanho; i++) {
        if(!isalnum(nome[i]) && nome[i] != '_') { // espaços, quebra de linha ou especial
            return 1;
        }
    }

    return 0;
}

int Validar_reserva(char nome[]) {

    const char *palavrasReservadas[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long",
        "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "_Boll", "_Complex",
        "_Imaginary", "asm",
    };

    int total = sizeof(palavrasReservadas) / sizeof(palavrasReservadas[0]); // tamanho manual

    for(int i = 0; i < total; i++) {
        if(strcmp(nome, palavrasReservadas[i]) == 0) {
            return 1;
        }
    }

    return 0; 
}

int main () {

    char nome[MAX_NOME];
    int ok = 1;

    int testes;
    printf("Digite a quantidade de testes:");
    scanf("%d", &testes);
    getchar();

    while (testes!=0) {

    do {
        printf(":\n");
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        ok = Validar_letra(nome);
        if(!ok) {
            ok = Validar_reserva(nome);
        }

    } while(ok);

    if(!ok) {
        printf("O nome da sua variavel eh valido! Parabens!");
    }

    testes--;
    }

    return 0;
}
