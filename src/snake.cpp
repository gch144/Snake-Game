#include "snake.h"

int x, y;
// snake-dynimic_array of coordinate
// will array fine  here
std::vector<std::pair<int, int>> body;
/*
{10,10}->body[0]
{10,11}->body[1]
......and so on
*/
void init_snake()
{
    body.clear();
    body.push_back({10, 10});
    body.push_back({10, 11});
    body.push_back({10, 12});
}
void paint_snake()
{
    for (int i = 0; i < body.size(); i++)
    {
        std::pair<int, int> location = body[i];
        move(location.first, location.second);
        //    move(body[i].first,body[i].second)
        addch('#');
    }

    // move(x,y);
    addch('#');
}
std::pair<int, int> SNAKE_TAIL;
std::pair<int, int> move_snake(int direction)
{
    // to move add head remove tail
    // remove end corrdinate from the end
    SNAKE_TAIL = body[body.size() - 1];
    body.pop_back();
    std::pair<int, int> old_head = body[0];
    std::pair<int, int> new_head = old_head;
    if (direction == UP)
    {
        new_head.first--;
    }
    else if (direction == DOWN)
    {
        new_head.first++;
    }
    if (direction == LEFT)
    {
        new_head.second--;
    }
    else if (direction == RIGHT)
    {
        new_head.second++;
    }
    body.insert(body.begin(), new_head);
    return new_head;
}
void grow_snake()
{
    // add the end of tail || not remove
    body.push_back(SNAKE_TAIL);
}
bool has_collision()
{
    // collision with border-> 4 border for 4 loop
    // what is top boder -> x cordinate=0;
    // what is bottom boder -> x cordinate=Lines-1;;
    // what is left boder -> y cordinate=0;
    // what is right boder -> y cordinate=cols-1;
    std::pair<int, int> head = body[0];
    int x = head.first;
    int y = head.second;
    if (x == 0 || x == LINES - 1 || y == 0 || y == COLS - 1)
    {
        return true;
    }
    // colsion with tail;
    for (int i = 1; i < body.size(); i++)
    {
        if (head == body[i])
        {
            return true;
        }
    }

    return false;
}