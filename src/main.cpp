#include<iostream>
#include<curses.h>
#include "ui.h"
#include "game.h"

void event_loop(){
    while (true){
        erase();
        game_logic();
        getch();
        refresh();
        // sleep(100);//sleep for 100 ms
        

    }
    
}
int main(){

    int_ui();
    event_loop();
    tear_down_ui();
    
    
    
    return 0;
    
}
