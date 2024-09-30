#include "raylib.h"
#include "colors.h"
#include "game.h"
#include <iostream>

double lastUpdatedTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdatedTime >= interval)
    {
        lastUpdatedTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(550, 600, "Tetris");
    SetTargetFPS(60);
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Game game = Game();
    while (!WindowShouldClose())
    {
        game.PlayerInput();
        if (EventTriggered(0.2))
        {
            game.MoveDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", { 360,15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 375,145 }, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "Game Over", { 330,450 }, 38, 2, WHITE);
            DrawTextEx(font, "Press Enter", { 310,490 }, 37, 2, WHITE);
        }
        DrawRectangleRounded({ 330,55,170,60 }, 0.3, 6, lightBlue);
       char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2,65 }, 38, 2, WHITE);

        DrawRectangleRounded({ 330,190,170,160 }, 0.3, 6, lightBlue);
        game.DrawGame();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}