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

    int length = 0;
    std::cout << "How long do you want the line? ";
    std::cin >> length;

    int num_mines = 0;
    std::cout << "How many mines do you want on the line? ";
    std::cin >> num_mines;

    Player User(name);
    LineOfMines Minefield(length, num_mines);
    
    while (true) {
        Minefield.display();
        std::cout << "What position would you like to reveal? ";
        int position = 0;
        std::cin >> position;
        --position;  // Player thinks it starts counting at 1, but it actually starts at 0
        Minefield.makeSelection(position);
        Minefield.display();
        if (Minefield.hasHitMine()) { break; }
        std::cout << "Would you like to reveal another location? [y/n] ";
        char continue_playing = ' ';
        std::cin >> continue_playing;
        if (continue_playing != 'y') { break; }
    }
    std::cout << "The mine positions are now revealed:\n";
    Minefield.grandReveal();

	return 0;
}