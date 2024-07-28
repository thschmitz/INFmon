#include "../config/config.h"

static const char *labelBotoes[] = {
  "NOVO JOGO",
  "CARREGAR JOGO",
  "SAIR"
};

// Corrigindo a função measure_text para aceitar const char *
int measure_text(const char *text, int tamanhoFonte) {
  return MeasureText(text, tamanhoFonte);
}

void menu_inicial() {
  int selection = 0;
  int menuOpen = true;
  Image image = LoadImage("../texturas/ponteiroMenuInicial.png"); 
  Texture2D cursorTelaInicial = LoadTextureFromImage(image);    
  UnloadImage(image);
  
  while (menuOpen) {
    ClearBackground(WHITE);
    BeginDrawing();

    DrawText(tituloProjeto, LARGURA / 2 - (measure_text(tituloProjeto, tamanhoFonteTituloPrincipal) / 2), 20, tamanhoFonteTituloPrincipal, BLACK);

    for (int i = 0; i < 3; i++) {
      Color cor = (i == selection) ? RED : BLACK;
      DrawText(labelBotoes[i], LARGURA / 2 - (measure_text(labelBotoes[i], tamanhoFonteOpcoesMenu) / 2), ALTURA / 2 + i * 100, tamanhoFonteOpcoesMenu, cor);
      if (i == selection) {
        int posX = (LARGURA / 2 - (measure_text(labelBotoes[i], tamanhoFonteOpcoesMenu) / 2)) - cursorTelaInicial.width - 10;
        int posY = ALTURA / 2 + i * 100 - cursorTelaInicial.height / 2;
        DrawTexture(cursorTelaInicial, posX, posY + 10, WHITE);
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

  UnloadTexture(cursorTelaInicial);

  if (IsKeyPressed(KEY_ENTER)) {
    switch (selection) {
      case 0:
        // Novo Jogo
        menu_inicial_rodando = false;
        menuOpen = false;
        break;
      case 1:
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