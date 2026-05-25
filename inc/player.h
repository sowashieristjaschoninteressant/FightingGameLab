#ifndef PLAYER_H
#define PLAYER_H
#include "common.h"
#include "fighter.h"
typedef struct {
    int up,down,left,right,attack;
} Controls;

typedef struct{
    Controls controls;
    Fighter* fighter;
} Player;

Player* createPlayer(Controls controls, Vector2 pos, Color color);
void updatePlayer(Player* player, const float dt);
void destroyPlayer(Player* player);

#endif