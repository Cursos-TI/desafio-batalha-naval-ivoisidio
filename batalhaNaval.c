#include <stdio.h>

int main() {
    
    // ==================== TABULEIRO 10x10 ====================
    int tabuleiro[10][10];

    // Inicializa com 0 (água)
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ==================== POSICIONAMENTO DOS 4 NAVIOS ====================
    
    // Navio 1 - Horizontal
    int linha1 = 2;
    int col1[3] = {3, 4, 5};
    for(int i = 0; i < 3; i++) tabuleiro[linha1][col1[i]] = 3;

    // Navio 2 - Vertical
    int col2 = 7;
    int lin2[3] = {4, 5, 6};
    for(int i = 0; i < 3; i++) tabuleiro[lin2[i]][col2] = 3;

    // Navio 3 - Diagonal Principal (↘)
    for(int i = 0; i < 3; i++) tabuleiro[1 + i][1 + i] = 3;

    // Navio 4 - Diagonal Secundária (↙)
    for(int i = 0; i < 3; i++) tabuleiro[3 + i][8 - i] = 3;

    // ==================== HABILIDADES ESPECIAIS ====================

    // 1. Cone (apontando para baixo)
    int origemConeL = 1, origemConeC = 4;
    tabuleiro[origemConeL][origemConeC] = 5;           // topo
    tabuleiro[origemConeL+1][origemConeC-1] = 5;
    tabuleiro[origemConeL+1][origemConeC] = 5;
    tabuleiro[origemConeL+1][origemConeC+1] = 5;
    tabuleiro[origemConeL+2][origemConeC-2] = 5;
    tabuleiro[origemConeL+2][origemConeC-1] = 5;
    tabuleiro[origemConeL+2][origemConeC] = 5;
    tabuleiro[origemConeL+2][origemConeC+1] = 5;
    tabuleiro[origemConeL+2][origemConeC+2] = 5;

    // 2. Cruz
    int origemCruzL = 5, origemCruzC = 2;
    // Horizontal
    for(int j = origemCruzC-2; j <= origemCruzC+2; j++) {
        if(j >= 0 && j < 10) tabuleiro[origemCruzL][j] = 5;
    }
    // Vertical
    for(int i = origemCruzL-2; i <= origemCruzL+2; i++) {
        if(i >= 0 && i < 10) tabuleiro[i][origemCruzC] = 5;
    }

    // 3. Octaedro (Losango)
    int origemOctL = 7, origemOctC = 6;
    tabuleiro[origemOctL][origemOctC] = 5;           // centro
    tabuleiro[origemOctL-1][origemOctC] = 5;
    tabuleiro[origemOctL+1][origemOctC] = 5;
    tabuleiro[origemOctL][origemOctC-1] = 5;
    tabuleiro[origemOctL][origemOctC+1] = 5;

    // ==================== EXIBIÇÃO DO TABULEIRO ====================
    printf("=== BATALHA NAVAL - HABILIDADES ESPECIAIS ===\n\n");
    printf("    0  1  2  3  4  5  6  7  8  9\n");
    printf("   ----------------------------\n");

    for(int i = 0; i < 10; i++) {
        printf("%2d |", i);
        for(int j = 0; j < 10; j++) {
            if(tabuleiro[i][j] == 5)
                printf(" 5 ");
            else if(tabuleiro[i][j] == 3)
                printf(" 3 ");
            else
                printf(" 0 ");
        }
        printf("\n");
    }

    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Navio\n");
    printf("5 = Área afetada por habilidade\n");

    // Informações
    printf("\n=== HABILIDADES ATIVADAS ===\n");
    printf("Cone     -> Origem (%d,%d)\n", origemConeL, origemConeC);
    printf("Cruz     -> Origem (%d,%d)\n", origemCruzL, origemCruzC);
    printf("Octaedro -> Origem (%d,%d)\n", origemOctL, origemOctC);

    return 0;
}