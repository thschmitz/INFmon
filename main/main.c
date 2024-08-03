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
	LoadMap(&mapa);
	ToggleFullscreen();   

	Vector2 position = { posicaoX, posicaoY };
	Camera2D camera = { 0 };
    camera.target = position;
    camera.offset = (Vector2){ LARGURA/2.0f, ALTURA/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 4.0f;

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
			Vector2 position = { posicaoX, posicaoY };
			camera.target = position;

			DrawTexture(texturas.personagemPrincipal, posicaoX, posicaoY, WHITE);
			EndDrawing();
			EndMode2D();
		}
	}

	CloseWindow();
	return 0;
}