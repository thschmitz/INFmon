#include "./config/config.h"

int posicaoX, posicaoY;

int main() {
	InitWindow(LARGURA, ALTURA, "Quadrado");
    // Inicializa a posição do quadrado
    posicaoX = ALTURA / 2 - LADO;
    posicaoY = LARGURA / 2 - LADO;

	SetTargetFPS(60);
	while (!WindowShouldClose()){
		leitura_movimentos();

		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangle(posicaoX, posicaoY, LADO, LADO, GREEN);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}

