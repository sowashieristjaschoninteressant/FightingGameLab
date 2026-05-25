
#include "game.h"

int main(void){
    int width = 750, height = 750;
   Game* game = createGame(width, height);
   runGame(game);

   return 0;
}