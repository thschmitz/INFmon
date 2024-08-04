#include "./config/config.h"

int main() {
	InitWindow(COLUNAS_MAPA * LADO, LINHAS_MAPA * LADO, tituloProjeto);
	larguraMonitor = GetMonitorWidth(GetCurrentMonitor());
	alturaMonitor = GetMonitorHeight(GetCurrentMonitor());
	
	jogador.posicaoX = COLUNAS_MAPA * LADO / 2 - LADO;
	jogador.posicaoY = LINHAS_MAPA * LADO / 2 - LADO;

	Mapa_t mapa;
	Texturas_t texturas;
  	texturas.personagemPrincipal = LoadTexture("./texturas/sprite.png"); 

	SetTargetFPS(60);
	SetExitKey(KEY_BACKSPACE);
	LoadMap(&mapa);

	Vector2 position = { jogador.posicaoX, jogador.posicaoY };
	Camera2D camera = { 0 };
	camera.target = position;
	camera.offset = (Vector2){ larguraMonitor / 2.0f, alturaMonitor /2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 4.0f;

	bool fullscreen = false;
	SetWindowSize(larguraMonitor, alturaMonitor);
	ToggleFullscreen();

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

			//if (camera.target.x < LARGURA / 2 / camera.zoom) camera.target.x = LARGURA / 2 / camera.zoom;
        	//if (camera.target.y < ALTURA / 2 / camera.zoom) camera.target.y = ALTURA / 2 / camera.zoom;
        	//if (camera.target.x > LARGURA / 2 / camera.zoom) camera.target.x = LARGURA / 2 / camera.zoom;
        	//if (camera.target.y > ALTURA / 2 / camera.zoom) camera.target.y = ALTURA / 2 / camera.zoom;

			BeginMode2D(camera);

			DrawMap(&mapa);

			ClearBackground(RAYWHITE);
			Vector2 position = { jogador.posicaoX, jogador.posicaoY };
			camera.target = position;

			DrawTexture(texturas.personagemPrincipal, jogador.posicaoX, jogador.posicaoY, WHITE);
			EndDrawing();
			EndMode2D();
		}
	}

	CloseWindow();
	return 0;
}