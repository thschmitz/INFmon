#include "../config/config.h"

typedef struct Interface {
    Rectangle optionsBox;
    Rectangle fightBox;
    Rectangle bagBox;
    Rectangle pokemonBox;
    Rectangle runBox;
} Interface;

void rodar_jogo(Camera2D *camera, Texturas_t *textura){
    //Pokemon_t charmander = {100, 200, 5, "CHARMANDER", "FOGO"};
    //Pokemon_t squirtle = {100, 200, 2, "SQUIRTLE", "AGUA"};

    leitura_movimentos();
    if (IsKeyPressed(KEY_TAB)) {
        menu_opcoes_rodando = true;
        menu_inicial_rodando = false;
        menu_erro_rodando = false;
    }
    
    camera->target.x = jogador.posicaoX;
    camera->target.y= jogador.posicaoY;
    if (jogador.posicaoY < 110) camera->target.y = 110;
    else if (jogador.posicaoY > 610) camera->target.y = 610;
    if (jogador.posicaoX < 193) camera->target.x = 193;
    else if (jogador.posicaoX > 1087) camera->target.x = 1087;

    BeginMode2D(*camera);
    ClearBackground(RAYWHITE);

    //mostrar_tela_combate(charmander, squirtle);
    desenhador_mapa();

    DrawTexture(textura->personagemPrincipal, jogador.posicaoX, jogador.posicaoY, WHITE);
    EndMode2D();
    EndDrawing();
}