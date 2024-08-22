#ifndef MOVIMENTACAO_PERSONAGEM_H
#define MOVIMENTACAO_PERSONAGEM_H

int spawnar_grama();
void leitura_movimentos(int *selvagem, Jogador_t *jogadorPrincipal);
int deve_mover(int dx, int dy, int *selvagem, Jogador_t *jogadorPrincipal);
void move(int dx, int dy, Jogador_t *jogadorPrincipal);

#endif