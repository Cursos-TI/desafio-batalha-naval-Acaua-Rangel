#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

int podeAdicionarHorizontal(int x, int y) {
    return (x >= 0 && x < COLUNAS && x+TAMANHO_NAVIO <= COLUNAS && y >= 0 && y < LINHAS);
}

int podeAdicionarVertical(int x, int y) {
    return (x >= 0 && x < COLUNAS && y >= 0 && y < LINHAS && y+TAMANHO_NAVIO <= LINHAS);
}

int podeAdicionarDiagonal(int x, int y) {
    return (x >= 0 && x < COLUNAS && x+TAMANHO_NAVIO <= COLUNAS && y >= 0 && y < LINHAS && y+TAMANHO_NAVIO <= LINHAS);
}

int main() {
    int tabuleiro[LINHAS][COLUNAS];
    int tabuleiro2[LINHAS][COLUNAS];

    // Preenchendo a matriz com zeros
    for (int l = 0; l < LINHAS; l++) {
        for (int a = 0; a < COLUNAS; a++) {
            tabuleiro[l][a] = 0;
            tabuleiro2[l][a] = 0;
        }
    }

    // Adicionando navio na horizontal
    int navio1X = 7, navio1Y = 0;
    if (podeAdicionarHorizontal(navio1X, navio1Y)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1Y][navio1X + i] = 3;
        }
    } else {
        printf("Erro: navio horizontal na posição (%d,%d) não cabe no tabuleiro.\n", navio1X, navio1Y);
        return 0;
    }

    // Adicionando navio na vertical
    int navio2X = 6, navio2Y = 3;
    if (podeAdicionarVertical(navio2X, navio2Y)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio2Y + i][navio2X] = 3;
        }
    } else {
        printf("Erro: navio vertical na posição (%d,%d) não cabe no tabuleiro.\n", navio2X, navio2Y);
        return 0;
    }

    // Adicionando navios na diagonal (descendo)
    int navio3X = 1, navio3Y = 5;
    if (podeAdicionarDiagonal(navio3X, navio3Y)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio3Y + i][navio3X + i] = 3;
        }
    } else {
        printf("Erro: navio diagonal na posição (%d,%d) não cabe no tabuleiro.\n", navio3X, navio3Y);
        return 0;
    }

    int navio4X = 6, navio4Y = 7;
    if (podeAdicionarDiagonal(navio4X, navio4Y)) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio4Y + i][navio4X + i] = 3;
        }
    } else {
        printf("Erro: navio diagonal na posição (%d,%d) não cabe no tabuleiro.\n", navio4X, navio4Y);
        return 0;
    }


    // ================= Geometria =================

    // Cone

    int cone_x = 3, cone_y = 6;

    for (int c = 2, tam = 5, p = 5; c >= 0; c--) {
        for (int h = 0; h < p; h++) {
            int padding = (tam-p)/2;
            tabuleiro[c+cone_y][padding+h+cone_x] = 1;
        }
        p-=2;
    }

    // Cruz

    int cruz_x = 2, cruz_y = 3;

    for (int c = 2, tam = 5; c >= 0; c--) {
        if (c==1) {
            for (int h = 0; h < tam; h++) {
                tabuleiro[c+cruz_y][h+cruz_x] = 1;
            }
        } else {
            tabuleiro[c+cruz_y][2+cruz_x] = 1;
        }
    }

    // Octaedro

    int octa_x = 0, octa_y = 0;

    for (int c = 2, tam = 5; c >= 0; c--) {
        if (c==1) {
            for (int h = 0; h < tam-2; h++) {
                tabuleiro[c+octa_y][h+octa_x+1] = 1;
            }
        } else {
            tabuleiro[c+octa_y][2+octa_x] = 1;
        }
    }

    // Mostrando a matriz no console
    printf("\nTabuleiro:\n");
    for (int l = 0; l < LINHAS; l++) {
        for (int a = 0; a < COLUNAS; a++) {
            printf("%d  ", tabuleiro[l][a]);
        }
        printf("\n");
    }

    return 0;
}
