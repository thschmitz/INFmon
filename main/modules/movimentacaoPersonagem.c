#include "../config/config.h"

void leitura_movimentos(){
	int dx=0;
	int dy=0;
	float speed = 10.0f;
	float deltaTime = GetFrameTime();

	if (IsKeyDown(KEY_RIGHT)) {
		dx = LADO * speed * deltaTime; 
	}

	if (IsKeyDown(KEY_LEFT)) {
		dx = -LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_UP)){
		dy = -LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_DOWN)) {
		dy = LADO * speed * deltaTime;
	}

	if(deveMover(posicaoX, posicaoY, dx, dy) == 1) {
		move(dx, dy, &posicaoX, &posicaoY);
	}
}

int deveMover(int x, int y, int dx, int dy) {
	int mover;
	if(x + dx < 0 || x + dx > (COLUNAS_MAPA * LADO) - LADO || y + dy < 0 || y + dy > (LINHAS_MAPA * LADO) - LADO){
		mover = 0;
	} else {
		mover = 1;
	}

	return mover;
}

void move(int dx, int dy, int *x, int *y){
	*x += dx;
	*y += dy;
}