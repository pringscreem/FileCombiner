#include <iostream>
#include "Game.h"

Game::Game(int min, int max)
	:
    rd(),
    gen(rd()),
    distribution(min, max),
    myMin(min),
    myMax(max)
{
}

void Game::RunGuessingGame()
{
    bool isCorrectGuess = false;
    int guess = 0;

    while(!isCorrectGuess)
    {
        std::cout << "Enter your guess between " << myMin << " and " << myMax << ": ";
        std::cin >> guess;
        if(guess == randomNumber)
        {
            std::cout << "Correct." << std::endl;
            isCorrectGuess = true;
        }
        else
        {
            std::cout << "Guess again." << std::endl;
        }
    }
    std::cout << "End of game." << std::endl;
}