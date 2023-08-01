#include "game.h"


// int x=10, y=10;
int game_state=BEFORE_START;
int direction;

void start_game(){
    init_snake();
    // init_food();
    direction=UP;
    game_state=STARTED;

}
void game_logic(){
     paint_border();

    int key=getch();
    if(game_state==BEFORE_START){
        move(10,10);
        addstr("        Press space to start");
        if(key==32){
            //start the game
            //init snake
            //direction
            start_game();
        }
    }else{
        //either keepmoving snake 
        //or react to key input
        if(key==UP && direction!=DOWN){
            direction=UP;
        }
        else if(key==DOWN && direction!=UP){
            direction=DOWN;
        }if(key==LEFT&& direction!=RIGHT){
            direction=LEFT;
        }else if(key==RIGHT&& direction!=LEFT){
            direction=RIGHT;
        }
        move_snake(direction);
        paint_snake();

    }

   


}