#include "../config/config.h"

static const char *labelBotoesCombate[] = {
    "FIGHT",
    "BAG",
    "POKEMON",
    "RUN"
};

int tentar_fuga() {
    return rand() % 2 == 0;
}

void desenhar_interface_dialogo(const char *mensagem) {
    int larguraCaixa = larguraMonitor * 0.6;
    int alturaCaixa = alturaMonitor * 0.2;
    int xCaixa = (larguraMonitor - larguraCaixa) / 2;
    int yCaixa = alturaMonitor - alturaCaixa - 20;

    DrawRectangle(xCaixa, yCaixa, larguraCaixa, alturaCaixa, LIGHTGRAY);
    DrawRectangleLines(xCaixa, yCaixa, larguraCaixa, alturaCaixa, BLACK);

    // Centralizar o texto
    int larguraTexto = MeasureText(mensagem, 20);
    int xTexto = xCaixa + (larguraCaixa - larguraTexto) / 2;
    int yTexto = yCaixa + (alturaCaixa - 20) / 2;
    DrawText(mensagem, xTexto, yTexto, 20, BLACK);

    DrawText(mensagem, xTexto + 1, yTexto + 1, 20, GRAY);
}

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent) {
    int combateAtivo = true;
    int fugaBemSucedida = false;

    while (combateAtivo) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        int margemSuperior = alturaMonitor * 0.1;
        int margemInferior = alturaMonitor * 0.8;
        int margemLateral = larguraMonitor * 0.1;

        int larguraBarraHP = larguraMonitor * 0.3;
        int alturaBarraHP = alturaMonitor * 0.05;

        DrawText(opponent.nome, margemLateral, margemSuperior, 20, DARKGREEN);
        DrawText(TextFormat("Lv %d", opponent.xp), margemLateral + 200, margemSuperior, 20, DARKGREEN);
        DrawRectangle(margemLateral, margemSuperior + 30, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
        DrawRectangle(margemLateral, margemSuperior + 30, (int)(larguraBarraHP * (float)opponent.vida / opponent.vidaMaxima), alturaBarraHP, RED);

        DrawText(player.nome, margemLateral, margemInferior, 20, DARKGREEN);
        DrawText(TextFormat("Lv %d", player.xp), margemLateral + 200, margemInferior, 20, DARKGREEN);
        DrawRectangle(margemLateral, margemInferior + 30, larguraBarraHP, alturaBarraHP, LIGHTGRAY);
        DrawRectangle(margemLateral, margemInferior + 30, (int)(larguraBarraHP * (float)player.vida / player.vidaMaxima), alturaBarraHP, RED);

        desenhar_opcoes_combate(margemLateral, &fugaBemSucedida, &combateAtivo);
    }
}

void desenhar_opcoes_combate(int margemLateral, int *fugaBemSucedida, int *combateAtivo){
    InterfaceCombate_t ui = {
        .optionsBox = {0, 0, 0, 0},  
        .fightBox = {0, 0, 0, 0},
        .bagBox = {0, 0, 0, 0},
        .pokemonBox = {0, 0, 0, 0},
        .runBox = {0, 0, 0, 0}
    };
    int larguraOpcoes = larguraMonitor * 0.15;
    int alturaOpcoes = alturaMonitor * 0.1;
    int espacamentoOpcoes = larguraMonitor * 0.02;
    int xOpcoes = larguraMonitor - margemLateral - larguraOpcoes / 2;
    int yOpcoes = alturaMonitor - margemLateral - alturaOpcoes / 2 - espacamentoOpcoes;
    int selection = 0;

    ui.fightBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.bagBox = (Rectangle){xOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.pokemonBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};
    ui.runBox = (Rectangle){xOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};

    Rectangle boxes[] = {ui.fightBox, ui.bagBox, ui.pokemonBox, ui.runBox};

    // Desenhando as opções
    for (int i = 0; i < 4; i++) {
        Color cor = (i == selection) ? RED : DARKGRAY;
        DrawRectangleRec(boxes[i], cor);
        DrawText(labelBotoesCombate[i], boxes[i].x + 10, boxes[i].y + 10, 20, WHITE);
    }

    EndDrawing();

    // Navegação com as setas
    if (IsKeyPressed(KEY_RIGHT)) {
        if (selection == 0) selection = 1;
        else if (selection == 1) selection = 0;
        else if (selection == 2) selection = 3;
        else if (selection == 3) selection = 2;
    }
    if (IsKeyPressed(KEY_LEFT)) {
        if (selection == 0) selection = 1;
        else if (selection == 1) selection = 0;
        else if (selection == 2) selection = 3;
        else if (selection == 3) selection = 2;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        if (selection == 0) selection = 2;
        else if (selection == 1) selection = 3;
        else if (selection == 2) selection = 0;
        else if (selection == 3) selection = 1;
    }
    if (IsKeyPressed(KEY_UP)) {
        if (selection == 0) selection = 2;
        else if (selection == 1) selection = 3;
        else if (selection == 2) selection = 0;
        else if (selection == 3) selection = 1;
    }

    // Seleção com a tecla ENTER
    if (IsKeyPressed(KEY_ENTER)) {
        switch (selection) {
            case 0:
                // Implementar ação do botão "FIGHT"
                combateAtivo = false;
                break;
            case 1:
                // Implementar ação do botão "BAG"
                combateAtivo = false;
                break;
            case 2:
                // Implementar ação do botão "POKEMON"
                combateAtivo = false;
                break;
            case 3:
                if (tentar_fuga()) {
                    *fugaBemSucedida = true;
                    *combateAtivo = false;
                } else {
                    // Desenhar mensagem de falha na fuga
                    desenhar_interface_dialogo("FUGA FALHOU!");
                    EndDrawing();
                    WaitTime(2); // Mensagem fica visivel durante 2 segundos
                }
                break;
            default:
                break;
        }
    }
}