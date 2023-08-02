#include "food.h"

// rendom
// food->cordinate
std::vector<std::pair<int, int>> nibles;
char food_charater = (char)36;
std::pair<int, int> make_food()
{
    // randemly gentrate {x,y}
    // retrict number between range {rand()%(LINES-2)+1,rand()%(COLS-2)+1}
    return {rand() % (LINES - 2) + 1, rand() % (COLS - 2) + 1};
}
void init_food()
{
    nibles.clear();
    for (int i = 0; i < FOOD_COUNT; i++)
    {
        nibles.push_back(make_food());
    }
}

void paint_food()
{
    for (int i = 0; i < nibles.size(); i++)
    {
        move(nibles[i].first, nibles[i].second);
        addch(food_charater);
    }
}
bool try_eating_food(std::pair<int, int> head)
{
    // first check if head==food
    for (int i = 0; i < nibles.size(); i++)
    {
        if (head.first == nibles[i].first && head.second == nibles[i].second)
        {
            // eat food
            nibles.erase(nibles.begin() + i); //
            nibles.push_back(make_food());
            return true;
        }
    }
    return false;
}