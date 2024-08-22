#include "../config/config.h"

typedef struct Interface {
    Rectangle optionsBox;
    Rectangle fightBox;
    Rectangle bagBox;
    Rectangle pokemonBox;
    Rectangle runBox;
} Interface;

void rodar_jogo(Camera2D *camera, Texturas_t *textura, int *selvagem, Jogador_t *jogadorPrincipal, Pokemon_t pokemonsIniciais[]) {
    if(strlen(jogadorPrincipal->pokemons[0].nome) == 0){
        menu_escolha_pokemon(jogadorPrincipal, pokemonsIniciais);
    }
    leitura_movimentos(selvagem, jogadorPrincipal);
    if (IsKeyPressed(KEY_TAB)) {
        menu_opcoes_rodando = true;
        menu_inicial_rodando = false;
        menu_erro_rodando = false;
    }

    camera->target.x = jogadorPrincipal->posicaoX;
    camera->target.y = jogadorPrincipal->posicaoY;

    // Ajuste de limites de câmera (opcional, dependendo da necessidade do jogo)
    if (jogadorPrincipal->posicaoY < 110) camera->target.y = 110;
    else if (jogadorPrincipal->posicaoY > 610) camera->target.y = 610;
    if (jogadorPrincipal->posicaoX < 193) camera->target.x = 193;
    else if (jogadorPrincipal->posicaoX > 1087) camera->target.x = 1087;

    BeginMode2D(*camera);
    ClearBackground(RAYWHITE);

    desenhador_mapa();

    // Desenha o jogador na posição correta
    DrawTexture(textura->personagemPrincipal, jogadorPrincipal->posicaoX, jogadorPrincipal->posicaoY, WHITE);
    
    EndMode2D();
    EndDrawing();
}