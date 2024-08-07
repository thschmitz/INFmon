#ifndef COMBATE_H
#define COMBATE_H

#include "../config/config.h"

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent);
void desenhar_opcoes_combate(InterfaceCombate_t *ui, int *combateAtivo, int *fugaBemSucedida, int *selection);
void desenhar_interface_dialogo(const char *mensagem);
int tentar_fuga();

#endif
