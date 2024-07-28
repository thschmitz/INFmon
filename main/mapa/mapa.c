#include "../config/config.h"

void LoadMap(Mapa_t *mapa) {

    char nome_mapa[20] = "\0";

    snprintf(nome_mapa, 20, "mapas/mapa%d.txt", fase_atual);

    FILE *file = fopen(nome_mapa, "r");

    if (!file) {
        printf("Falha no carregamento do mapa: %s\n", nome_mapa);
        return;
    }

    for (int y = 0; y < LINHAS_MAPA; y++) {
        for (int x = 0; x < COLUNAS_MAPA; x++) {
            fscanf(file, "%c", &map->tiles[x][y]);
        }
    }

    fclose(file);

    map->wallTexture = LoadTexture("texturas/wall.png");
    map->groundTexture = LoadTexture("texturas/ground.png");
    map->playerTexture = LoadTexture("texturas/player.png");
    map->grassTexture = loadTexture("texturas/grass.png")
}

void DrawMap(Mapa_t *mapa) {
    for (int y = 0; y < LINHAS_MAPA; y++) {
        for (int x = 0; x < COLUNAS_MAPA; x++) {
            switch (mapa->tiles[x][y]) {

                case 'A':
                    DrawTexture(mapa->wallTexture, x * mapa->wallTexture.width, y * mapa->wallTexture.height, WHITE);
                    break;
                case '\o':
                    DrawTexture(mapa->groundTexture, x * mapa->groundTexture.width, y * mapa->groundTexture.height, WHITE);
                    break;
                case 'J':
                    DrawTexture(mapa->playerTexture, x * mapa->playerTexture.width, y * mapa->playerTexture.height, WHITE);
                    break;
                case 'G':
                    DrawTexture(mapa->playerTexture, x * mapa->grassTexture.width, y * mapa->playerTexture.height, WHITE);
                    break;
                default:
                    break;
            }
            
        }
    }
}
