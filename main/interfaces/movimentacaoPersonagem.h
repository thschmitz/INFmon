#ifndef MOVIMENTACAO_PERSONAGEM_H
#define MOVIMENTACAO_PERSONAGEM_H

int spawnar_grama();
void leitura_movimentos(int *selvagem);
int deve_mover(int dx, int dy, int *selvagem);
void move(int dx, int dy);

#endif