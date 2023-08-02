#ifndef DEF_SNAKE

#define DEF_SNAKE
// #include<iostream>
#include <vector>
#include <curses.h>
#include "settings_constants.h"
void init_snake();
void paint_snake();
std::pair<int, int> move_snake(int direction);
void grow_snake();
bool has_collision();

#endif