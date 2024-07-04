#include <random>

class Game
{
    public:
        Game();
        void RunGuessingGame();
    private:
        int randomNumber = 0;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribution(min, max);
};