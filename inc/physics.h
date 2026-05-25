#ifndef PHYSICS_H
#define PHYSICS_H
typedef struct FG_Transform FG_Transform;
typedef struct Vector2 Vector2;

void integrateVerlet(FG_Transform* transform, const float dt);
void applyGravity(FG_Transform* transform);

float getVelocity(float prev, float current, const float dt);

#define MOV_ACC 5500.0f
#define GRAVITY 1000.0f
#define JUMPING_ACC -15000.0f
#endif
