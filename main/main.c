#include "./config/config.h"

int main() {
	InitRandomSeed();
	InitWindow(COLUNAS_MAPA * LADO, LINHAS_MAPA * LADO, tituloProjeto);
	larguraMonitor = GetMonitorWidth(GetCurrentMonitor());
	alturaMonitor = GetMonitorHeight(GetCurrentMonitor());

	jogador.posicaoX = COLUNAS_MAPA * LADO / 2;
	jogador.posicaoY = LINHAS_MAPA * LADO / 2;

	Ataque_t ataque1 = {"TESTE1", 50.5, 42, "NORMAL"};
	Ataque_t ataque2 = {"TESTE2", 12.5, 42, "NORMAL"};
	Ataque_t ataque3 = {"TESTE3", 43.5, 42, "NORMAL"};
	Ataque_t ataque4 = {"TESTE4", 89.5, 42, "NORMAL"};
	Ataque_t ataque5 = {"TESTE5", 100.5, 42, "NORMAL"};
	Ataque_t ataque6 = {"TESTE6", 34.5, 42, "NORMAL"};
	Ataque_t ataques[] = {ataque1, ataque2, ataque3, ataque4, ataque5, ataque6};

	Pokemon_t charmander = {
		.ataques = {ataque1, ataque2, ataque3, ataque4},
		.vida = 100,
		.vidaMaxima = 200,
		.xp = 5,
		.nome = "CHURRASQUINHO",
		.tipoPokemon = "FOGO"
	};

	Pokemon_t lapras = {
		.ataques = {ataque1, ataque2, ataque3, ataque4},
		.vida = 100,
		.vidaMaxima = 200,
		.xp = 2,
		.nome = "CHORAO",
		.tipoPokemon = "AGUA"
	};

	Pokemon_t graminha = {
		.ataques = {ataque1, ataque2, ataque3, ataque4},
		.vida = 100,
		.vidaMaxima = 200,
		.xp = 2,
		.nome = "GRAMINHA",
		.tipoPokemon = "GRAMA"
	};

	Pokemon_t zubat = {
		.ataques = {ataque1, ataque2, ataque3, ataque4},
		.vida = 100,
		.vidaMaxima = 200,
		.xp = 2,
		.nome = "MORCEGAO",
		.tipoPokemon = "VOADOR"
	};

	Pokemon_t diglett = {
		.ataques = {ataque1, ataque2, ataque3, ataque4},
		.vida = 100,
		.vidaMaxima = 200,
		.xp = 2,
		.nome = "GONZAGUINHA",
		.tipoPokemon = "TERRA"
	};

	Pokemon_t pikachu = {
		.ataques = {ataque1, ataque2, ataque3, ataque4},
		.vida = 100,
		.vidaMaxima = 200,
		.xp = 2,
		.nome = "ZEUS",
		.tipoPokemon = "ELETRICO"
	};

	Texturas_t texturas;
  	texturas.personagemPrincipal = LoadTexture("./texturas/personagem_infmon.png");//personagem principal
  	texturas.churrasquinhoFrente = LoadTexture ("./textures/churrasquinho_invertido.png");//churrasquinho
  	texturas.churrasquinhoCostas = LoadTexture ("./textures/churrasquiho_costas.png");
  	texturas.choraoFrente = LoadTexture ("./textures/chora2def.png");//chorão
  	texturas.choraoCostas = LoadTexture ("./textures/chorao2_costas.png");
  	texturas.gonzaguinhaFrente = LoadTexture ("./textures/gonzaguinha.png");//gonzaguinha
  	texturas.gonzaguinhaCostas = LoadTexture ("./textures/gonzaguinha_costas2.png");
  	texturas.graminhaFrente = LoadTexture ("./textures/graminha_frente.png");//graminha
  	texturas.graminhaCostas = LoadTexture ("./textures/graminha1.png");
  	texturas.morcegaoFrente = LoadTexture ("./textures/morcegaoinfbola.png");//morcegao
  	texturas.morcegaoCostas = LoadTexture ("./textures/morcegao_costas.png");
  	texturas.zeusFrente = LoadTexture ("./textures/zeus.png");//zeus
  	texturas.zeusCostas = LoadTexture ("./textures/zeus_costas.png");


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
			mostrar_tela_combate(charmander, lapras);
		} else {
			rodar_jogo(&camera, &texturas);
		}
	}
	CloseWindow();
	return 0;
}
