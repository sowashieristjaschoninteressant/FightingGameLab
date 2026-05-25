#include "game.h"
#include "colision.h"
Game* createGame(int width, int height){
    Game* game = calloc(1,sizeof(Game));
    assert(game);

    game->state = FIGHT;
    game->width = width;
    game->height = height;

    initGame(game);
    return game;
}

void initGame(Game* game){
    const int targetFPS = 60;
    Controls count1 = (Controls) { 
      .attack = KEY_SPACE,
      .left = KEY_A,
      .right = KEY_D,
      .down = KEY_S,
      .up = KEY_W,
    };

    Controls count2 = (Controls){
        .attack = KEY_K,
        .left = KEY_LEFT,
        .right = KEY_RIGHT,
        .up  = KEY_UP,
        .down = KEY_DOWN,
    };

    InitWindow(game->width, game->height, GAME_NAME);
    game->player_1 = createPlayer(count1, (Vector2) {.x = game->width / 4, .y = GROUND(game->height)}, RED);
    game->player_2 = createPlayer(count2, (Vector2){.x = game->width / 4 * 2, .y  = game->height - 100}, BLUE);
    SetTargetFPS(targetFPS);
}

void runGame(Game* game){

    
    while(!WindowShouldClose()){
        const float dt = GetFrameTime();

        handleGameInput(game);
        updateGame(game, dt);
        renderGame(game, dt);
    }
    
    closeGame(game);
}



void updateGame(Game* game, const float dt){
    updatePlayer(game->player_1, dt);
    updatePlayer(game->player_2, dt);
    checkcolision(game->player_1->fighter,game->player_2->fighter);
}

void renderGame(Game* game, const float dt){
    Player* player1 = game->player_1;
    Player* player2 = game->player_2;
    BeginDrawing();
      ClearBackground(GRAY);
      DrawFPS(5,5);
      DrawText("raylib! working!", 200,250, 20,RED);
      drawFighter(player1->fighter, dt);
      drawFighter(player2->fighter, dt);
    EndDrawing();
}

void closeGame(Game* game){
    destroyPlayer(game->player_1);
    destroyPlayer(game->player_2);
    CloseWindow();
    free(game);
}