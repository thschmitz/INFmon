#include "../config/config.h"

typedef struct Interface {
    Rectangle optionsBox;
    Rectangle fightBox;
    Rectangle bagBox;
    Rectangle pokemonBox;
    Rectangle runBox;
} Interface;

void rodar_jogo(Camera2D *camera, Texturas_t *textura, int *selvagem, Jogador_t *jogadorPrincipal){
    leitura_movimentos(selvagem, jogadorPrincipal);
    if (IsKeyPressed(KEY_TAB)) {
        menu_opcoes_rodando = true;
        menu_inicial_rodando = false;
        menu_erro_rodando = false;
    }
    
    camera->target.x = jogadorPrincipal->posicaoX;
    camera->target.y= jogadorPrincipal->posicaoY;
    if (jogadorPrincipal->posicaoY < 110) camera->target.y = 110;
    else if (jogadorPrincipal->posicaoY > 610) camera->target.y = 610;
    if (jogadorPrincipal->posicaoX < 193) camera->target.x = 193;
    else if (jogadorPrincipal->posicaoX > 1087) camera->target.x = 1087;

    BeginMode2D(*camera);
    ClearBackground(RAYWHITE);

    desenhador_mapa();

    DrawTexture(textura->personagemPrincipal, jogadorPrincipal->posicaoX, jogadorPrincipal->posicaoY, WHITE);
    EndMode2D();
    EndDrawing();
}