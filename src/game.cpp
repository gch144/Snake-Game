#include "game.h"

int i=10;
void game_logic(){
    paint_border();
    move(10,i);
    addch('#');
    i++;
    if(i>20) i=0;


}