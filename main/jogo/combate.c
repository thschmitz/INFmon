#include "../config/config.h"

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent){
    InterfaceCombate_t ui = {
        .optionsBox = {50, 350, 700, 100},
        .fightBox = {60, 360, 160, 80},
        .bagBox = {240, 360, 160, 80},
        .pokemonBox = {420, 360, 160, 80},
        .runBox = {600, 360, 160, 80}
    };
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Posicionamento baseado na largura e altura do monitor
    int margemSuperior = alturaMonitor * 0.1;
    int margemInferior = alturaMonitor * 0.8;
    int margemLateral = larguraMonitor * 0.1;

    int larguraBarraHP = larguraMonitor * 0.3;
    int alturaBarraHP = alturaMonitor * 0.05;

    // Desenhando informações do oponente
    DrawText(opponent.nome, margemLateral, margemSuperior, 20, DARKGREEN);
    DrawText(TextFormat("Lv %d", opponent.xp), margemLateral + 200, margemSuperior, 20, DARKGREEN);
    DrawRectangle(margemLateral, margemSuperior + 30, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
    DrawRectangle(margemLateral, margemSuperior + 30, (int)(larguraBarraHP * (float)opponent.vida / opponent.vidaMaxima), alturaBarraHP, RED);

    // Desenhando informações do jogador
    DrawText(player.nome, margemLateral, margemInferior, 20, DARKGREEN);
    DrawText(TextFormat("Lv %d", player.xp), margemLateral + 200, margemInferior, 20, DARKGREEN);
    DrawRectangle(margemLateral, margemInferior + 30, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
    DrawRectangle(margemLateral, margemInferior + 30, (int)(larguraBarraHP * (float)player.vida / player.vidaMaxima), alturaBarraHP, RED);

    // Ajuste das caixas de opções
    int larguraOpcoes = larguraMonitor * 0.15;
    int alturaOpcoes = alturaMonitor * 0.1;
    int espacamentoOpcoes = larguraMonitor * 0.02;

    ui.fightBox = (Rectangle){margemLateral, margemInferior + 100, larguraOpcoes, alturaOpcoes};
    ui.bagBox = (Rectangle){margemLateral + larguraOpcoes + espacamentoOpcoes, margemInferior + 100, larguraOpcoes, alturaOpcoes};
    ui.pokemonBox = (Rectangle){margemLateral + 2 * (larguraOpcoes + espacamentoOpcoes), margemInferior + 100, larguraOpcoes, alturaOpcoes};
    ui.runBox = (Rectangle){margemLateral + 3 * (larguraOpcoes + espacamentoOpcoes), margemInferior + 100, larguraOpcoes, alturaOpcoes};

    DrawRectangleRec(ui.fightBox, DARKGRAY);
    DrawText("FIGHT", ui.fightBox.x + 10, ui.fightBox.y + 10, 20, WHITE);
    DrawRectangleRec(ui.bagBox, DARKGRAY);
    DrawText("BAG", ui.bagBox.x + 10, ui.bagBox.y + 10, 20, WHITE);
    DrawRectangleRec(ui.pokemonBox, DARKGRAY);
    DrawText("POKEMON", ui.pokemonBox.x + 10, ui.pokemonBox.y + 10, 20, WHITE);
    DrawRectangleRec(ui.runBox, DARKGRAY);
    DrawText("RUN", ui.runBox.x + 10, ui.runBox.y + 10, 20, WHITE);

    EndDrawing();
}