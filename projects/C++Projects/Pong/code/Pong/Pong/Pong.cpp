#include <iostream>
#include <raylib.h>

using namespace std;

int main() {

    // Color Chart
    Color Black = Color{ 0, 0, 0, 255 };
    Color White = Color{ 255, 255, 255, 255 };
    Color Dark_Green = Color{ 20, 160, 133, 255 };
    Color Dark_Gray = Color{ 80, 80, 80, 255 };
    Color Dark_Blue = Color{ 0, 82, 172, 255 };


    const int screenWidth = 1280;
    const int screenHeight = 720;
    int ball_x = 100;
    int ball_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;

    cout << "CTEngine (Chrono Tech Engine)" << endl;

    InitWindow(screenWidth, screenHeight, "CTEngine Render Window");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Dark_Blue);
        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if (ball_x + ball_radius >= screenWidth || ball_x - ball_radius <= 0)
        {
            ball_speed_x *= -1;
        }

        if (ball_y + ball_radius >= screenHeight || ball_y - ball_radius <= 0)
        {
            ball_speed_y *= -1;
        }

        DrawCircle(ball_x, ball_y, ball_radius, WHITE);
        EndDrawing();

    }
    
    InitWindow(screenWidth, screenHeight, "CTEngine Render Window 2");
    SetTargetFPS(60);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(Dark_Blue);
        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        if (ball_x + ball_radius >= screenWidth || ball_x - ball_radius <= 0)
        {
            ball_speed_x *= -1;
        }

        if (ball_y + ball_radius >= screenHeight || ball_y - ball_radius <= 0)
        {
            ball_speed_y *= -1;
        }

        DrawCircle(ball_x, ball_y, ball_radius, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}