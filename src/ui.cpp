#include "ui.h"

char border_charcter=219;
void int_ui(){
 initscr();
}
void tear_down_ui(){
    endwin();
}
void paint_border(){
    //cols , lines
    for (int i = 0; i < COLS; i++)
    {
        move(0,i);
        addch(border_charcter);
        move(LINES-1,i);
        addch(border_charcter);
    }
    for (int i = 1; i < LINES; i++)
    {
        move(i,0);
        addch(border_charcter);
        move(i,COLS-1);
        addch(border_charcter);
    }
    
    
    // getch();
}