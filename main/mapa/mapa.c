#include "../config/config.h"

void carregar_mapa(Jogador_t *jogadorPrincipal) {
    mapa.fase_atual = 1;
    char nome_mapa[20] = "\0";

    snprintf(nome_mapa, 20, "mapas/mapa%d.txt", mapa.fase_atual);

    FILE *file = fopen(nome_mapa, "r");

    if (!file) {
        printf("Falha no carregamento do mapa: %s\n", nome_mapa);
        return;
    }

    for (int y = 0; y < LINHAS_MAPA; y++) {
        for (int x = 0; x < COLUNAS_MAPA; x++) {
            char ch = fgetc(file);
            if (ch == EOF) {
                break;
            } else {
                mapa.tiles[y][x] = ch;

                // Se encontrar 'J', define a posição inicial do jogador
                if (ch == 'J') {
                    jogadorPrincipal->posicaoX = x * LADO;
                    jogadorPrincipal->posicaoY = y * LADO;
                    printf("Posição inicial do jogador definida em X: %d, Y: %d\n", jogadorPrincipal->posicaoX, jogadorPrincipal->posicaoY); // Debug
                }
            }
        }
        fgetc(file); // Pular o caractere de nova linha
    }

    fclose(file);

    // Carrega as texturas do mapa
    mapa.texturas.wallTexture = LoadTexture("texturas/wall.png");
    mapa.texturas.groundTexture = LoadTexture("texturas/ground.png");
    mapa.texturas.grassTexture = LoadTexture("texturas/grass.png");
    mapa.texturas.enemyTexture = LoadTexture("texturas/inimigo_infmon.png");
}

void desenhador_mapa() {
    for (int y = 0; y < LINHAS_MAPA; y++) {
        for (int x = 0; x < COLUNAS_MAPA; x++) {
            switch (mapa.tiles[y][x]) { 
                case 'A':
                    DrawTexture(mapa.texturas.wallTexture, x * mapa.texturas.wallTexture.width, y * mapa.texturas.wallTexture.height, WHITE);
                    break;
                case ' ':
                    DrawTexture(mapa.texturas.groundTexture, x * mapa.texturas.groundTexture.width, y * mapa.texturas.groundTexture.height, WHITE);
                    break;
                case 'J':
                    // Aqui só desenhamos o chão, o jogador é desenhado separadamente
                    DrawTexture(mapa.texturas.groundTexture, x * mapa.texturas.groundTexture.width, y * mapa.texturas.groundTexture.height, WHITE);
                    break;
                case 'P':
                    DrawTexture(mapa.texturas.wallTexture, x * mapa.texturas.wallTexture.width, y * mapa.texturas.wallTexture.height, WHITE);
                    break;
                case 'G':
                    DrawTexture(mapa.texturas.grassTexture, x * mapa.texturas.grassTexture.width, y * mapa.texturas.grassTexture.height, WHITE);
                    break;
                case 'E':
                    DrawTexture(mapa.texturas.groundTexture, x * mapa.texturas.groundTexture.width, y * mapa.texturas.groundTexture.height, WHITE);
                    DrawTexture(mapa.texturas.enemyTexture, x * mapa.texturas.enemyTexture.width, y * mapa.texturas.enemyTexture.height, WHITE);
                    break;
                default:
                    break;
            }
        }
    }
}