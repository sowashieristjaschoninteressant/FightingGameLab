#include "input.h"
#include "game.h"

InputState getPlayerInput(Player* player){
    InputState inputState = (InputState) {0};

    if(IsKeyDown(player->controls.left)){
         inputState.move = -1;
    }

    if(IsKeyDown(player->controls.right)){
        inputState.move = 1;
    }

    if(IsKeyDown(player->controls.up)){
        inputState.jump = true;
    }

    if(IsKeyDown(player->controls.attack)){
        inputState.attack = true;
        // start hitbox for now
    }

    return inputState;

}

void handleGameInput(Game* game){
    Player* player1 = game->player_1;
    Player* player2 = game->player_2;

    assert(player1 && player2);
    
    InputState input1 = getPlayerInput(player1);
    InputState input2 = getPlayerInput(player2);

    applyInputToFighter(player1->fighter, input1);
    applyInputToFighter(player2->fighter, input2);

}