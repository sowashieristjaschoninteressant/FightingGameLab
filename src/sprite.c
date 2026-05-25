#include "sprite.h"
#include "fighter.h"


Texture2D loadTextureChecked(const char* filePath){
    Texture2D tex = LoadTexture(filePath);

    if(tex.id == 0 ){
        fprintf(stderr, "failed to load texture, path: %s\n", filePath);
    }

    return tex;
}

void updateSprite(Sprite *sprite, const float dt)
{

    Animation *animation = &sprite->animation[sprite->currentAnimation];

    sprite->timer += dt;

    if (sprite->timer >= animation->speed)
    {
        sprite->timer = 0;
        sprite->frameIndex++;

        if (sprite->frameIndex >= animation->frameCount)
        {
            sprite->frameIndex = 0;
        }
    }

    return;
}

void drawSprite(Sprite *sprite, Vector2 pos, int direction, int w, int h)
{

    Animation *animation = &sprite->animation[sprite->currentAnimation];

    int frameWidth = animation->texture.width / animation->frameCount;
    int frameHeight = animation->texture.height;

    Rectangle source = {
        .x = frameWidth * sprite->frameIndex,
        .y = 0,
        .width = frameWidth,
        .height = frameHeight,
    };

    Rectangle destination = {
        .x = pos.x,
        .y = pos.y -100,
        .height = h,
        .width = w};

    if (direction == WEST)
    {
        source.width = -source.width;
    }

    DrawTexturePro(animation->texture, source, destination, (Vector2){0, 0}, 0.0f, WHITE);

    return;
}

void destroyAnimations(Sprite* sprite){

    Animation* animations = sprite->animation; 
    
    for(int i = 0 ; i < 8; i++){
        UnloadTexture(animations[i].texture);
    }

    return;
}

Animation createAnimation(float speed, int frameCount, const char* filePath){
    Animation animation = (Animation) {0};

    assert(speed > 0 && frameCount > 0);

    animation.frameCount = frameCount;
    animation.speed = speed;
    animation.texture = loadTextureChecked(filePath);

    return animation;
}

