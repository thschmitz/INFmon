#ifndef COMBATE_H
#define COMBATE_H

#include "../config/config.h"

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent);
void desenhar_opcoes_combate(int margemLateral, int *fugaBemSucedida, int *combateAtivo);
int tentar_fuga();

#endif
