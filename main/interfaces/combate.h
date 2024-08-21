#ifndef COMBATE_H
#define COMBATE_H

#include "../config/config.h"

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent, Texturas_t texturas);
//void mostrar_tela_combate_inimigo(Jogador_t *playerInimigo, Pokemon_t *player, Texturas_t texturas);
void desenhar_opcoes_combate(InterfaceCombate_t *ui, int *combateAtivo, int *fugaBemSucedida, int *selection, int *menuAtaque, int *menuPokemonsDisponiveis);
void desenha_pokemons_jogador(Pokemon_t *player, Texturas_t *texturas, Texture2D *texturaPlayer);
void desenhar_opcoes_ataque(InterfaceCombate_t *ui, int *selection, int *menuAtaque, Pokemon_t player, Ataque_t ataquesSelecionados[], Pokemon_t *opponent);
void desenhar_interface_dialogo(const char *mensagem);
int measure_text(const char *text, int tamanhoFonte);
Texture2D selecionar_textura(Pokemon_t pokemon, Texturas_t texturas, bool costas);
int tentar_fuga();

#endif
