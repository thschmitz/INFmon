#include "raylib.h"
#include <string.h>

int main(void){
    const int screenWidth = 600;
    const int screenHeight = 600;
    char texto[50] = "Pressione uma seta";

    InitWindow(screenWidth, screenHeight, "Quadrado");
    SetTargetFPS(60);

    int flagBlocoTela = 1;
    int boxPositionY = screenHeight/2 - 40;
    int boxPositionX = screenWidth/2 - 40;

    while (!WindowShouldClose() && flagBlocoTela) {

        ClearBackground(RAYWHITE);

        if (IsKeyPressed(KEY_RIGHT)){
            strcpy(texto,"Direita");
            boxPositionX += 20;
        }

        if (IsKeyPressed(KEY_LEFT)) {
            strcpy(texto,"Esquerda");
            boxPositionX -= 20;
        }
        if (IsKeyPressed(KEY_UP)){
            strcpy(texto,"Cima");
            boxPositionY -= 20;
        }
        if (IsKeyPressed(KEY_DOWN)) {
            strcpy(texto,"Baixo");
            boxPositionY += 20;
        }

        BeginDrawing();

        DrawRectangle(boxPositionX, boxPositionY, 20, 20, GREEN);

        DrawText("Use keyboard to move the cube up and down!", 10, 10, 20, GRAY);
        DrawText(texto, 50, 50, 40, RED);


        EndDrawing();

        if(boxPositionX > 580 || boxPositionY > 580 || boxPositionY < 0 || boxPositionX < 0) {
            flagBlocoTela = 0;
        }
    }

    CloseWindow();

    return 0;
}