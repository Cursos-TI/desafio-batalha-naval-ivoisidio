#include <stdio.h>

int main() {
    
    // ==================== DECLARAÇÃO DO TABULEIRO ====================
    int tabuleiro[10][10];

    // Inicializa todo o tabuleiro com 0 (água)
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==================== POSICIONAMENTO DOS 4 NAVIOS ====================
    
    // Navio 1 - Horizontal (3 casas)
    int linha1 = 2;
    int colunas1[3] = {3, 4, 5};
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha1][colunas1[i]] = 3;
    }

    // Navio 2 - Vertical (3 casas)
    int coluna2 = 7;
    int linhas2[3] = {4, 5, 6};
    for(int i = 0; i < 3; i++) {
        tabuleiro[linhas2[i]][coluna2] = 3;
    }

    // Navio 3 - Diagonal Principal (↘)
    int linha3 = 1;
    int coluna3 = 1;
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha3 + i][coluna3 + i] = 3;
    }

    // Navio 4 - Diagonal Secundária (↙)
    int linha4 = 3;
    int coluna4 = 8;
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha4 + i][coluna4 - i] = 3;
    }

    // ==================== EXIBIÇÃO DO TABULEIRO ====================
    printf("=== BATALHA NAVAL - TABULEIRO 10x10 ===\n\n");
    printf("    0  1  2  3  4  5  6  7  8  9\n");
    printf("   ----------------------------\n");

    for(int i = 0; i < 10; i++) {
        printf("%2d |", i);
        
        for(int j = 0; j < 10; j++) {
            if(tabuleiro[i][j] == 3)
                printf(" 3 ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }

    printf("\nLegenda:  0 = Água    3 = Navio\n");

    // Informações dos navios
    printf("\n=== NAVIOS POSICIONADOS ===\n");
    printf("1. Horizontal : Linha %d, Colunas 3-5\n", linha1);
    printf("2. Vertical   : Coluna %d, Linhas 4-6\n", coluna2);
    printf("3. Diagonal   : Posição inicial (%d,%d) -> (%d,%d)\n", 
           linha3, coluna3, linha3+2, coluna3+2);
    printf("4. Diagonal   : Posição inicial (%d,%d) -> (%d,%d)\n", 
           linha4, coluna4, linha4+2, coluna4-2);

    return 0;
}