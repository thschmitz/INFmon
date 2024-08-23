#ifndef config_lib
#define config_lib

//Tamanhos para o mapa
#define LADO 20
#define LINHAS_MAPA 36
#define COLUNAS_MAPA 64

#define TAMANHO_FONTE_TITULO_PRINCIPAL 150
#define TAMANHO_FONTE_OPCOES_MENU 40
#define QUANTIDADE_POKEMONS_POR_JOGADOR 6
#define QUANTIDADE_CARACTERES_NOME_POKEMON 50
#define QUANTIDADE_CARACTERES_TIPO_POKEMON 20
#define QUANTIDADE_CARACTERES_TIPO_ATAQUE 20
#define QUANTIDADE_ATAQUES_POR_POKEMON 4
#define QUANTIDADE_CARACTERES_NOME_ATAQUE 20

//Defines de booleanos para facilitar a leitura
#define true 1
#define false 0

//Bibliotecas adicionais
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <raylib.h>
#include <string.h>

//Bibliotecas do projeto
#include "../interfaces/structs.h"
#include "../interfaces/movimentacaoPersonagem.h"
#include "../interfaces/menu.h"
#include "../interfaces/mapa.h"
#include "../interfaces/jogo.h"
#include "../interfaces/combate.h"

// Declaração de variáveis globais
extern unsigned int globalSeed;
extern int larguraMonitor;
extern int alturaMonitor;
extern int posicaoX, posicaoY;
extern const char tituloProjeto[10];
extern float tabela[6][6];
extern Mapa_t mapa;

void InitRandomSeed();

// Estados do jogo
extern int menu_inicial_rodando;
extern int menu_opcoes_rodando;
extern int menu_erro_rodando;
extern int programa_rodando;
extern int menu_batalha_rodando;

#endif
