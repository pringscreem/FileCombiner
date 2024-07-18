#include <random>

class Game
{
    public:
        Game(int min, int max);
        void RunGuessingGame();
    private:
        int myMin;
        int myMax;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> distribution;
        int randomNumber;
};