#include "raylib.h"
#include "raymath.h" // required for Vector2Add, Vector2Scale and Vector2Normalize

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 640
#define SPEED 100

int main(void)
{
    float dt = 0;

    Vector2 pos = { 100.0f, 100.0f }; // init rectangle position
    Vector2 dimensions = { 80.0f, 50.0f }; // set width and height rectangle

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "window");

    SetTargetFPS(60); // set execution to 60 frames per second

    while (!WindowShouldClose()) // execute till ESC pressed or clicked on X window
    {
        BeginDrawing();         // setup canvas (framebuffer) to start drawing
        ClearBackground(BLACK); // set background color
        dt = GetFrameTime();    // get delta time (time elapsed since last frame)
        Vector2 direction = {0, 0};
        Vector2 vel = {0, 0};
        
        // set direction on keypressed (right, left, up, down)
        if (IsKeyDown(KEY_RIGHT)) { direction.x += 1.0f; }
        if (IsKeyDown(KEY_LEFT))  { direction.x -= 1.0f; }
        if (IsKeyDown(KEY_UP))    { direction.y -= 1.0f; }
        if (IsKeyDown(KEY_DOWN))  { direction.y += 1.0f; }
        
        // normalize direction and calculate velocity
        direction = Vector2Normalize(direction);
		    vel = Vector2Scale(direction, SPEED);
        pos = Vector2Add(pos, Vector2Scale(vel, dt)); // update position: pos = pos + (vel * dt)
        
        DrawRectangleV(pos, dimensions, BLUE); // draw rectangle of dimensions(w,h) at pos(x,y)
        EndDrawing(); // end canvas drawing and swap buffers (double buffering)
    }

    CloseWindow(); // close window and unload OpenGL context

    return 0;
}
