#!/bin/bash

# Compilar os arquivos main.c e movimentacaoPersonagem.c
cc main.c movimentacaoPersonagem.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o infmon

# Verificar se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida. Execute ./infmon para rodar o programa."
else
    echo "Erro na compilação."
fi