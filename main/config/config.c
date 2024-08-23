#include "config.h"

// Declaração de variáveis globais
const char tituloProjeto[10] = "INFmon";
Jogador_t jogador;
Mapa_t mapa;

// Variaveis de tamanho da tela
int larguraMonitor;
int alturaMonitor;

// Status do jogo
int menu_inicial_rodando=true;
int menu_opcoes_rodando=false;
int menu_erro_rodando=false;
int programa_rodando=true;
int menu_batalha_rodando=false;

// Função para inicializar a seed
unsigned int globalSeed;
void InitRandomSeed() {
    globalSeed = (unsigned int)time(NULL);
    srand(globalSeed);
}

//Tabela de desvantagens
float tabela[6][6] = {
    {1, 0.5, 1, 1.5, 1, 1},
    {1.5, 1, 0.5, 0.5, 1, 1},
    {0.5, 1.5, 1, 1.5, 0.5, 1},
    {1, 1.5, 1, 1, 1.5, 0},
    {1, 1, 1, 0, 1, 1},
    {1.5, 1, 1, 1, 1, 1}
};