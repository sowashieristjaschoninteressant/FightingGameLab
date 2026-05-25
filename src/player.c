
#include "player.h"
#include "fighter.h"

Player* createPlayer(Controls controls, Vector2 pos, Color color){
    Player* player = calloc(1, sizeof(Player));
    assert(player);
    
    player->fighter = createFighter(pos, color);
    player->controls = controls;
    return player;

}
void updatePlayer(Player* player, const float dt){
    updateFighter(player->fighter, dt);
    

}
void destroyPlayer(Player* player){

    destroyFighter(player->fighter);
    free(player);
}