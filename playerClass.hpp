#pragma once
// NOTE: This player class was designed for "Tic Tac Toe: 3"
// It can be included in "Tic Tac Toe: 4" for "player vs computer"

class Player
{
private:
    unsigned int hierarchy;

public:
    unsigned int score;
    std::string name;
    char character; // Tic Tac Toe use only

    Player(int Hierarchy, std::string Name)
        : hierarchy(Hierarchy), name(Name){};

    Player(int Hierarchy)
        : hierarchy(Hierarchy){};

    void setPlayerName(int iterator = 0)
    {
        std::cout << "Player(" << iterator << "), Enter your name: ";
        std::cin >> Player::name;
    }

    int returnHierachy()
    {
        return hierarchy;
    }
};