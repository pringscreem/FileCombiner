#include <random>

class Game
{
    public:
        Game(int min, int max);
        void RunGuessingGame();
    private:
        int myMin;
        int myMax;
        int randomNumber = 0;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> distribution;
};
#include <iostream>

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
        std::cout << "Enter your guess between" << myMin << " and " << myMax << ": ";
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
#include <iostream>

int main(int argc, char* argv[])
{
    Game game(1, 5);

    game.RunGuessingGame();
    return 0;
}
