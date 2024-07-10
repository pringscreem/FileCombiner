#include <random>
#include <random>
#include <random>



class Game
class Game
class Game
{
{
{
    public:
    public:
    public:
        Game(int min, int max);
        Game(int min, int max);
        Game(int min, int max);
        void RunGuessingGame();
        void RunGuessingGame();
        void RunGuessingGame();
    private:
    private:
    private:
        int myMin;
        int myMin;
        int myMin;
        int myMax;
        int myMax;
        int myMax;
        int randomNumber = 0;
        int randomNumber = 0;
        int randomNumber = 0;
        std::random_device rd;
        std::random_device rd;
        std::random_device rd;
        std::mt19937 gen;
        std::mt19937 gen;
        std::mt19937 gen;
        std::uniform_int_distribution<> distribution;
        std::uniform_int_distribution<> distribution;
        std::uniform_int_distribution<> distribution;
};
};
};
#include <iostream>
#include <iostream>
#include <iostream>
#include "Game.h"
#include "Game.h"



Game::Game(int min, int max)
Game::Game(int min, int max)
Game::Game(int min, int max)
	:
	:
	:
    rd(),
    rd(),
    rd(),
    gen(rd()),
    gen(rd()),
    gen(rd()),
    distribution(min, max),
    distribution(min, max),
    distribution(min, max),
    myMin(min),
    myMin(min),
    myMin(min),
    myMax(max)
    myMax(max)
    myMax(max)
{
{
{
}
}
}



void Game::RunGuessingGame()
void Game::RunGuessingGame()
void Game::RunGuessingGame()
{
{
{
    bool isCorrectGuess = false;
    bool isCorrectGuess = false;
    bool isCorrectGuess = false;
    int guess = 0;
    int guess = 0;
    int guess = 0;



    while(!isCorrectGuess)
    while(!isCorrectGuess)
    while(!isCorrectGuess)
    {
    {
    {
        std::cout << "Enter your guess between" << myMin << " and " << myMax << ": ";
        std::cout << "Enter your guess between" << myMin << " and " << myMax << ": ";
        std::cout << "Enter your guess between" << myMin << " and " << myMax << ": ";
        std::cin >> guess;
        std::cin >> guess;
        std::cin >> guess;
        if(guess == randomNumber)
        if(guess == randomNumber)
        if(guess == randomNumber)
        {
        {
        {
            std::cout << "Correct." << std::endl;
            std::cout << "Correct." << std::endl;
            std::cout << "Correct." << std::endl;
            isCorrectGuess = true;
            isCorrectGuess = true;
            isCorrectGuess = true;
        }
        }
        }
        else
        else
        else
        {
        {
        {
            std::cout << "Guess again." << std::endl;
            std::cout << "Guess again." << std::endl;
            std::cout << "Guess again." << std::endl;
        }
        }
        }
    }
    }
    }
    std::cout << "End of game." << std::endl;
    std::cout << "End of game." << std::endl;
    std::cout << "End of game." << std::endl;
}
}
}
#include <iostream>
#include <iostream>
#include <iostream>
#include "Game.h"
#include "Game.h"



int main(int argc, char* argv[])
int main(int argc, char* argv[])
int main(int argc, char* argv[])
{
{
{
    Game game(1, 5);
    Game game(1, 5);
    Game game(1, 5);



    game.RunGuessingGame();
    game.RunGuessingGame();
    game.RunGuessingGame();
    return 0;
    return 0;
    return 0;
}
}
}
