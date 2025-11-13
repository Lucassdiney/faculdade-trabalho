#include <stdio.h>

int main() {
    int colunas = 10;
    int linhas = 10;

    int tabuleiro[10][10] = {0};

    //Navio 01 Vertical

    int navio1_y = 7; // coluna
    int navio1_y_inicio = 0; //onde ele começa na coluna!

    for (int i = 0; i < 3; i++) {
        tabuleiro[navio1_y_inicio + i][navio1_y] = 1;
    }

    //Navio 02 Horizontal

    int navio2_x = 3; //Linha
    int navio2_x_inicio = 0; //onde ele começa na linha

    for (int j = 0; j < 4; j++) {
        tabuleiro[navio2_x][navio2_x_inicio + j] = 2;
    }

    //Navio 03 Diagonal Descendo

    int navio3_y_inicio = 4; //onde ele começa no eixo X!
    int navio3_x_inicio = 6; //onde ele começa no eixo Y!

    for (int k = 0; k < 2; k++) {
        tabuleiro[navio3_y_inicio + k][navio3_x_inicio + k] = 3;
    }

    //Navio 04 Diagonal Subindo

    int navio4_y_inicio = 5; //onde ele começa no eixo X!
    int navio4_x_inicio = 3; //onde ele começa no eixo Y!

    for (int l = 0; l < 1; l++) {
        tabuleiro[navio4_y_inicio + l][navio4_x_inicio - l] = 3;
    }


    printf("* Coordenadas dos Navios *\n");

    /*Aqui está escrito onde está localizados os navios (Coluna (Y), Linha(X) )*/

    printf("Navio 1 (Vertical):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d -> (%d, %d)\n", i + 1, navio1_y_inicio + i, navio1_y);
    }

    printf("\nNavio 2 (Horizontal):\n");
    for (int j = 0; j < 4; j++) {
        printf("Parte %d -> (%d, %d)\n", j + 1, navio2_x_inicio + j, navio2_x);
    }

    printf("\nNavio 3 (Diagonal):\n");
    for (int k = 0; k < 3; k++) {
        printf("Parte %d -> (%d, %d)\n", k + 1, navio3_y_inicio + k, navio3_x_inicio - k);
    }

    printf("\nNavio 4 (Diagonal):\n");
    for (int l = 0; l < 3; l++) {
        printf("Parte %d -> (%d, %d)\n", l + 1, navio4_y_inicio + 1, navio4_x_inicio - 1);
    }

    printf("\n* Tabuleiro Visual *\n\n");

    /*Nesse laço, ele percorre as linhas e colunas.
    Se o resultado for diferente de 0 ele imprime N de Navio.*/

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {

                /*N para navio e ~ para Mar*/
                printf(" ~ ");
            } else {
                printf(" N ");
            }
        }
        printf("\n");
    }

    return 0;
}
