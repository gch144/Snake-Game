#include "game.h"

// int x=10, y=10;
int game_state = BEFORE_START;
int direction;
int score;

void start_game()
{
    init_snake();
    init_food();
    direction = UP;
    game_state = STARTED;
    score = 0;
}
void end_game()
{
    game_state = ENDED;
}
void paint_status()
{
    move(0, 5);
    printw("Score %d", score);
}
bool game_logic()
{
    paint_border();
    paint_status();

    int key = getch();
    if (game_state == BEFORE_START)
    {
        move(LINES / 2, COLS / 2);
        addstr("Press space to start");
        if (key == 32)
        {
            // start the game
            // init snake
            // direction
            start_game();
        }
    }
    else if (game_state == STARTED)
    {
        // either keepmoving snake
        // or react to key input
        if (key == UP && direction != DOWN)
        {
            direction = UP;
        }
        else if (key == DOWN && direction != UP)
        {
            direction = DOWN;
        }
        if (key == LEFT && direction != RIGHT)
        {
            direction = LEFT;
        }
        else if (key == RIGHT && direction != LEFT)
        {
            direction = RIGHT;
        }
        std::pair<int, int> head = move_snake(direction);
        // food postion == head of snake
        // if it True eat the food and grow snake
        if (try_eating_food(head))
        {
            score++;
            grow_snake();
        }
        if (has_collision())
        {
            end_game();
        }
        // else{ start_game();}
        paint_snake();
        paint_food();
    }
    else
    {
        move(LINES / 2, COLS / 2);
        addstr("Gave OVER:Press space to restart ,q to quit");
        if (key == 32)
        {
            start_game();
        }
        else if (key == 'q')
        {
            return true; // game over
        }
    }

    return false; // restart game
}