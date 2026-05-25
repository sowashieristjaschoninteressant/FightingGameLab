#ifndef SPRITE_H
#define SPRITE_H
#include "common.h"

enum ANIMATION_NAMES {
    ATTACK_1_A,
    ATTACK_2_A,
    DEATH_A,
    FALL_A,
    IDLE_A,
    JUMP_A,
    RUN_A,
    TAKE_HIT_A
};

typedef struct Animation{
    Texture2D texture;
    int frameCount;
    float speed;
}Animation;

typedef struct Sprite{
    Animation animation[8];
    float timer;
    int currentAnimation;
    int frameIndex;
}Sprite;

Sprite createSprite(void);
void updateSprite(Sprite* sprite, const float dt);
void drawSprite(Sprite *sprite, Vector2 pos, int direction, int w, int h);
Animation createAnimation(float speed, int frameCount, const char* filePath);
void destroyAnimations(Sprite* sprite);
Texture2D loadTextureChecked(const char* filePath);
#endif