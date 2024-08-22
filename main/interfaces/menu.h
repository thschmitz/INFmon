#ifndef MENU_H
#define MENU_H

void menu_inicial(Jogador_t *jogadorPrincipal);
void menu_opcoes(Jogador_t *jogadorPrincipal);
void menu_erro();
int salvar_jogo(Jogador_t *jogadorPrincipal);
int carregar_jogo(Jogador_t *jogadorPrincipal);
void novo_jogo(Jogador_t *jogadorPrincipal);

#endif