#include "./config/config.h"

int main() {
	InitWindow(LARGURA, ALTURA, tituloProjeto);
	// Inicializa a posição do quadrado
	posicaoX = ALTURA / 2 - LADO;
	posicaoY = LARGURA / 2 - LADO;

	SetTargetFPS(60);

	while (!WindowShouldClose()){
		if(menuInicial == 1){
			menuInicial = menu_inicial();
		} else {
			leitura_movimentos();

			BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawRectangle(posicaoX, posicaoY, LADO, LADO, GREEN);
			EndDrawing();
		}
	}
	CloseWindow();
	return 0;
}

