#include "fighter.h"
#include "physics.h"
#include "input.h"


Fighter* createFighter(Vector2 pos, Color color){
    Fighter* fighter = calloc(1, sizeof(Fighter));
    assert(fighter);
    FG_Transform* transform = &fighter->transform;

    fighter->health = 100;
    transform->acc = (Vector2) { 0 };
    transform->pos = pos;
    transform->prev_pos = pos;
    transform->height = 100;
    transform->width = 100;
    
    fighter->direction = EAST;
    fighter->color = color;

    // TODO: remove animation loading from the fighter
    // for safety of the current flight 

    fighter->sprite = (Sprite) {0};
    Animation* animations = fighter->sprite.animation;
    animations[IDLE_A] = createAnimation(0.1f,8, "./assets/MidnightSlash/Idle.png");
    animations[RUN_A] = createAnimation(0.1f,8, "./assets/MidnightSlash/Run.png");
    animations[JUMP_A] = createAnimation(0.1f,2, "./assets/MidnightSlash/Jump.png");
    animations[ATTACK_1_A] = createAnimation(0.1f,6, "./assets/MidnightSlash/Attack1.png");
    animations[FALL_A] = createAnimation(0.1f,2, "./assets/MidnightSlash/Fall.png");

    fighter->hitbox = (Rectangle) {
         .height = fighter->transform.height,
         .width = transform->width,
         .x = transform->pos.x,
         .y = transform->pos.y
        };
 
    return fighter;
}

void updateFighter(Fighter* fighter, const float dt){
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    FG_Transform* t = &fighter->transform;

    float velocityY = getVelocity(fighter->transform.prev_pos.y, fighter->transform.pos.y, dt);

    int newAni = 0;
    if(fighter->state == IDLE) newAni = IDLE_A;
    if(fighter->state == RUNNING) newAni = RUN_A; 
    if(fighter->state == JUMP) newAni = JUMP_A;
    if(fighter->state == ATTACK) newAni = ATTACK_1_A;

    if(fighter->transform.pos.y < screenHeight - 100 && velocityY > 0 ){
        newAni = FALL_A;
        fighter->state = AIR;
    }


    if(fighter->sprite.currentAnimation != newAni){
        fighter->sprite.currentAnimation = newAni;
        fighter->sprite.timer = 0;
    }

    t->acc.y += GRAVITY;

    integrateVerlet(t, dt);

    if(t->pos.x < 0 ){
        t->pos.x = 0;
        t->prev_pos.x = t->pos.x;
    }

    if(t->pos.x + t->width >= screenWidth){
        t->pos.x = screenWidth - t->width;
        t->prev_pos.x = t->pos.x;
    }

    if(t->pos.y >= screenHeight - t->height){
        t->pos.y = screenHeight - t->height;
        t->prev_pos.y = t->pos.y;
    }

    if (t->pos.y < 0) {
        t->pos.y = 0;
        t->prev_pos.y = t->pos.y;
    }

    fighter->hitbox.x = t->pos.x;
    fighter->hitbox.y = t->pos.y;
}

void applyInputToFighter(Fighter* fighter, InputState input){

    FG_Transform* t = &fighter->transform;

    t->acc.x = 0;
    if(input.move == -1){
        t->acc.x = -MOV_ACC;
        fighter->direction = WEST;
        fighter->state = RUNNING;
    }else if(input.move == 1){
        t->acc.x = MOV_ACC;
        fighter->direction = EAST;
        fighter->state = RUNNING;
    }else{
        fighter->state = IDLE;
    }
    
    if(input.jump){
        fighter->state = JUMP;
        t->acc.y = JUMPING_ACC;
    }

    if(input.attack){
        fighter->state = ATTACK;
    }

    return;
}

void drawFighter( Fighter* fighter, const float dt){
    Sprite* sprite = &fighter->sprite;
    FG_Transform* transform = &fighter->transform;
    
    updateSprite(sprite, dt);
    drawSprite(sprite, transform->pos,fighter->direction, transform->width + 100, transform->height + 100);
}

void destroyFighter(Fighter* fighter){

    destroyAnimations(&fighter->sprite);
    free(fighter);
}