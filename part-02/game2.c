#include "raylib.h"
#include "raymath.h" // required for Vector2Add and Vector2Scale

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 640
#define SPEED 100

int main(void)
{
    float dt = 0;

    Vector2 pos = { 100.0f, 100.0f };      // init rectangle position
    Vector2 vel  = {100, 0};               // speed vector (100 pixels per second)
    Vector2 dimensions = { 80.0f, 50.0f }; // set width and height rectangle

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "window");

    SetTargetFPS(60); // set execution to 60 frames per second

    while (!WindowShouldClose()) // execute till ESC pressed or clicked on X window
    {
        dt = GetFrameTime();    // get delta time (time elapsed since last frame)
        BeginDrawing();         // setup canvas (framebuffer) to start drawing
        ClearBackground(BLACK); // set background color
        
        pos = Vector2Add(pos, Vector2Scale(vel, dt)); // get next frame position
        
        DrawRectangleV(pos, dimensions, BLUE); // draw rectangle of dimensions(w,h) at pos(x,y)
        EndDrawing(); // end canvas drawing and swap buffers (double buffering)
    }

    CloseWindow(); // close window and unload OpenGL context

    return 0;
}
