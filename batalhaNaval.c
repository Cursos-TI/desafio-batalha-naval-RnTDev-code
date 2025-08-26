#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 1
#define AREA_NORMAL 0

void imprimirTabuleiro(int tamanho, int tabuleiro[tamanho][tamanho]);
void gerarHabilidadeCone(int tamanho, int matriz[tamanho][tamanho]);
void gerarHabilidadeCruz(int tamanho, int matriz[tamanho][tamanho]);
void gerarHabilidadeOctaedro(int tamanho, int matriz[tamanho][tamanho]);

int main() {
    printf("--- Desafio Batalha Naval: Nivel Mestre --- \n\n");
    printf("--- Tabuleiro Principal do Jogo --- \n");

    int tabuleiroPrincipal[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    for (int j = 1; j <= 3; j++) {
        tabuleiroPrincipal[1][j] = NAVIO;
    }
    for (int i = 4; i <= 6; i++) {
        tabuleiroPrincipal[i][8] = NAVIO;
    }
    for (int i = 3; i <= 5; i++) {
        tabuleiroPrincipal[i][i] = NAVIO;
    }
    for (int i = 0; i <= 2; i++) {
        tabuleiroPrincipal[7 + i][2 - i] = NAVIO;
    }

    imprimirTabuleiro(TAMANHO_TABULEIRO, tabuleiroPrincipal);

    int matrizCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matrizCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matrizOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    printf("\n--- Habilidade Especial: Cone --- \n");
    gerarHabilidadeCone(TAMANHO_HABILIDADE, matrizCone);
    imprimirTabuleiro(TAMANHO_HABILIDADE, matrizCone);

    printf("\n--- Habilidade Especial: Cruz --- \n");
    gerarHabilidadeCruz(TAMANHO_HABILIDADE, matrizCruz);
    imprimirTabuleiro(TAMANHO_HABILIDADE, matrizCruz);

    printf("\n--- Habilidade Especial: Octaedro --- \n");
    gerarHabilidadeOctaedro(TAMANHO_HABILIDADE, matrizOctaedro);
    imprimirTabuleiro(TAMANHO_HABILIDADE, matrizOctaedro);

    return 0;
}

void imprimirTabuleiro(int tamanho, int tabuleiro[tamanho][tamanho]) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void gerarHabilidadeCone(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                matriz[i][j] = AREA_AFETADA;
            } else {
                matriz[i][j] = AREA_NORMAL;
            }
        }
    }
}

void gerarHabilidadeCruz(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = AREA_AFETADA;
            } else {
                matriz[i][j] = AREA_NORMAL;
            }
        }
    }
}

void gerarHabilidadeOctaedro(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int distancia = (i > centro ? i - centro : centro - i) + (j > centro ? j - centro : centro - j);
            if (distancia <= centro) {
                matriz[i][j] = AREA_AFETADA;
            } else {
                matriz[i][j] = AREA_NORMAL;
            }
        }
    }
}
