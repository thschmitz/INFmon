#include "./config/config.h"

int main() {
	InitWindow(LARGURA, ALTURA, tituloProjeto);
	// Inicializa a posição do quadrado
	posicaoX = ALTURA / 2 - LADO;
	posicaoY = LARGURA / 2 - LADO;
	Mapa_t mapa;
	Texturas_t texturas;
  texturas.personagemPrincipal = LoadTexture("./texturas/sprite.png"); 


	SetTargetFPS(60);
	SetExitKey(KEY_BACKSPACE);

	while (!WindowShouldClose() && programa_rodando) {
		if (menu_inicial_rodando) {
			menu_inicial();
		} else if(menu_opcoes_rodando){
			menu_opcoes();
		} else {
			leitura_movimentos();

			if (IsKeyPressed(KEY_ESCAPE)) {
				menu_opcoes_rodando = true;
			}

			LoadMap(&mapa);
			DrawMap(&mapa);
			ClearBackground(RAYWHITE);
			DrawTexture(texturas.personagemPrincipal, posicaoX, posicaoY, WHITE);
			EndDrawing();
		}
	}

	CloseWindow();
	return 0;
}