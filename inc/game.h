#ifndef GAME_H
#define GAME_H
#include "common.h"
#include "input.h"
#include "fighter.h"
#include "player.h"

#define GAME_NAME "fightingGame"
enum gameState {
    MAIN_MENU,
    FIGHT,
    SETTINGS
};



typedef struct Game {
    int width, height;
    int state;
    Player* player_1;
    Player* player_2;
} Game;

Game* createGame(int width, int height);
void initGame(Game* game);
void runGame(Game* game);
void closeGame(Game* game);
void updateGame(Game* game, const float dt);
void renderGame(Game* game, const float dt);


#define GROUND(x) (float)((float)x - 100)

#endif