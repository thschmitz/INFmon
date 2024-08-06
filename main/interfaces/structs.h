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
    Essa struct engloba os elementos do ataque
*/
typedef struct ataque {
    char tipoAtaque[QUANTIDADE_CARACTERES_TIPO_ATAQUE];
    float dano;
    int pp;
} Ataque_t;

/*
    Essa struct engloba os elementos do pokemon
*/
typedef struct pokemon {
    char nome[QUANTIDADE_CARACTERES_NOME_POKEMON];
    char tipoPokemon[QUANTIDADE_CARACTERES_TIPO_POKEMON];
    float vida;
    Ataque_t ataques[QUANTIDADE_ATAQUES_POR_POKEMON];
} Pokemon_t;

/*
    Essa struct engloba os elementos do jogador
*/
typedef struct jogador {
    int posicaoX;
    int posicaoY;
    Pokemon_t pokemons[QUANTIDADE_POKEMONS_POR_JOGADOR];
} Jogador_t;





#endif