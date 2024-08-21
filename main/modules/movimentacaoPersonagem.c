#include "../config/config.h"

void leitura_movimentos(int *selvagem) //movimenta��o do personagem principal
{
	int dx = 0;
	int dy = 0;
	float speed = 8.0f;
	float deltaTime = GetFrameTime();

	if (IsKeyDown(KEY_RIGHT))
	{
		dx = LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_LEFT))
	{
		dx = -LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_UP))
	{
		dy = -LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_DOWN))
	{
		dy = LADO * speed * deltaTime;
	}

	if (deve_mover(dx, dy, selvagem) == 1)
	{
		move(dx, dy);
	}
}

int deve_mover(int dx, int dy, int *selvagem) //define se o personagem principal pode se mover ou se tem algo o impedido
{
	int mx = jogador.posicaoX/LADO;
	int my = jogador.posicaoY/LADO;
	int mover;

	if (jogador.posicaoX + dx < 20 || jogador.posicaoX + dx > (COLUNAS_MAPA * LADO) - 2*LADO || jogador.posicaoY + dy < 20 || jogador.posicaoY + dy > (LINHAS_MAPA * LADO) - 2*LADO){
		mover = 0;
	}else{
		mover = 1;
		if (dx > 0){
			mx = (int)(jogador.posicaoX / LADO);
			my = (int)((jogador.posicaoY + 9) / LADO);
			if (mapa.tiles[my][mx + 1] == 'W') mover = 0;
			else if(mapa.tiles[my][mx + 1] == 'P') mover = 0;
		} else if (dx < 0) {
			mx = (int)((jogador.posicaoX + 19) / LADO);
			my = (int)((jogador.posicaoY + 9) / LADO);
			if (mapa.tiles[my][mx - 1] == 'W')mover = 0;
			else if(mapa.tiles[my][mx - 1] == 'P') mover = 0;
		}
		if (dy > 0){
			mx = (int)((jogador.posicaoX + 9) / LADO);
			my = (int)(jogador.posicaoY / LADO);
			if (mapa.tiles[my + 1][mx] == 'W')mover = 0;
		}else if (dy < 0){
			mx = (int)((jogador.posicaoX + 9) / LADO);
			my = (int)((jogador.posicaoY + 19) / LADO);
			if (mapa.tiles[my - 1][mx] == 'W') mover = 0;
			else if(mapa.tiles[my - 1][mx] == 'P') mover = 0;
		}
	}

	if(mover){
		mx = (int)((jogador.posicaoX + 9) / LADO);
		my = (int)((jogador.posicaoY + 9) / LADO);
		if (mapa.tiles[my][mx] == 'G'){
			*selvagem = spawnar_grama();
		}
	}

	return mover;
}

void move(int dx, int dy)
{
	jogador.posicaoX += dx;
	jogador.posicaoY += dy;
}

int spawnar_grama(){
	int chance = (rand() %250);
	if (chance == 7){
		chance = 0;
		menu_inicial_rodando = false;
        menu_erro_rodando = false;
        menu_opcoes_rodando = false;
		menu_batalha_rodando = true;
	}

	return 1;
}
