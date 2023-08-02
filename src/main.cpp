#include <iostream>
#include <curses.h>
#include "ui.h"
#include "game.h"
#include <chrono>
#include "settings_constants.h"

void event_loop()
{
    while (true)
    {
        auto last_time = std::chrono::system_clock::now();
        int dt; // time diffrence
        erase();
        bool game_over;
        game_over = game_logic();
        if (game_over)
        {
            break;
        }
        // getch();
        refresh();
        do // use because for dt inasliztion
        {
            auto current_time = std::chrono::system_clock::now();
            dt = std::chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();

        } while (dt < Time_DELAY_BETWEEN_FRAMS);
    }
}
int main()
{

    int_ui();
    event_loop();
    tear_down_ui();
    std::cout << "THANKS FOR PLAYING GAME \n";

    return 0;
}
