#include "../config/config.h"

void LoadMap(Mapa_t *mapa) {
    mapa->fase_atual = 1;
    char nome_mapa[20] = "\0";

    snprintf(nome_mapa, 20, "mapas/mapa%d.txt", mapa->fase_atual);

    FILE *file = fopen(nome_mapa, "r");

    if (!file) {
        printf("Falha no carregamento do mapa: %s\n", nome_mapa);
        return;
    }

    for (int y = 0; y < LINHAS_MAPA; y++) {
        for (int x = 0; x < COLUNAS_MAPA; x++) {
            fscanf(file, "%c", &mapa->tiles[x][y]);
        }
    }

    fclose(file);

    mapa->texturas.wallTexture = LoadTexture("texturas/wall.png");
    mapa->texturas.groundTexture = LoadTexture("texturas/ground.png");
    mapa->texturas.playerTexture = LoadTexture("texturas/player.png");
    mapa->texturas.grassTexture = LoadTexture("texturas/grass.png");
}

void DrawMap(Mapa_t *mapa) {
    for (int y = 0; y < LINHAS_MAPA; y++) {
        for (int x = 0; x < COLUNAS_MAPA; x++) {
            switch (mapa->tiles[x][y]) {
                case 'A':
                    DrawTexture(mapa->texturas.wallTexture, x * mapa->texturas.wallTexture.width, y * mapa->texturas.wallTexture.height, WHITE);
                    break;
                case '\0':
                    DrawTexture(mapa->texturas.groundTexture, x * mapa->texturas.groundTexture.width, y * mapa->texturas.groundTexture.height, WHITE);
                    break;
                case 'J':
                    DrawTexture(mapa->texturas.playerTexture, x * mapa->texturas.playerTexture.width, y * mapa->texturas.playerTexture.height, WHITE);
                    break;
                case 'G':
                    DrawTexture(mapa->texturas.grassTexture, x * mapa->texturas.grassTexture.width, y * mapa->texturas.grassTexture.height, WHITE);
                    break;
                default:
                    break;
            }
            
        }
    }
}
