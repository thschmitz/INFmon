#include "./config/config.h"

int main() {
	InitWindow(LARGURA, ALTURA, tituloProjeto);
	// Inicializa a posição do quadrado
	posicaoX = ALTURA / 2 - LADO;
	posicaoY = LARGURA / 2 - LADO;

	SetTargetFPS(60);
	SetExitKey(KEY_BACKSPACE);

	while (!WindowShouldClose() && programa_rodando) {
		if (menu_inicial_rodando) {
			menu_inicial();
		} else {
			leitura_movimentos();

			if (IsKeyPressed(KEY_ESCAPE)) {
				menu_inicial_rodando = true;
			}

			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(posicaoX, posicaoY, LADO, LADO, GREEN);
			EndDrawing();
		}
	}

	CloseWindow();
	return 0;
}