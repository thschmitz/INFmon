#ifndef config_lib
#define config_lib

//Tamanhos para a tela e para o persongaem
#define LARGURA 800
#define ALTURA 800
#define LADO 20

//Defines de booleanos para facilitar a leitura
#define true 1
#define false 0

//Bibliotecas adicionais
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <raylib.h>
#include <string.h>

// Declaração de variáveis globais
extern int posicaoX, posicaoY;
extern const char tituloProjeto[10];
extern const int tamanhoFonteTituloPrincipal;
extern const int tamanhoFonteOpcoesMenu;
extern int menuInicial;

//Bibliotecas do projeto
#include "../interfaces/movimentacaoPersonagem.h"
#include "../interfaces/menu.h"

#endif
