#ifndef FG_INPUT
#define FG_INPUT
#include "common.h"
#include "fighter.h"
#include "player.h"

typedef struct Game Game;

typedef struct InputState {
    int move; // -1, 0, 1
    bool jump;
    bool attack;
} InputState;

InputState getPlayerInput(Player* player);
void handlePlayerInput(Player* player);
void handleGameInput(Game* game);
#endif