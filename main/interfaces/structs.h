#ifndef STRUCTS_H
#define STRUCTS_H

#include "../config/config.h"

/*
    Essa struct engloba as texturas do jogo
*/
typedef struct texturas {
    Texture2D ponteiroMenuInicialTexture;
    Texture2D wallTexture;
    Texture2D groundTexture;
    Texture2D playerTexture;
    Texture2D grassTexture;
    Texture2D personagemPrincipal;

} Texturas_t;

/*
    Essa struct engloba os elementos mapa
*/
typedef struct mapa {
    int fase_atual;
    char tiles[LINHAS_MAPA][COLUNAS_MAPA];
    Texturas_t texturas;
} Mapa_t;

/*
    Essa struct engloba os elementos do jogador
*/
typedef struct jogador {
    int posicaoX;
    int posicaoY;
} Jogador_t;

#endif