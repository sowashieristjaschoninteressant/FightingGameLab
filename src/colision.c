#include "colision.h"
#include "fighter.h"

void checkcolision(Fighter* fighter1, Fighter* fighter2){

    if(fighter1->hitbox.x + fighter1->hitbox.width >= fighter2->hitbox.x &&
         fighter1->hitbox.x < fighter2->hitbox.x + fighter2->hitbox.width && fighter1->hitbox.y >= (fighter2->hitbox.y - fighter2->hitbox.height)
        ){
        fighter1->transform.pos.x = fighter1->transform.prev_pos.x;
        fighter1->hitbox.x = fighter1->transform.pos.x;
        fighter1->transform.pos.y = fighter1->transform.prev_pos.y;
        fighter1->hitbox.y = fighter1->transform.pos.y;
    }

  
    


}