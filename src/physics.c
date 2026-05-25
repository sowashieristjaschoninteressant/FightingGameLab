#include "physics.h"
#include "common.h"
#include "fighter.h"

void integrateVerlet(FG_Transform* transform, const float dt){

    const Vector2 current = transform->pos;
    const Vector2 acc = transform->acc;

    Vector2 velocity = {
        current.x - transform->prev_pos.x,
        current.y - transform->prev_pos.y
    };

    velocity.x *= 0.90f;
    velocity.y *= 0.90f;

    transform->pos.x = current.x + velocity.x + acc.x * dt * dt;
    transform->pos.y = current.y + velocity.y + acc.y * dt * dt;

    transform->prev_pos = current;
}


float getVelocity(float prev, float current, const float dt){
    
    return (current - prev) / dt;
}