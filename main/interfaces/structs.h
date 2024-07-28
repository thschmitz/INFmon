#ifndef STRUCTS_H
#define STRUCTS_H

#include "../config/config.h"

/*
    Inclui as texturas do jogo
*/
typedef struct texturas {
    Texture2D wallTexture;
    Texture2D groundTexture;
    Texture2D playerTexture;
    Texture2D grassTexture;

} Texturas_t;

/*
    Essa struct engloba os elementos mapa
*/
typedef struct mapa{

    char mapa[LINHAS_MAPA][COLUNAS_MAPA];
    int fase_atual;
    Texturas_t texturas;

} Mapa_t;

#endif