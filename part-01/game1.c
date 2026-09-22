#include "raylib.h"

int main(void)
{
    InitWindow(320, 100, "window");

    while (!WindowShouldClose()) // execute till ESC pressed or clicked on X window
    {
        BeginDrawing();         // setup canvas (framebuffer) to start drawing
        ClearBackground(BLACK); // set background color
        EndDrawing();           // end canvas drawing and swap buffers (double buffering)
    }

    CloseWindow(); // close window and unload OpenGL context

    return 0;
}
