#ifndef MOVIMENTACAO_PERSONAGEM_H
#define MOVIMENTACAO_PERSONAGEM_H

void leitura_movimentos();
int deveMover(int x, int y, int dx, int dy);
void move(int dx, int dy, int *x, int *y);

#endif