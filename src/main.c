#include <raylib.h>
#include <string.h>
#include <stdio.h> 

typedef struct Letter {
    char character;
    float x;
    float y;
    float targetY;
    float speed;
    bool reachedTarget;
} Letter;


int main(int argc,char ** argv)
{
    // Initialization
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int charSize = 40;

    InitWindow(screenWidth, screenHeight, "raylib [text] example - moving characters to middle");
    ToggleBorderlessWindowed();
    ToggleFullscreen();
    ToggleFullscreen();

    const char *phrase = argc == 2 ? argv[1] : "antonio";
    int length = strlen(phrase);
    Letter letters[length];

    float startX = screenWidth / 2 - ((strlen(phrase) / 2) * charSize);
    float startY = -20; // Starting y position (above the screen)
    float middleY = screenHeight / 2;
    float delay = 0.5f;  // Delay between each character appearing
    float timePassed = 0.0f;
    int lettersShown = 0;

    // Initialize letters
    for (int i = 0; i < length; i++) {
        letters[i].character = phrase[i];
        letters[i].x = startX + (charSize * i);
        letters[i].y = startY;
        letters[i].targetY = middleY;
        letters[i].speed = 700.0f; // Speed at which characters move
        letters[i].reachedTarget = false;
    }

    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        // Update
        timePassed += GetFrameTime();

        // Show letters sequentially based on delay
        if (lettersShown < length && timePassed >= delay) {
            lettersShown++;
            timePassed = 0.0f;
        }

        for (int i = 0; i < lettersShown; i++) {
            if (!letters[i].reachedTarget) {
                letters[i].y += letters[i].speed * GetFrameTime();
                if (letters[i].y >= letters[i].targetY) {
                    letters[i].y = letters[i].targetY;
                    letters[i].reachedTarget = true;
                }
            }
        }

        // Draw
        BeginDrawing();
        
        ClearBackground(BLACK);

        for (int i = 0; i < lettersShown; i++) {
            DrawText(TextFormat("%c", letters[i].character), letters[i].x, letters[i].y, charSize, GREEN);
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context

    return 0;
}