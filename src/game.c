#include <raylib.h>

typedef struct l {
    char character;
    short x;
    short y;
    short speed;
} Letters;


void loadScreen(){

    const char loading[] = "Loading";

    Letters l[7];
    for(int i = 0;i < 7;i++){
        l[i].character = loading[i];
        l[i].x = 300 + (30 * i);
        l[i].y = 0;
        l[i].speed = 5;
    }

    InitWindow(800,1024,"Loading");
    ToggleFullscreen();
    ToggleBorderlessWindowed();
    while(!WindowShouldClose()){

        BeginDrawing();
        
            ClearBackground(BLACK);
            // DrawText("Welcome to the game",100,100,30,WHITE);

        EndDrawing();
    }
    CloseWindow();
}

void startGame(){
    
}   