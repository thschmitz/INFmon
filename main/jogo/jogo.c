#include "../config/config.h"

typedef struct Interface {
    Rectangle optionsBox;
    Rectangle fightBox;
    Rectangle bagBox;
    Rectangle pokemonBox;
    Rectangle runBox;
} Interface;

void rodar_jogo(Camera2D *camera, Texturas_t *textura){
    Pokemon_t charmander = {100, 200, 5, "CHARMANDER", "FOGO"};
    Pokemon_t squirtle = {100, 200, 2, "SQUIRTLE", "AGUA"};

    leitura_movimentos();
    if (IsKeyPressed(KEY_TAB)) {
        menu_opcoes_rodando = true;
        menu_inicial_rodando = false;
        menu_erro_rodando = false;
    }
    
    camera->target.x = jogador.posicaoX;
    camera->target.y= jogador.posicaoY;
    if (jogador.posicaoY < 140) camera->target.y = 140;
    else if (jogador.posicaoY > 580) camera->target.y = 580;
    if (jogador.posicaoX < 240) camera->target.x = 240;
    else if (jogador.posicaoX > 1040) camera->target.x = 1040;

    BeginMode2D(*camera);
    ClearBackground(RAYWHITE);
    desenhar_mapa();

    //mostrar_tela_combate(charmander, squirtle);


    DrawTexture(textura->personagemPrincipal, jogador.posicaoX, jogador.posicaoY, WHITE);
    EndDrawing();
    EndMode2D();
    EndDrawing();
}