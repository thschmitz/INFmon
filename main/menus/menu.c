#include "../config/config.h"

static const char *labelBotoes[] = {
  "NOVO JOGO",
  "CARREGAR JOGO",
  "SAIR"
};

// Corrigindo a função measure_text para aceitar const char *
int measure_text(const char *text, int tamanhoFonte){
  return MeasureText(text, tamanhoFonte);
}

int menu_inicial(){

  int selection = 0;

  ClearBackground(WHITE);
  BeginDrawing();

  DrawText(tituloProjeto, LARGURA / 2 - (measure_text(tituloProjeto, tamanhoFonteTituloPrincipal) / 2), 20, tamanhoFonteTituloPrincipal, BLACK);

  DrawText(labelBotoes[0], LARGURA / 2 - (measure_text(labelBotoes[0], tamanhoFonteOpcoesMenu) / 2), ALTURA / 2, tamanhoFonteOpcoesMenu, BLACK);
  DrawText(labelBotoes[1], LARGURA / 2 - (measure_text(labelBotoes[1], tamanhoFonteOpcoesMenu) / 2), ALTURA / 2 + 100, tamanhoFonteOpcoesMenu, BLACK);
  DrawText(labelBotoes[2], LARGURA / 2 - (measure_text(labelBotoes[2], tamanhoFonteOpcoesMenu) / 2), ALTURA / 2 + 200, tamanhoFonteOpcoesMenu, BLACK);

  EndDrawing();

  if (IsKeyPressed(KEY_N) || selection == 1) {
    return 1;
  }

  // Carrega um jogo salvo previamente
  if (IsKeyPressed(KEY_C) || selection == 2) {
    return 1;
  }

  // Fecha o jogo
  if (IsKeyPressed(KEY_F) || selection == 3) {
    return 0;
  }

  // Abre o menu de opções
  if (IsKeyPressed(KEY_O) || selection == 4) {
    return 2;
  }

  return 1;
}