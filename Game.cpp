#include <iostream>
#include "Game.h""

Game::Game()
{
    randomNumber = distribution(gen);
}

Game::RunGuessingGame()
{
    bool isCorrectGuess = false;
    int guess = 0;
    while(!isCorrectGuess)
    {
        std::cout << "Enter your guess between" << min << " and " << max << ": ";
        std::cin >> guess;
    }
}