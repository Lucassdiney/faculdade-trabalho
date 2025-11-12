#include <stdio.h>

int main() {
    int colunas = 5;
    int linhas = 5;

    int tabuleiro[5][5] = {0};

    /*Navio Vertical*/

    int navio1_y = 4; // Coluna
    int navio1_y_inicio = 0; //onde ele começa!

    for (int i = 0; i < 3; i++) {
        tabuleiro[navio1_y_inicio + i][navio1_y] = 1;
    }

    /*Navio Horizontal*/

    int navio2_x = 3;// Onde ele fica!
    int navio2_x_inicio = 0; //onde ele começa!

    for (int j = 0; j < 4; j++) {
        tabuleiro[navio2_x][navio2_x_inicio + j] = 2;
    }

    printf("* Coordenadas dos Navios *\n");

    /*Aqui está escrito onde está localizados os navios (Coluna (Y), Linha(X) )*/

    printf("Navio 1 (Vertical):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d -> (%d, %d)\n", i + 1, navio1_y_inicio + i, navio1_y);
    }

    printf("\nNavio 2 (Horizontal):\n");
    for (int j = 0; j < 4; j++) {
        printf("Parte %d -> (%d, %d)\n", j + 1, navio2_x, navio2_x_inicio + j);
    }

    printf("\n* Tabuleiro Visual *\n\n");

    /*Nesse laço, ele percorre as linhas e colunas.
    Se o resultado for diferente de 0 ele imprime N de Navio.*/

    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
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
