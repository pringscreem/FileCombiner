#include <iostream>
#include "Game.h"

Game::Game()
{
    randomNumber = distribution(gen);
}

void Game::RunGuessingGame()
{
    bool isCorrectGuess = false;
    int guess = 0;
    while(!isCorrectGuess)
    {
        std::cout << "Enter your guess between" << min << " and " << max << ": ";
        std::cin >> guess;
        if(guess == randomNumber)
        {
            std::cout << "Correct." std::endl;
            isCorrectGuess = true;
        }
        else
        {
            std::cout << "Guess again." << std::endl;
        }
    }
    std::cout << "End of game." << std::endl;
}