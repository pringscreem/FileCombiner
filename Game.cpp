#include <iostream>
#include "Game.h"

Game::Game(int min, int max)
  : rd(),
    gen(rd()),
    distribution(min, max),
    myMin(min),
    myMax(max),
    randomNumber(distribution(gen)) 
{
    std::cout << min << std::endl;
    std::cout << max << std::endl;
}

void Game::RunGuessingGame()
{
    bool isCorrectGuess = false;
    int guess = 0;
    std::cout << "The random number is " << randomNumber << "\n";
    while(!isCorrectGuess)
    {
        std::cout << "The random number is " << randomNumber << "\n";
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