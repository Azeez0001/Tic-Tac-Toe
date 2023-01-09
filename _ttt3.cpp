#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "playerClass.hpp"
#include "_ttt3.hpp"
// #include "log.hpp"

void introduction()
{
    std::chrono::seconds sec(1);

    std::cout << "Tic-Tac-Toe: ";
    std::this_thread::sleep_for(sec);

    std::cout << "The Game";
    std::this_thread::sleep_for(sec);
    system("cls");
    // std::this_thread::sleep_for(sec);

    std::cout << "=====================\n";

    std::cout << "========START========\n";

    std::cout << "=====================\n\n";
    std::this_thread::sleep_for(sec);
}

void take_turn(int turn, std::string pos, Player player)
{
    if (turn % 2 == 1)
    {
        pos = set_position(pos, player);
    }
}

std::string set_position(std::string pos, Player player)
{
    int ind;

    while (true)
    {
        draw(pos);

        std::cout << player.name << ", Choose a slot: ";
        std::cin >> ind;
        if (ind >> 0 && ind << 10)
        {
            if (pos[ind - 1] == ' ')
            {
                pos[ind - 1] = player.character;
                std::cout << "Position Set" << std::endl;
                system("cls");
                break;
            }
            else
            {
                std::cout << "Nice try ('_'), no cheating" << std::endl;
            }
        }
        else
        {
            system("cls");
            std::cout << "Enter a number from 1 to 9" << std::endl;
        }
    }

    return pos;
}

// void update_board(int x_score, int o_score, std::string player_x, std::string player_o) {}

// std::string change_player(int i) {}

void draw(const std::string &position)
{
    std::cout << "      |       |\n  "
              << position[0] << "   |   "
              << position[1] << "   |   "
              << position[2] << "\n______|_______|_______\n      |       |\n  "
              << position[3] << "   |   "
              << position[4] << "   |   "
              << position[5] << "\n______|_______|_______\n      |       |\n  "
              << position[6] << "   |   "
              << position[7] << "   |   "
              << position[8] << "\n      |       |"
              << std::endl;
    std::cout << std::endl;
}

bool end_game()
{
    return ask("Would you like to continue?");
}

bool ask(const char *question)
{
    char response;

    while (true)
    {
        std::cout << question << std::endl;
        std::cout << "Press Y: Yes, Press N: No" << std::endl;
        std::cin >> response;
        if (response == 'y' || response == 'Y')
            return true;
        else if (response == 'n' || response == 'N')
            return false;
        else
        {
            system("cls");
            std::cout << "Invalid response!" << std::endl;
            std::chrono::seconds sec(1);
            std::this_thread::sleep_for(sec);
            system("cls");
        }
    }
}

void chooseCustomCharacter(Player &player)
{
    // char playerChoice;

    // Choose character
    std::cout << "Hi " << player.name << ", Would you like to set a custom character?" << std::endl;
    std::cout << "Press Y: Yeah, Press N: Nope: " << std::endl;
    std::cin >> player.character;

    // If player chooses to change game character
    if (player.character == 'y' || player.character == 'Y')
    {
        std::cout << "Enter a prefered character/letter: ";
        std::cin >> player.character;
    }
    // If not, use default game character
    else
    {
        if (player.returnHierachy() - 1)
            // Player 2
            player.character = 'O';
        else
            // Player 1
            player.character = 'X';
    }

    // return playerChoice;
}

bool playerWins(const std::string &position, Player player)
{
    if (position[0] == player.character && position[1] == player.character && position[2] == player.character)
    { // 1 //
        return true;
    }
    else if (position[3] == player.character && position[4] == player.character && position[5] == player.character)
    { // 2 //
        return true;
    }
    else if (position[6] == player.character && position[7] == player.character && position[8] == player.character)
    { // 3 //
        return true;
    }
    else if (position[0] == player.character && position[3] == player.character && position[6] == player.character)
    { // 4 //
        return true;
    }
    else if (position[1] == player.character && position[4] == player.character && position[7] == player.character)
    { // 5 //
        return true;
    }
    else if (position[2] == player.character && position[5] == player.character && position[8] == player.character)
    { // 6 //
        return true;
    }
    else if (position[0] == player.character && position[4] == player.character && position[8] == player.character)
    { // 7 //
        return true;
    }
    else if (position[6] == player.character && position[4] == player.character && position[2] == player.character)
    { // 8 //
        return true;
    }
    else
    {
        return false;
    }
}