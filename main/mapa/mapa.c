#include "../config/config.h"

void LoadMap(Mapa *map) {

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

    map->wallTexture = LoadTexture("textures/wall.png");
    map->groundTexture = LoadTexture("textures/ground.png");
    map->playerTexture = LoadTexture("textures/player.png");
}

void DrawMap(Mapa *map) {
    for (int y = 0; y < LINHAS_MAPA; y++) {
        for (int x = 0; x < COLUNAS_MAPA; x++) {
            switch (map->tiles[x][y]) {

                case 'A':
                    DrawTexture(map->wallTexture, x * map->wallTexture.width, y * map->wallTexture.height, WHITE);
                    break;
                case '\o':
                    DrawTexture(map->groundTexture, x * map->groundTexture.width, y * map->groundTexture.height, WHITE);
                    break;
                case 'J':
                    DrawTexture(map->playerTexture, x * map->playerTexture.width, y * map->playerTexture.height, WHITE);
                    break;
                case 'G':
                    DrawTexture(map->playerTexture, x * map->playerTexture.width, y * map->playerTexture.height, WHITE);
                    break;
                default:
                    break;
            }
            
        }
    }
}
