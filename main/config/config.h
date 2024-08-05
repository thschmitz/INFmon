#ifndef config_lib
#define config_lib

//Tamanhos para o mapa
#define LADO 20
#define LINHAS_MAPA 36
#define COLUNAS_MAPA 64

#define TAMANHO_FONTE_TITULO_PRINCIPAL 150
#define TAMANHO_FONTE_OPCOES_MENU 40

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

// Declaração de variáveis globais
extern int larguraMonitor;
extern int alturaMonitor;
extern int posicaoX, posicaoY;
extern const char tituloProjeto[10];
extern Jogador_t jogador;
extern Mapa_t mapa;

// Estados do jogo
extern int menu_inicial_rodando;
extern int menu_opcoes_rodando;
extern int programa_rodando;

#endif
