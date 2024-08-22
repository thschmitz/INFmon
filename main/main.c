#include "./config/config.h"

int main() {
    InitRandomSeed();
    InitWindow(COLUNAS_MAPA * LADO, LINHAS_MAPA * LADO, tituloProjeto);
    int selvagem = 0;
    larguraMonitor = GetMonitorWidth(GetCurrentMonitor());
    alturaMonitor = GetMonitorHeight(GetCurrentMonitor());
    Jogador_t jogadorPrincipal;
	Jogador_t jogador;

	Ataque_t ataque1 = {"NO DE GRAMA", 60, 15, "GRAMA"};
	Ataque_t ataque2 = {"MORDIDA", 55, 22, "GRAMA"};
	Ataque_t ataque3 = {"CHICOTE DE ERVA", 70, 10, "GRAMA"};
	Ataque_t ataque4 = {"ERVA DANINHA", 60, 15, "GRAMA"};
	Ataque_t ataque5 = {"EXPLOSAO", 1000, 1, "FOGO"};
	Ataque_t ataque6 = {"CARBONIZAR", 60, 15, "FOGO"};
	Ataque_t ataque7 = {"LANCA CHAMAS", 70, 10, "FOGO"};
	Ataque_t ataque8 = {"BOLA DE FOGO", 75, 8, "FOGO"};
	Ataque_t ataque9 = {"BOLHA", 70, 10, "AGUA"};
	Ataque_t ataque10 = {"DIAS DE LUTA", 40, 30, "AGUA"};
	Ataque_t ataque11 = {"DIAS DE GLORIA", 100, 8, "AGUA"};
	Ataque_t ataque12 = {"SURF", 60, 12, "AGUA"};
	Ataque_t ataque13 = {"TERREMOTO", 80, 10, "TERRA"};
	Ataque_t ataque14 = {"CALANGO", 70, 15, "TERRA"};
	Ataque_t ataque15 = {"ARRAIAL", 60, 18, "TERRA"};
	Ataque_t ataque16 = {"AREIA MOVEDICA", 50, 20, "TERRA"};
	Ataque_t ataque17 = {"TEMPESTADE", 75, 15, "ELETRICO"};
	Ataque_t ataque18 = {"ONDA DE CHOQUE", 80, 10, "ELETRICO"};
	Ataque_t ataque19 = {"TROVAO", 70, 12, "ELETRICO"};
	Ataque_t ataque20 = {"CANHAO DE RAIO", 100, 8, "ELETRICO"};
	Ataque_t ataque21 = {"ACROBACIA", 75, 12, "VOADOR"};
	Ataque_t ataque22 = {"BOMERANG", 80, 10, "VOADOR"};
	Ataque_t ataque23 = {"SONAR", 50, 20, "VOADOR"};
	Ataque_t ataque24 = {"BATMOVEL", 90, 8, "VOADOR"};
	//Ataque_t ataques[] = {ataque1, ataque2, ataque3, ataque4, ataque5, ataque6};

	Pokemon_t churrasquinho = {
		.ataques = {ataque5, ataque6, ataque7, ataque8},
		.defesa = 43,
		.vida = 195,
		.ataque = 52,
		.vidaMaxima = 195,
		.xp = 0,
		.nome = "CHURRASQUINHO",
		.tipoPokemon = "FOGO"
	};

	Pokemon_t chorao = {
		.ataques = {ataque9, ataque10, ataque11, ataque12},
		.defesa = 65,
		.vida = 220,
		.ataque = 48,
		.vidaMaxima = 220,
		.xp = 0,
		.nome = "CHORAO",
		.tipoPokemon = "AGUA"
	};

	Pokemon_t graminha = {
		.ataques = {ataque1, ataque2, ataque3, ataque4},
		.defesa = 49,
		.vida = 225,
		.ataque = 49,
		.vidaMaxima = 225,
		.xp = 0,
		.nome = "GRAMINHA",
		.tipoPokemon = "GRAMA"
	};

	Pokemon_t zubat = {
		.ataques = {ataque21, ataque22, ataque23, ataque24},
		.defesa = 35,
		.vida = 200,
		.ataque = 45,
		.vidaMaxima = 200,
		.xp = 0,
		.nome = "MORCEGAO",
		.tipoPokemon = "VOADOR"
	};

	Pokemon_t diglett = {
		.ataques = {ataque13, ataque14, ataque15, ataque16},
		.defesa = 25,
		.vida = 100,
		.ataque = 55,
		.vidaMaxima = 100,
		.xp = 0,
		.nome = "GONZAGUINHA",
		.tipoPokemon = "TERRA"
	};

	Pokemon_t pikachu = {
		.ataques = {ataque17, ataque18, ataque19, ataque20},
		.defesa = 40,
		.vida = 175,
		.ataque = 55,
		.vidaMaxima = 175,
		.xp = 0,
		.nome = "ZEUS",
		.tipoPokemon = "ELETRICO"
	};

    Pokemon_t pokemonsIniciais[3] = {graminha, churrasquinho, chorao};

	jogador.pokemons[0] = graminha;
	jogador.pokemons[1] = churrasquinho;
	jogador.pokemons[2] = chorao;
	jogador.pokemons[3] = diglett;
	jogador.pokemons[4] = pikachu;
	jogador.pokemons[5] = zubat;

    Texturas_t texturas;
    texturas.personagemPrincipal = LoadTexture("texturas/personagem_infmon.png"); // personagem principal
    texturas.churrasquinhoFrente = LoadTexture("texturas/churrasquinho_invertido.png"); // churrasquinho
    texturas.churrasquinhoCostas = LoadTexture("texturas/churrasquinho_costas.png");
    texturas.choraoFrente = LoadTexture("texturas/chorao2def.png"); // chorão
    texturas.choraoCostas = LoadTexture("texturas/chorao2_costas.png");
    texturas.gonzaguinhaFrente = LoadTexture("texturas/gonzaguinha.png"); // gonzaguinha
    texturas.gonzaguinhaCostas = LoadTexture("texturas/gonzaguinha_costas2.png");
    texturas.graminhaFrente = LoadTexture("texturas/graminha_frente.png"); // graminha
    texturas.graminhaCostas = LoadTexture("texturas/graminha1.png");
    texturas.morcegaoFrente = LoadTexture("texturas/morcegaoinfbola.png"); // morcegao
    texturas.morcegaoCostas = LoadTexture("texturas/morcegao_costas.png");
    texturas.zeusFrente = LoadTexture("texturas/zeus.png"); // zeus
    texturas.zeusCostas = LoadTexture("texturas/zeus_costas.png");

    // Verifica se as texturas foram carregadas
    if (texturas.churrasquinhoFrente.id == 0 || texturas.choraoFrente.id == 0 || texturas.gonzaguinhaFrente.id == 0 ||
        texturas.graminhaFrente.id == 0 || texturas.morcegaoFrente.id == 0 || texturas.zeusFrente.id == 0) {
        printf("Erro ao carregar uma ou mais texturas.\n");
        return 1; // Sai do programa caso falhe o carregamento
    }

    SetTargetFPS(60);
    SetExitKey(KEY_BACKSPACE);

    bool fullscreen = false;
    SetWindowSize(larguraMonitor, alturaMonitor);
    ToggleFullscreen();

    carregar_mapa(&jogadorPrincipal);

    Camera2D camera = { 0 };
    camera.target.x = jogadorPrincipal.posicaoX;
    camera.target.y = jogadorPrincipal.posicaoY;
    camera.offset = (Vector2){ larguraMonitor / 2.0f, alturaMonitor / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 5.0f;

    while (!WindowShouldClose() && programa_rodando) {
        if (menu_inicial_rodando) {
            menu_inicial(&jogadorPrincipal);
        } else if (menu_opcoes_rodando) {
            menu_opcoes(&jogadorPrincipal);
        } else if (menu_erro_rodando) {
            menu_erro();
        } else if (menu_batalha_rodando) {
            if (selvagem) {
                mostrar_tela_combate(jogadorPrincipal.pokemons[0], jogador.pokemons[3 + (rand() %3)], texturas, &jogadorPrincipal);
            } else {
				Jogador_t opponent = configurar_oponente(jogador, jogadorPrincipal);
                mostrar_tela_combate_inimigo(jogadorPrincipal.pokemons[0],opponent, texturas, &jogadorPrincipal);
            }

        } else {
            rodar_jogo(&camera, &texturas, &selvagem, &jogadorPrincipal, pokemonsIniciais);
        }
    }

    // Descarrega as texturas ao finalizar
    UnloadTexture(texturas.personagemPrincipal);
    UnloadTexture(texturas.churrasquinhoFrente);
    UnloadTexture(texturas.churrasquinhoCostas);
    UnloadTexture(texturas.choraoFrente);
    UnloadTexture(texturas.choraoCostas);
    UnloadTexture(texturas.gonzaguinhaFrente);
    UnloadTexture(texturas.gonzaguinhaCostas);
    UnloadTexture(texturas.graminhaFrente);
    UnloadTexture(texturas.graminhaCostas);
    UnloadTexture(texturas.morcegaoFrente);
    UnloadTexture(texturas.morcegaoCostas);
    UnloadTexture(texturas.zeusFrente);
    UnloadTexture(texturas.zeusCostas);
    CloseWindow();
    return 0;
}