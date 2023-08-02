#ifndef DEF_FOOD

#define DEF_FOOD
#include <ncurses.h>
#include <vector>
#include "settings_constants.h"
#include <random>

void init_food();
std::pair<int, int> make_food();
void paint_food();
bool try_eating_food(std::pair<int, int> head);
#endif