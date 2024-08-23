#ifndef COMBATE_H
#define COMBATE_H

#include "../config/config.h"

void mostrar_tela_combate(Pokemon_t player, Pokemon_t opponent, Texturas_t texturas, Jogador_t *jogadorPrincipal, int *selvagem);
//void mostrar_tela_combate_inimigo(Jogador_t *playerInimigo, Pokemon_t *player, Texturas_t texturas);
void desenha_pokemons_jogador(Pokemon_t *player, Texturas_t *texturas, Texture2D *texturaPlayer, Jogador_t *jogadorPrincipal, Pokemon_t *opponent, int *combateAtivo, int *pokemonSelecionado, int *menuPokemonsDisponiveis);
void desenhar_opcoes_combate(InterfaceCombate_t *ui, int *combateAtivo, int *fugaBemSucedida, int *selection, int *menuAtaque, int *menuPokemonsDisponiveis, Pokemon_t *opponent, Jogador_t *jogadorPrincipal, Pokemon_t *player, Texture2D *texturaPlayer, Texturas_t texturas, int *selvagem);
void desenhar_opcoes_ataque(InterfaceCombate_t *ui, int *selection, int *menuAtaque, Pokemon_t *player, Ataque_t ataquesSelecionados[], Pokemon_t *opponent, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *jogadorPrincipal, int *selvagem);
void desenhar_interface_dialogo(const char *mensagem);
int measure_text(const char *text, int tamanhoFonte);
Texture2D selecionar_textura(Pokemon_t pokemon, Texturas_t texturas, bool costas);

void ataqueOponente(Pokemon_t *opponent, Pokemon_t *player, Ataque_t ataqueOponente, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *jogadorPrincipal);

void ataqueOponente_inimigo(Pokemon_t *opponent, Pokemon_t *player, Ataque_t ataqueOponente, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *opponentJogador, Jogador_t *jogadorPrincipal, int *selvagem);
void mostrar_tela_combate_inimigo(Pokemon_t player, Jogador_t opponent, Texturas_t texturas, Jogador_t *jogadorPrincipal, int *faseAtual, int *selvagem);
int jogador_tem_pokemons_vivos(Jogador_t *jogadorPrincipal);
void atualizar_lista_pokemons(Jogador_t *jogadorPrincipal);
int tentar_fuga();
int tipagem_pokemon(Pokemon_t pokemon);
void desenhar_opcoes_ataque_inimigo(InterfaceCombate_t *ui, int *selection, int *menuAtaque, Pokemon_t *player, Ataque_t ataquesSelecionados[], Pokemon_t *opponent, Texturas_t texturas, Texture2D *texturaPlayer, int *combateAtivo, Jogador_t *opponentJogador, Jogador_t *jogadorPrincipal, Texture2D *texturaOpponent, int *faseAtual, int *selvagem);
Jogador_t configurar_oponente(Jogador_t jogador, Jogador_t jogadorPrincipal);
void desenhar_opcoes_combate_inimigo(InterfaceCombate_t *ui, int *combateAtivo, int *selection, int *menuAtaque, int *menuPokemonsDisponiveis, Pokemon_t *opponent, Jogador_t *jogadorPrincipal, Pokemon_t *player, Texture2D *texturaPlayer, Texturas_t texturas);
void mostrar_tela_final(Jogador_t *jogadorPrincipal);

#endif
