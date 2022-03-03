#include <ctime>
#include <iostream>

#include "Player.h"
#include "LineOfMines.h"

int main() {
    std::srand(std::time(nullptr));

    std::cout << 
		"This is a game of Linesweeper: mines are arranged on a line. \n"
		"You select a position to reveal what is there. \n"
		"For every safe location you reveal, you get +1 point. \n"
		"If you reveal a mine, you get a score of 0. \n"
		"A given location may have a mine to either its left, right, both, or neither. \n"
		"The number of neighbouring mines of a revealed location 0/1/2 is displayed. \n"
		"You can continue playing until you either hit a mine or choose not to reveal any more locations.\n"

        "What is your name? ";
    std::string name = "";
    std::getline(std::cin, name);

    Player User(name);

    int length = 0;
    std::cout << "How long do you want the line? ";
    std::cin >> length;

    int num_mines = 0;
    std::cout << "How many mines do you want on the line? ";
    std::cin >> num_mines;
    
    char play_another_round = 'y';
    while (play_another_round == 'y') {
        // Keep starting new games as long as user says 'y' when prompted whether to play another round
        LineOfMines Minefield(length, num_mines);
        while (true) {
            // Keep asking to reveal a position until either the player chooses to stop,
            // or they hit a mine
            // (There are break statements for both of those cases, so this shouldn't be an infinite loop)
            Minefield.display();

            std::cout << "What position would you like to reveal? ";
            int position = 0;
            std::cin >> position;
            --position;  // Player thinks position numbers start at 1, but they actually start at 0
            Minefield.makeSelection(position);
            Minefield.display();

            // If they hit a mine, round is over
            if (Minefield.hasHitMine()) { break; }
            std::cout << "Would you like to reveal another location? [y/n] ";
            char reveal_another_location = ' ';
            std::cin >> reveal_another_location;
            // Round is also over if they say 'n' to that question
            if (reveal_another_location != 'y') { break; }
        }

        std::cout << "The mine positions are now revealed:\n";
        Minefield.grandReveal();
        if (User.checkRecord(Minefield.getScore())) {
            // If their score is a new record, let them know!
            std::cout << "You have a new high score of " << User.getMaxScore() << "!\n";
        } else {
            // Otherwise, display a disappointed message
            std::cout << "You scored " << Minefield.getScore() << " but your best score is still " << User.getMaxScore() << '\n';
        }
        // Ask whether they want to play another game
        // They can play as many games as they want if they just keep saying 'y'
        std::cout << "Would you like to play another game? [y/n] ";
        std::cin >> play_another_round;
    }

    std::cout << '\n' << User.getName() << ", your top score was " << User.getMaxScore() << ".\n";

	return 0;
}
