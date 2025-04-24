#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // Preenchendo a matriz com zeros
    for (int l = 0; l < 10; l++) {
        for (int a = 0; a < 10; a++) {
            tabuleiro[l][a] = 0;
        }
    }
    
    // Adicionando navio na horizontal
    int navio1X=2, navio1Y=3;

    for (int n1=0; n1<3; n1++) {
        tabuleiro[navio1Y][navio1X+n1] = 3;
    }

    // Adicionando navio na vertical
    int navio2X=7, navio2Y=4;

    for (int n2=0; n2<3; n2++) {
        tabuleiro[navio2Y+n2][navio2X] = 3;
    }

    // Mostrando a matriz no console
    printf("Tabuleiro:\n");
    for (int l = 0; l < 10; l++) {
        for (int a = 0; a < 10; a++) {
            printf("%d ", tabuleiro[l][a]);
        }
        printf("\n");
    }


    return 0;
}
