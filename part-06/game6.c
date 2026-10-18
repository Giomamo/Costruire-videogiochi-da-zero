#include "raylib.h"
#include "raymath.h"

#define NATIVE_WINDOW_WIDTH 105
#define NATIVE_WINDOW_HEIGHT 60
#define SCALE 10
#define WINDOW_WIDTH NATIVE_WINDOW_WIDTH * SCALE
#define WINDOW_HEIGHT NATIVE_WINDOW_HEIGHT * SCALE
#define SPEED 30 * SCALE

int main(void)
{   
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "window");
    // set execution to 60 frames per second
    SetTargetFPS(60);

    // load image
    Image devittSprite = LoadImage("assets/devitt.png");	
	  // load background texture
    Texture2D hall = LoadTexture("assets/hall.png");
    // load texture
    Texture2D devitt = LoadTexture("assets/devitt.png");

	Rectangle devittCollisionBorder = GetImageAlphaBorder(devittSprite, 0);

    // init position
    Vector2 pos = { (float)46 * SCALE, (float)24 * SCALE } ; 
    // set width, height and offset of image
    Vector2 dimensions = { (float)devittCollisionBorder.width * SCALE, devittCollisionBorder.height * SCALE}; 
	Vector2 offset = { (float)devittCollisionBorder.x * SCALE, (float)devittCollisionBorder.y * SCALE};

    float dt = 0;

    // execute till ESC pressed or clicked on X window
    while (!WindowShouldClose())
    {
        dt = GetFrameTime();
        Vector2 direction = {0, 0};
        Vector2 vel = {0, 0};
        
        // set direction on keypressed (right, left, up, down)
        if (IsKeyDown(KEY_RIGHT)) { 
            direction.x += 1.0f;
            devitt.width = devitt.width; 
        }
        if (IsKeyDown(KEY_LEFT)) { 
            direction.x -= 1.0f; 
            //ImageFlipHorizontal(&devittSprite); 
            devitt.width = -devitt.width;
        }
        
        // normalize direction and calculate velocity
        direction = Vector2Normalize(direction);
		    vel = Vector2Scale(direction, SPEED);
        // update position: pos = pos + (vel * dt)
        pos = Vector2Add(pos, Vector2Scale(vel, dt)); 

        // move image inside window till latest pixel of borders
        pos.x = Clamp(pos.x, -offset.x, WINDOW_WIDTH - dimensions.x - offset.x);
        
        // setup canvas (framebuffer) to start drawing
        BeginDrawing();
            // set background color
            ClearBackground(BLACK);
            DrawTextureEx(hall, (Vector2){0, 0}, 0, SCALE, WHITE);

            // draw texture with scale
            DrawTextureEx(devitt, pos, 0, SCALE, WHITE);

        // end canvas drawing and swap buffers (double buffering)
        EndDrawing(); 
    }

    // release image memory space
    UnloadImage(devittSprite);
    // release textures memory space
    UnloadTexture(hall);
    UnloadTexture(devitt);
    // close window and unload OpenGL context
    CloseWindow();

    return 0;
}
