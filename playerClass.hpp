#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP
#endif
// NOTE: This player class was designed for "Tic Tac Toe: 3"
// It can be included in "Tic Tac Toe: 4" for "player vs computer"

class Player
{
private:
    unsigned int priority;

public:
    unsigned int score;
    std::string name;
    char character; // Tic Tac Toe use only

    Player(int Priority, std::string Name)
        : priority(Priority), name(Name){};

    Player(int Priority)
        : priority(Priority){};

    void setPlayerName(int iterator = 0)
    {
        std::cout << "Player(" << iterator << "), Enter your name: ";
        std::cin >> Player::name;
    }

    int getPriority()
    {
        return priority;
    }
};