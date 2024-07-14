#include "./config/config.h"

void leitura_movimentos(){
	int dx=0;
	int dy=0;

	if (IsKeyPressed(KEY_RIGHT)) {
		dx = LADO; 
	}

	if (IsKeyPressed(KEY_LEFT)) {
		dx = -LADO;
	}

	if (IsKeyPressed(KEY_UP)){
		dy = -LADO;
	}

	if (IsKeyPressed(KEY_DOWN)) {
		dy = LADO;
	}

	if(deveMover(posicaoX, posicaoY, dx, dy) == 1) {
		move(dx, dy, &posicaoX, &posicaoY);
	}
}

int deveMover(int x, int y, int dx, int dy) {
	int mover;
	if(x + dx < 0 || x + dx > LARGURA - LADO || y + dy < 0 || y + dy > ALTURA - LADO){
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