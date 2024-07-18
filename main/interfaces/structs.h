#ifndef STRUCTS_H
#define STRUCTS_H

#include "../config/config.h"

typedef struct {

    char mapa[LINHAS_MAPA][COLUNAS_MAPA];
    int fase_atual;

    Texture2D wallTexture;
    Texture2D groundTexture;
    Texture2D playerTexture;

} Mapa;

#endif