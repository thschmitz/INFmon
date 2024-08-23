#include "../config/config.h"

void leitura_movimentos(int *selvagem, Jogador_t *jogadorPrincipal) //movimenta��o do personagem principal
{
	int dx = 0;
	int dy = 0;
	float speed = 8.0f;
	float deltaTime = GetFrameTime();

	if (IsKeyDown(KEY_RIGHT)){
		dx = LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_LEFT)){
		dx = -LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_UP)){
		dy = -LADO * speed * deltaTime;
	}

	if (IsKeyDown(KEY_DOWN)){
		dy = LADO * speed * deltaTime;
	}

	if (deve_mover(dx, dy, selvagem, jogadorPrincipal) == 1){
		move(dx, dy, jogadorPrincipal);
	}
}

int deve_mover(int dx, int dy, int *selvagem, Jogador_t *jogadorPrincipal) //define se o personagem principal pode se mover ou se tem algo o impedido
{
	int mx = jogadorPrincipal->posicaoX/LADO;
	int my = jogadorPrincipal->posicaoY/LADO;
	int mover;

	if (jogadorPrincipal->posicaoX + dx < 20 || jogadorPrincipal->posicaoX + dx > (COLUNAS_MAPA * LADO) - 2*LADO || jogadorPrincipal->posicaoY + dy < 20 || jogadorPrincipal->posicaoY + dy > (LINHAS_MAPA * LADO) - 2*LADO){
		mover = 0;
	}else{
		mover = 1;
		if (dx > 0){
			mx = (int)(jogadorPrincipal->posicaoX / LADO);
			my = (int)((jogadorPrincipal->posicaoY + 9) / LADO);
			if (mapa.tiles[my][mx + 1] == 'W') mover = 0;
			else if(mapa.tiles[my][mx + 1] == 'P') mover = 0;
			else if(mapa.tiles[my][mx + 1] == 'E') {
				menu_inicial_rodando = false;
        		menu_erro_rodando = false;
        		menu_opcoes_rodando = false;
				menu_batalha_rodando = true;
				selvagem = 0;
			}
		} else if (dx < 0) {
			mx = (int)((jogadorPrincipal->posicaoX + 19) / LADO);
			my = (int)((jogadorPrincipal->posicaoY + 9) / LADO);
			if (mapa.tiles[my][mx - 1] == 'W')mover = 0;
			else if(mapa.tiles[my][mx - 1] == 'P') mover = 0;
			else if(mapa.tiles[my][mx - 1] == 'E') {
				menu_inicial_rodando = false;
        		menu_erro_rodando = false;
        		menu_opcoes_rodando = false;
				menu_batalha_rodando = true;
				selvagem = 0;
			}
		}
		if (dy > 0){
			mx = (int)((jogadorPrincipal->posicaoX + 9) / LADO);
			my = (int)(jogadorPrincipal->posicaoY / LADO);
			if (mapa.tiles[my + 1][mx] == 'W')mover = 0;
			else if(mapa.tiles[my + 1][mx] == 'P') mover = 0;
			else if(mapa.tiles[my + 1][mx] == 'E') {
				menu_inicial_rodando = false;
        		menu_erro_rodando = false;
        		menu_opcoes_rodando = false;
				menu_batalha_rodando = true;
				selvagem = 0;
			}
		}else if (dy < 0){
			mx = (int)((jogadorPrincipal->posicaoX + 9) / LADO);
			my = (int)((jogadorPrincipal->posicaoY + 19) / LADO);
			if (mapa.tiles[my - 1][mx] == 'W') mover = 0;
			else if(mapa.tiles[my - 1][mx] == 'P') mover = 0;
			else if(mapa.tiles[my - 1][mx] == 'E') {
				menu_inicial_rodando = false;
        		menu_erro_rodando = false;
        		menu_opcoes_rodando = false;
				menu_batalha_rodando = true;
				selvagem = 0;
			}
		}
	}

	if(mover){
		mx = (int)((jogadorPrincipal->posicaoX + 9) / LADO);
		my = (int)((jogadorPrincipal->posicaoY + 9) / LADO);
		if (mapa.tiles[my][mx] == 'G'){
			*selvagem = spawnar_grama();
		}
	}

	return mover;
}

void move(int dx, int dy, Jogador_t *jogadorPrincipal)
{
	jogadorPrincipal->posicaoX += dx;
	jogadorPrincipal->posicaoY += dy;
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
