#include <iostream>
#include <string>
#include "playerClass.hpp"
#include "_ttt3.hpp"

int main()
{
    std::string position = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, choice;

    introduction();
    Player player1(1);
    Player player2(2);

    // Enter name
    player1.setPlayerName(player1.getPriority());
    player2.setPlayerName(player2.getPriority());

    do
    {
        chooseCustomCharacter(player1);
        chooseCustomCharacter(player2);
        system("cls");

        // Draw
        // draw(position);

        // Begin match
        for (int turn = 1; turn <= 9; turn++)
        {
            // Change player
            if (turn % 2 == 1)
            {
                // Choose a slot
                position = set_position(position, player1);
            }
            else if (turn % 2 == 0)
            {
                position = set_position(position, player2);
            }
            system("cls");
        }
        // Draw
        draw(position);

        // Select winner

        // Reset board
        position = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

        // Display scores

        // running = end_game();
    } while (end_game());

    return 0;
}