# Snake Game

This is a simple Snake game implemented in C++ using the `ncurses` library for terminal-based user interface. The game allows you to control a snake to eat food and grow longer while avoiding collisions with the borders and its own tail.

## How to Play

1.  Use the  UP = 'w',
          DOWN = 's',
          LEFT = 'a',
          RIGHT = 'd'; to control the snake's direction. OR you can change the keys in `settings_constants.h`
2. The objective is to eat as much food as possible without running into the borders or colliding with the snake's tail.
3. Eating food will make the snake grow longer and increase the score.

## Requirements

To run this game, you need to have `g++` and the `ncurses` library installed on your system.

## Compilation and Execution

To compile and run the game, you can use the provided `makefile` or use the following command in your terminal:

```bash
g++ main.cpp ui.cpp game.cpp snake.cpp food.cpp -lncurses -o logic && ./logic
```

## Code Files

- `main.cpp`: Contains the main function that initiates the game and the event loop.
- `ui.cpp`: Implements the terminal UI and utility functions for the game interface.
- `game.cpp`: Implements the game logic, including starting and ending the game, handling collisions, and updating the game state.
- `snake.cpp`: Implements the snake-related logic, such as moving the snake, growing it, and checking for collisions.
- `food.cpp`: Implements the food-related logic, including generating random food positions and handling food eating.
- `settings_constants.h`: Contains various constants used in the game, such as time delay between frames, arrow keys' representations, and game states.

## Controls

- Use the  UP = 'w',
          DOWN = 's',
          LEFT = 'a',
          RIGHT = 'd'; to control the snake's direction.OR you can change the keys in `settings_constants.h`
- Press the 'q' key to quit the game.OR you can change the keys in `settings_constants.h`
- Press the 'space' key to start the game when prompted.OR you can change the keys in `settings_constants.h`

## Acknowledgements

This game is created as a simple project for learning C++ and the `ncurses` library. It's inspired by the classic Snake game.

Feel free to modify and improve the game according to your needs and creativity. Happy coding!