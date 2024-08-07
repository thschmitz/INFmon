#include "./config/config.h"

int main() {
	InitRandomSeed();
	InitWindow(COLUNAS_MAPA * LADO, LINHAS_MAPA * LADO, tituloProjeto);
	larguraMonitor = GetMonitorWidth(GetCurrentMonitor());
	alturaMonitor = GetMonitorHeight(GetCurrentMonitor());

	jogador.posicaoX = COLUNAS_MAPA * LADO / 2;
	jogador.posicaoY = LINHAS_MAPA * LADO / 2;

	Pokemon_t charmander = {100, 200, 5, "CHARMANDER", "FOGO"};
    Pokemon_t squirtle = {100, 200, 2, "SQUIRTLE", "AGUA"};

	Texturas_t texturas;
  	texturas.personagemPrincipal = LoadTexture("./texturas/sprite.png"); 

	SetTargetFPS(60);
	SetExitKey(KEY_BACKSPACE);

	Vector2 position = { jogador.posicaoX, jogador.posicaoY };
	Camera2D camera = { 0 };
	camera.target = position;
	camera.offset = (Vector2){ larguraMonitor / 2.0f, alturaMonitor /2.0f };
	camera.rotation = 0.0f;
	camera.zoom = 5.0f;

	bool fullscreen = false;
	SetWindowSize(larguraMonitor, alturaMonitor);
	ToggleFullscreen();

	carregar_mapa();

	while (!WindowShouldClose() && programa_rodando) {
		if (menu_inicial_rodando) {
			menu_inicial();
		} else if(menu_opcoes_rodando){
			menu_opcoes();
		} else if(menu_erro_rodando){
			menu_erro();
		}else if(menu_batalha_rodando){
			mostrar_tela_combate(charmander, squirtle);
		} else {
			rodar_jogo(&camera, &texturas);
		}
	}
	CloseWindow();
	return 0;
}