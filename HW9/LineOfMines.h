#ifndef _LINE_OF_MINES_H_
#define _LINE_OF_MINES_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * @class LineOfMines The minefield used for linesweeper
 * Containts functions to display the current game status,
 * calculate the score, place mines, count mines, etc.
 */
class LineOfMines {
public:
    /**
     * LineOfMines constructor
     * @param length the number of positions in the minefield
     * @param mines the number of mines per game
     */
    LineOfMines(size_t length, size_t mines);

    /**
     * Displays the gameboard with ASCII chars
     */
    void display() const;

    /**
     * Modifies the location display to show where all the mines are,
     * then prints that display
     */
    void grandReveal();

    /**
     * Says whether a mine has been hit
     * @returns whether the player has hit a mine
     */
    bool hasHitMine() const;

    /**
     * Getter for score
     * @returns the player's score
     */
    int getScore() const;

    /**
     * Sees whether there is a mine at the given position,
     * then modifies hitMine and locationDisplays accordingly
     * @param position the location to investigate
     */
    void makeSelection(int position);

private:
    const size_t lineLength;
    const size_t numberOfMines;
    int score;
    std::vector<std::string> locationDisplays;
    std::vector<int> neighbouringMineCounts;
    std::vector<int> mineLocations;
    bool hitMine;

    /**
     * Modifies mineLocations so that there are numberOfMines mines
     * randomly distributed along the line, without multiple mines in the
     * same location
     */
    void placeMines();

    /**
     * Counts how how many mines are adjacent to each location and saves
     * that calculation to neighbouringMineCounts
     */
    void setCounts();

    /**
     * Says whether there is a mine at the given position
     * @param position the location to investigate
     * @returns whether there is a mine there
     */
    bool containsMine(int position) const;
};

#endif  // _LINE_OF_MINES_H_
