#include <stdio.h>

int main() {

    int tabuleiro[10][10] = {0};

    // ------------------ NAVIOS ------------------
    int navio1_y = 7;
    int navio1_y_inicio = 0;
    for (int i = 0; i < 3; i++)
        tabuleiro[navio1_y_inicio + i][navio1_y] = 1;

    int navio2_x = 3;
    int navio2_x_inicio = 0;
    for (int j = 0; j < 4; j++)
        tabuleiro[navio2_x][navio2_x_inicio + j] = 2;

    int navio3_y_inicio = 4;
    int navio3_x_inicio = 6;
    for (int k = 0; k < 2; k++)
        tabuleiro[navio3_y_inicio + k][navio3_x_inicio + k] = 3;

    int navio4_y_inicio = 5;
    int navio4_x_inicio = 3;
    for (int l = 0; l < 1; l++)
        tabuleiro[navio4_y_inicio + l][navio4_x_inicio - l] = 4;

    // ------------------ HABILIDADES ------------------
    int CRUZ[3][5] = {
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0}
    };

    int OCTAEDRO[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };

    int CONE[3][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1}
    };

    int escolha;
    int x, y;

    // Escolha válida
    do {
        printf("Escolha a habilidade:\n");
        printf("1 - Cruz\n");
        printf("2 - Octaedro\n");
        printf("3 - Cone\n");
        printf("Digite: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 3)
            printf("\n Escolha invalida! Digite apenas 1, 2 ou 3.\n\n");

    } while (escolha < 1 || escolha > 3);

    // Posição do ataque
    printf("\nPosicao X (linha): ");
    scanf("%d", &x);

    printf("Posicao Y (coluna): ");
    scanf("%d", &y);

    // Ponteiro da habilidade
    int (*habilidade)[5];
    if (escolha == 1) habilidade = CRUZ;
    else if (escolha == 2) habilidade = OCTAEDRO;
    else habilidade = CONE;

    // Flags dos navios
    int navio1_atingido = 0;
    int navio2_atingido = 0;
    int navio3_atingido = 0;
    int navio4_atingido = 0;

    // Vetor para armazenar locais atingidos
    int atingidos_x[30], atingidos_y[30];
    int total_atingidos = 0;

    // Aplicar habilidade
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {

                int nx = x + i;
                int ny = y + j;

                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {

                    int anterior = tabuleiro[nx][ny];

                    if (anterior == 1) navio1_atingido = 1;
                    if (anterior == 2) navio2_atingido = 1;
                    if (anterior == 3) navio3_atingido = 1;
                    if (anterior == 4) navio4_atingido = 1;

                    // registra local atingido
                    atingidos_x[total_atingidos] = nx;
                    atingidos_y[total_atingidos] = ny;
                    total_atingidos++;

                    tabuleiro[nx][ny] = 9;
                }
            }
        }
    }


    // Tabuleiro final
    printf("\nTABULEIRO FINAL:\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            if (tabuleiro[i][j] == 0) printf(" 0 ");
            else if (tabuleiro[i][j] == 1) printf(" n ");
            else if (tabuleiro[i][j] == 2) printf(" n ");
            else if (tabuleiro[i][j] == 3) printf(" n ");
            else if (tabuleiro[i][j] == 4) printf(" N ");
            else if (tabuleiro[i][j] == 9) printf(" 1 ");
        }
        printf("\n");
    }

    printf("\nRESULTADO DO ATAQUE:\n");

    if (navio1_atingido) printf("Navio 1 (vertical) foi atingido!\n");
    if (navio2_atingido) printf("Navio 2 (horizontal) foi atingido!\n");
    if (navio3_atingido) printf("Navio 3 (diagonal descendo) foi atingido!\n");
    if (navio4_atingido) printf("Navio 4 (diagonal subindo) foi atingido!\n");

    if (!navio1_atingido && !navio2_atingido && !navio3_atingido && !navio4_atingido)
        printf("Nenhum navio foi atingido.\n");

    // Mostrar locais atingidos
    printf("\nLocais atingidos pela habilidade:\n");

    for (int i = 0; i < total_atingidos; i++) {
        printf("(%d, %d)\n", atingidos_x[i], atingidos_y[i]);
    }

    // Perguntar se deseja jogar novamente
    char jogarNovamente;
    printf("\nDeseja jogar novamente? (s/n): ");
    scanf(" %c", &jogarNovamente);

    if (jogarNovamente == 's' || jogarNovamente == 'S')
        return main();

    printf("Jogo encerrado.\n");

    return 0;
}
