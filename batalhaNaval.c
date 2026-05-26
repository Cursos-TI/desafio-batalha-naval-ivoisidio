#include <stdio.h>

int main() {
    
    // ==================== DECLARAÇÃO DO TABULEIRO ====================
    int tabuleiro[10][10];  // Tabuleiro 10x10

    // Inicializa todo o tabuleiro com 0 (água)
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==================== POSICIONAMENTO DOS NAVIOS ====================
    
    // Navio 1 - Horizontal (3 casas) na linha 2, começando na coluna 3
    int navio1[3] = {3, 4, 5};           // colunas
    int linhaNavio1 = 2;
    
    for(int i = 0; i < 3; i++) {
        tabuleiro[linhaNavio1][navio1[i]] = 3;
    }

    // Navio 2 - Vertical (3 casas) na coluna 7, começando na linha 4
    int navio2[3] = {4, 5, 6};           // linhas
    int colunaNavio2 = 7;
    
    for(int i = 0; i < 3; i++) {
        tabuleiro[navio2[i]][colunaNavio2] = 3;
    }

    // ==================== EXIBIÇÃO DO TABULEIRO ====================
    printf("=== BATALHA NAVAL - TABULEIRO 10x10 ===\n\n");
    printf("   0  1  2  3  4  5  6  7  8  9\n");
    printf("   ----------------------------\n");

    for(int i = 0; i < 10; i++) {
        printf("%d |", i);  // Número da linha
        
        for(int j = 0; j < 10; j++) {
            if(tabuleiro[i][j] == 3)
                printf(" 3 ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Navio\n");

    // Informações dos navios
    printf("\nNavios posicionados:\n");
    printf("- Navio Horizontal: Linha %d, Colunas 3,4,5\n", linhaNavio1);
    printf("- Navio Vertical:   Coluna %d, Linhas 4,5,6\n", colunaNavio2);

    return 0;
}