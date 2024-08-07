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
    Texturas_t texturas;
    int fase_atual;
    char tiles[LINHAS_MAPA][COLUNAS_MAPA];
} Mapa_t;

/*
    Essa struct engloba os elementos do ataque
*/
typedef struct ataque {
    float dano;
    int pp;
    char tipoAtaque[QUANTIDADE_CARACTERES_TIPO_ATAQUE];
} Ataque_t;

/*
    Essa struct engloba os elementos do pokemon
*/
typedef struct pokemon {
    //Ataque_t ataques[QUANTIDADE_ATAQUES_POR_POKEMON];
    float vida;
    float vidaMaxima;
    int xp;
    char nome[QUANTIDADE_CARACTERES_NOME_POKEMON];
    char tipoPokemon[QUANTIDADE_CARACTERES_TIPO_POKEMON];
} Pokemon_t;

/*
    Essa struct engloba os elementos do jogador
*/
typedef struct jogador {
    Pokemon_t pokemons[QUANTIDADE_POKEMONS_POR_JOGADOR];
    int posicaoX;
    int posicaoY;
} Jogador_t;


typedef struct interfaceCombate {
    Rectangle optionsBox;
    Rectangle fightBox;
    Rectangle bagBox;
    Rectangle pokemonBox;
    Rectangle runBox;
} InterfaceCombate_t;

#endif