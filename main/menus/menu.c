#include "../config/config.h"

static const char *labelBotoesMenuInicial[] = {
  "NOVO JOGO",
  "CARREGAR JOGO",
  "SAIR"
};

static const char *labelBotoesMenuOpcoes[] = {
  "VOLTAR PRO JOGO",
  "SALVAR JOGO",
  "VOLTAR TELA INICIAL"
};

// Corrigindo a função measure_text para aceitar const char *
int measure_text(const char *text, int tamanhoFonte) {
  return MeasureText(text, tamanhoFonte);
}

void menu_opcoes() {
  Texturas_t texturas;
  int selection = 0;
  int menuOpen = true;
  texturas.ponteiroMenuInicialTexture = LoadTexture("./texturas/ponteiroMenuInicial.png"); 

  while (menuOpen) {
    ClearBackground(WHITE);
    BeginDrawing();

    DrawText(tituloProjeto, larguraMonitor / 2 - (measure_text(tituloProjeto, TAMANHO_FONTE_TITULO_PRINCIPAL) / 2), 20, TAMANHO_FONTE_TITULO_PRINCIPAL, BLACK);
    for (int i = 0; i < 3; i++) {
      Color cor = (i == selection) ? RED : BLACK;
      DrawText(labelBotoesMenuOpcoes[i], larguraMonitor / 2 - (measure_text(labelBotoesMenuOpcoes[i], TAMANHO_FONTE_OPCOES_MENU) / 2), alturaMonitor / 2 + i * 100, TAMANHO_FONTE_OPCOES_MENU, cor);
      if (i == selection) {
        int posX = (larguraMonitor / 2 - (measure_text(labelBotoesMenuOpcoes[i], TAMANHO_FONTE_OPCOES_MENU) / 2)) - texturas.ponteiroMenuInicialTexture.width - 10;
        int posY = alturaMonitor / 2 + i * 100 - texturas.ponteiroMenuInicialTexture.height / 2;
        DrawTexture(texturas.ponteiroMenuInicialTexture, posX, posY + 10, WHITE);
      }
    }

    EndDrawing();

    if (IsKeyPressed(KEY_DOWN)) {
      selection++;
      if (selection > 2) selection = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
      selection--;
      if (selection < 0) selection = 2;
    }

    if (IsKeyPressed(KEY_ENTER)) {
      menuOpen = false;
    }
  }

  UnloadTexture(texturas.ponteiroMenuInicialTexture);

  if (IsKeyPressed(KEY_ENTER)) {
    switch (selection) {
      case 0:
        // Voltar pro jogo
        menu_inicial_rodando = false;
        menu_opcoes_rodando = false;
        menuOpen = false;
        break;
      case 1:
        // Salvar jogo
        //salvar();
        menu_inicial_rodando = false;
        menu_opcoes_rodando = false;
        menuOpen = false;
        break;
      case 2:
        // Voltar menu inicial
        menu_inicial_rodando = true;
        menu_opcoes_rodando = false;
        menuOpen = false;
        break;
      default:
        break;
    }
  }
}

void salvarJogo(){
  FILE *file;


}

void menu_inicial() {
  Texturas_t texturas;
  int selection = 0;
  int menuOpen = true;
  texturas.ponteiroMenuInicialTexture = LoadTexture("./texturas/ponteiroMenuInicial.png"); 

  while (menuOpen) {
    ClearBackground(WHITE);
    BeginDrawing();

    DrawText(tituloProjeto, larguraMonitor / 2 - (measure_text(tituloProjeto, TAMANHO_FONTE_TITULO_PRINCIPAL) / 2), 20, TAMANHO_FONTE_TITULO_PRINCIPAL, BLACK);
    for (int i = 0; i < 3; i++) {
      Color cor = (i == selection) ? RED : BLACK;
      DrawText(labelBotoesMenuInicial[i], larguraMonitor / 2 - (measure_text(labelBotoesMenuInicial[i], TAMANHO_FONTE_OPCOES_MENU) / 2), alturaMonitor / 2 + i * 100, TAMANHO_FONTE_OPCOES_MENU, cor);
      if (i == selection) {
        int posX = (larguraMonitor / 2 - (measure_text(labelBotoesMenuInicial[i], TAMANHO_FONTE_OPCOES_MENU) / 2)) - texturas.ponteiroMenuInicialTexture.width - 10;
        int posY = alturaMonitor / 2 + i * 100 - texturas.ponteiroMenuInicialTexture.height / 2;
        DrawTexture(texturas.ponteiroMenuInicialTexture, posX, posY + 10, WHITE);
      }
    }

    EndDrawing();

    if (IsKeyPressed(KEY_DOWN)) {
      selection++;
      if (selection > 2) selection = 0;
    }
    if (IsKeyPressed(KEY_UP)) {
      selection--;
      if (selection < 0) selection = 2;
    }

    if (IsKeyPressed(KEY_ENTER)) {
      menuOpen = false;
    }
  }

  UnloadTexture(texturas.ponteiroMenuInicialTexture);

  if (IsKeyPressed(KEY_ENTER)) {
    switch (selection) {
      case 0:
        // Novo Jogo
        menu_inicial_rodando = false;
        menuOpen = false;
        break;
      case 1:
        // Carregar Jogo
        //carregarJogo();
        menu_inicial_rodando = false;
        menuOpen = false;
        break;
      case 2:
        programa_rodando = false;
        menuOpen = false;
        break;
      default:
        break;
    }
  }
}

void carregarJogo(){
  FILE *arq;

}