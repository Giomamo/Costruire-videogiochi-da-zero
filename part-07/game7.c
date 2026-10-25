#include "raylib.h"
#include "raymath.h"

#define NATIVE_WINDOW_WIDTH 105
#define NATIVE_WINDOW_HEIGHT 60
#define SCALE 10
#define WINDOW_WIDTH NATIVE_WINDOW_WIDTH * SCALE
#define WINDOW_HEIGHT NATIVE_WINDOW_HEIGHT * SCALE
#define SPEED 30 * SCALE
#define FRAME_DURATION 0.1

int main(void)
{   
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "window");

    // load image
    Image devittSprite = LoadImage("assets/devitt.png");

    // textures to simulate walking
    Texture2D devittWalkFrames[] = {
        LoadTexture("assets/devitt_walk_1.png"),
        LoadTexture("assets/devitt_walk_2.png"),
        LoadTexture("assets/devitt_walk_3.png"),
        LoadTexture("assets/devitt_walk_4.png"),
        LoadTexture("assets/devitt_walk_5.png"),
        LoadTexture("assets/devitt_walk_6.png"),
        LoadTexture("assets/devitt_walk_7.png"),
        LoadTexture("assets/devitt_walk_8.png"),
    };

    int animationFrame = 0;
	float animationFrameTimer = 0;
    int facingLeft = 0; //boolean

	// load background texture
    Texture2D hall = LoadTexture("assets/hall.png");
    // load texture
    Texture2D devitt = LoadTexture("assets/devitt.png");

	Rectangle devittCollisionBorder = GetImageAlphaBorder(devittSprite, 0);

    // init rectangle position
    Vector2 pos = { (float)46 * SCALE, (float)24 * SCALE }; 
    // set width, height and offset of image
    Vector2 dimensions = { (float)devittCollisionBorder.width * SCALE, devittCollisionBorder.height * SCALE}; 
	Vector2 offset = { (float)devittCollisionBorder.x * SCALE, (float)devittCollisionBorder.y * SCALE};

    float dt = 0;
    // set execution to 60 frames per second
    SetTargetFPS(60);

    // execute till ESC pressed or clicked on X window
    while (!WindowShouldClose())
    {
        dt = GetFrameTime();
        Vector2 direction = {0, 0};
        Vector2 vel = {0, 0};
        
        // set direction on keypressed (right, left)
        if (IsKeyDown(KEY_RIGHT)) direction.x += 1.0f;
        if (IsKeyDown(KEY_LEFT)) direction.x -= 1.0f;
        
        // normalize direction and calculate velocity
        direction = Vector2Normalize(direction);
		vel = Vector2Scale(direction, SPEED);
        // update position: pos = pos + (vel * dt)
        pos = Vector2Add(pos, Vector2Scale(vel, dt)); 

        // move image inside window till latest pixel of borders
        pos.x = Clamp(pos.x, -offset.x, WINDOW_WIDTH - dimensions.x - offset.x);

        if (direction.x == -1) facingLeft = 1;
		if (direction.x == 1) facingLeft = 0;

        // source rectangle (portion of texture to be drawn)
		Rectangle source = {0, 0, (float)devitt.width, (float)devitt.height};
		
        if (facingLeft) source.width = -source.width;

        // destination rectangle
		Rectangle dest = {pos.x, pos.y, (float)devitt.width * SCALE, (float)devitt.height * SCALE};
        
        // setup canvas (framebuffer) to start drawing
        BeginDrawing();
            // set background color
            ClearBackground(BLACK);
            DrawTextureEx(hall, (Vector2){0, 0}, 0, SCALE, WHITE);

            if (direction.x == 0) {
                DrawTexturePro(devitt, source, dest, (Vector2){0, 0}, 0, WHITE);
                animationFrame = 0;
                animationFrameTimer = 0;
            } else {
                animationFrameTimer += dt;
                if (animationFrameTimer >= FRAME_DURATION) {
                    animationFrameTimer = 0;
                    animationFrame += 1;
                    if (animationFrame == 8) animationFrame = 0;
                }

                // draw texture with scale
                DrawTexturePro(devittWalkFrames[animationFrame], source, dest, (Vector2){0, 0}, 0, WHITE);
            }

        // end canvas drawing and swap buffers (double buffering)
        EndDrawing(); 
    }

    // release image memory space
    UnloadImage(devittSprite);
    // release texture memory space
    UnloadTexture(hall);
    UnloadTexture(devitt);
    UnloadTexture(devittWalkFrames[0]);
    UnloadTexture(devittWalkFrames[1]);
    UnloadTexture(devittWalkFrames[2]);
    UnloadTexture(devittWalkFrames[3]);
    UnloadTexture(devittWalkFrames[4]);
    UnloadTexture(devittWalkFrames[5]);
    UnloadTexture(devittWalkFrames[6]);
    UnloadTexture(devittWalkFrames[7]);
    // close window and unload OpenGL context
    CloseWindow();

    return 0;
}
