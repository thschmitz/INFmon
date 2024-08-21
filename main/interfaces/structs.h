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
    Texture2D churrasquinhoFrente;
    Texture2D churrasquinhoCostas;
    Texture2D choraoFrente;
    Texture2D choraoCostas;
    Texture2D gonzaguinhaFrente;
    Texture2D gonzaguinhaCostas;
    Texture2D graminhaFrente;
    Texture2D graminhaCostas;
    Texture2D morcegaoFrente;
    Texture2D morcegaoCostas;
    Texture2D zeusFrente;
    Texture2D zeusCostas;

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
    char nome[QUANTIDADE_CARACTERES_NOME_ATAQUE];
    float dano;
    int pp;
    char tipoAtaque[QUANTIDADE_CARACTERES_TIPO_ATAQUE];
} Ataque_t;

/*
    Essa struct engloba os elementos do pokemon
*/
typedef struct pokemon {
    Ataque_t ataques[QUANTIDADE_ATAQUES_POR_POKEMON];
    float defesa;
    float vida;
    float vidaMaxima;
    float ataque;
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
    Rectangle ataque1;
    Rectangle ataque2;
    Rectangle ataque3;
    Rectangle ataque4;
} InterfaceCombate_t;

#endif
