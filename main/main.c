#include "./config/config.h"

int main() {
    InitRandomSeed();
    InitWindow(COLUNAS_MAPA * LADO, LINHAS_MAPA * LADO, tituloProjeto);
    int selvagem = 0;
    larguraMonitor = GetMonitorWidth(GetCurrentMonitor());
    alturaMonitor = GetMonitorHeight(GetCurrentMonitor());
    Jogador_t jogadorPrincipal;

    Ataque_t ataque1 = {"TESTE1", 50.5, 42, "NORMAL"};
    Ataque_t ataque2 = {"TESTE2", 12.5, 42, "NORMAL"};
    Ataque_t ataque3 = {"TESTE3", 43.5, 42, "NORMAL"};
    Ataque_t ataque4 = {"TESTE4", 89.5, 42, "NORMAL"};
    Ataque_t ataque5 = {"TESTE5", 100.5, 42, "NORMAL"};
    Ataque_t ataque6 = {"TESTE6", 34.5, 42, "NORMAL"};
    Ataque_t ataques[] = {ataque1, ataque2, ataque3, ataque4, ataque5, ataque6};

    Pokemon_t charmander = {
        .ataques = {ataque1, ataque2, ataque3, ataque4},
        .defesa = 20,
        .vida = 10,
        .vidaMaxima = 200,
        .xp = 5,
        .nome = "CHURRASQUINHO",
        .tipoPokemon = "FOGO"
    };

    Pokemon_t lapras = {
        .ataques = {ataque1, ataque2, ataque3, ataque4},
        .defesa = 20,
        .vida = 100,
        .vidaMaxima = 200,
        .xp = 2,
        .nome = "CHORAO",
        .tipoPokemon = "AGUA"
    };

    Pokemon_t graminha = {
        .ataques = {ataque1, ataque2, ataque3, ataque4},
        .defesa = 20,
        .vida = 100,
        .vidaMaxima = 200,
        .xp = 2,
        .nome = "GRAMINHA",
        .tipoPokemon = "GRAMA"
    };

    Pokemon_t zubat = {
        .ataques = {ataque1, ataque2, ataque3, ataque4},
        .defesa = 20,
        .vida = 100,
        .vidaMaxima = 200,
        .xp = 2,
        .nome = "MORCEGAO",
        .tipoPokemon = "VOADOR"
    };

    Pokemon_t diglett = {
        .ataques = {ataque1, ataque2, ataque3, ataque4},
        .defesa = 20,
        .vida = 100,
        .vidaMaxima = 200,
        .xp = 2,
        .nome = "GONZAGUINHA",
        .tipoPokemon = "TERRA"
    };

    Pokemon_t pikachu = {
        .ataques = {ataque1, ataque2, ataque3, ataque4},
        .defesa = 20,
        .vida = 100,
        .vidaMaxima = 200,
        .xp = 2,
        .nome = "ZEUS",
        .tipoPokemon = "ELETRICO"
    };

    jogadorPrincipal.pokemons[0] = charmander;
    jogadorPrincipal.pokemons[1] = lapras;
    jogadorPrincipal.pokemons[2] = graminha;
    jogadorPrincipal.pokemons[3] = zubat;
    jogadorPrincipal.pokemons[4] = diglett;
    jogadorPrincipal.pokemons[5] = pikachu;

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
                mostrar_tela_combate(charmander, lapras, texturas, &jogadorPrincipal);
            } else {
                // mostrar_tela_combate_inimigo(opponent, );
            }

        } else {
            rodar_jogo(&camera, &texturas, &selvagem, &jogadorPrincipal);

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