#include "../config/config.h"

static const char *labelBotoesCombate[] = {
    "FIGHT",
    "BAG",
    "POKEMON",
    "RUN"
};

int tentar_fuga() {
    int saiu = 0;
    int valorAleatorio = rand() % 9;
    if(valorAleatorio <=6){
        saiu = 1;
    }
    return saiu;
}

void desenhar_interface_dialogo(const char *mensagem) {
    int larguraCaixa = larguraMonitor * 0.6;
    int alturaCaixa = alturaMonitor * 0.2;
    int xCaixa = (larguraMonitor - larguraCaixa) / 2;
    int yCaixa = alturaMonitor - alturaCaixa - 20;

    DrawRectangle(xCaixa, yCaixa, larguraCaixa, alturaCaixa, LIGHTGRAY);
    DrawRectangleLines(xCaixa, yCaixa, larguraCaixa, alturaCaixa, BLACK);

    int larguraTexto = MeasureText(mensagem, 20);
    int xTexto = xCaixa + (larguraCaixa - larguraTexto) / 2;
    int yTexto = yCaixa + (alturaCaixa - 20) / 2;
    DrawText(mensagem, xTexto, yTexto, 20, BLACK);

    DrawText(mensagem, xTexto + 1, yTexto + 1, 20, GRAY);
}

void desenhar_opcoes_combate(InterfaceCombate_t *ui, int *combateAtivo, int *fugaBemSucedida, int *selection) {
    Rectangle boxes[] = {ui->fightBox, ui->bagBox, ui->pokemonBox, ui->runBox};

    for (int i = 0; i < 4; i++) {
        Color cor = (i == *selection) ? RED : DARKGRAY;
        DrawRectangleRec(boxes[i], cor);
        int larguraTextoOpcao = MeasureText(labelBotoesCombate[i], 20);
        int xTextoOpcao = boxes[i].x + (boxes[i].width - larguraTextoOpcao) / 2;
        DrawText(labelBotoesCombate[i], xTextoOpcao, boxes[i].y + (boxes[i].height - 20) / 2, 20, WHITE);
    }

    if (IsKeyPressed(KEY_RIGHT) && *selection % 2 == 0) (*selection)++;
    if (IsKeyPressed(KEY_LEFT) && *selection % 2 == 1) (*selection)--;
    if (IsKeyPressed(KEY_DOWN) && *selection < 2) (*selection) += 2;
    if (IsKeyPressed(KEY_UP) && *selection > 1) (*selection) -= 2;

    if (IsKeyPressed(KEY_ENTER)) {
        switch (*selection) {
            case 0:
                // Implementar ação do botão "FIGHT"
                *combateAtivo = false;
                break;
            case 1:
                // Implementar ação do botão "BAG"
                *combateAtivo = false;
                break;
            case 2:
                // Implementar ação do botão "POKEMON"
                *combateAtivo = false;
                break;
            case 3:
                if (tentar_fuga()) {
                    *fugaBemSucedida = true;
                    *combateAtivo = false;
                    menu_inicial_rodando = false;
                    menu_opcoes_rodando = false;
                    menu_batalha_rodando = false;
                } else {
                    desenhar_interface_dialogo("FUGA FALHOU!");
                    menu_inicial_rodando = false;
                    menu_opcoes_rodando = false;
                    EndDrawing();
                    WaitTime(2); // Mensagem fica visível durante 2 segundos
                }
                break;
            default:
                break;
        }
    }
}

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent) {
    int combateAtivo = true;
    int fugaBemSucedida = false;
    int selection = 0;

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
    int xOpcoes = larguraMonitor - larguraOpcoes - espacamentoOpcoes;
    int yOpcoes = alturaMonitor/1.2 - alturaOpcoes - espacamentoOpcoes;

    ui.fightBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.bagBox = (Rectangle){xOpcoes, yOpcoes, larguraOpcoes, alturaOpcoes};
    ui.pokemonBox = (Rectangle){xOpcoes - larguraOpcoes - espacamentoOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};
    ui.runBox = (Rectangle){xOpcoes, yOpcoes + alturaOpcoes + espacamentoOpcoes, larguraOpcoes, alturaOpcoes};

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

        desenhar_opcoes_combate(&ui, &combateAtivo, &fugaBemSucedida, &selection);
        EndDrawing();
    }
}