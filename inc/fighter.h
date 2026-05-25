#ifndef FIGHTER_H
#define FIGHTER_H
#include "common.h"
#include "sprite.h"

typedef struct InputState InputState;
enum FIGHTER_STATE{
    IDLE,
    RUNNING,
    ATTACK,
    JUMP,
    AIR,
};

enum DIRECTION{
    EAST,
    WEST,
};

typedef struct FG_Transform {
    Vector2 pos;
    Vector2 prev_pos;
    Vector2 acc;
    float width, height;
} FG_Transform;

typedef struct Fighter {
    int state;
    int direction;
    int health;
    Color color;
    Sprite sprite;
    FG_Transform transform;
    Rectangle hitbox;
}Fighter;


Fighter* createFighter(Vector2 pos, Color color);
void updateFighter(Fighter* fighter, const float dt);
void applyInputToFighter(Fighter* fighter, InputState input);
void destroyFighter(Fighter* fighter);
void drawFighter( Fighter* fighter, const float dt);
#endif