#include "LineOfMines.h"

LineOfMines::LineOfMines(size_t length, size_t mines) :
        lineLength(length),
        numberOfMines(mines),
        score(0),
        locationDisplays(std::vector<std::string>(length, "_____")),
        neighbouringMineCounts(std::vector<int>(length, 0)),
        mineLocations(std::vector<int>(mines, 0)),
        hitMine(false) {
    // mineLocations and neighbouringMineCounts should have been constants,
    // but they're slightly harder to calculate, so they had to be set using
    // these functions in the constructor body,
    // instead of in the initializer list, so sadly those variables couldn't
    // be marked const :(
    placeMines();
    setCounts();
}

void LineOfMines::placeMines() {
    size_t mines_placed = 0;
    while (mines_placed < numberOfMines) {
        // Keep trying to place mines until we've placed the desired number
        // As we go, make sure that mineLocations has no duplicates
        const int new_mine_position = std::rand() % lineLength;
        // Check that the new mine added is not a duplicate
        // Sadly, we can't use the containsMine function for this since
        // mineLocations begins full of zeroes, even though there aren't
        // actually any mines at the zero position (yet)
        bool unique_position = true;
        for (size_t i = 0; i < mines_placed; ++i) {
            // Look through the part at the beginning of mineLocations
            // that represent mines that have been placed
            // (The later part of mineLocations is placeholder zeroes)
            if (mineLocations[i] == new_mine_position) {
                // If there is already a mine there, try a different random
                // position in the next iteration of the while loop
                unique_position = false;
            }
        }
        if (unique_position) {
            // If the random position is does not yet have a mine,
            // place a mine there
            mineLocations[mines_placed] = new_mine_position;
            ++mines_placed;
        }
    }
}

void LineOfMines::setCounts() {
    if (containsMine(0)) {
        // If the first position has a mine, make note of that by incrementing
        // the neighboring mine count of the second position
        ++neighbouringMineCounts[1];
    }
    for (size_t i = 1; i < lineLength - 1; ++i) {
        // For each position (other than the endpoints), check whether there's
        // a mine there, and if so, increase the neighbouringMineCounts of
        // both neighbors (endpoints need to be treated differently since
        // there won't be a neighbor on both sides of them)
        if (containsMine(i)) {
            // Increment the neighbouringMineCounts of both neighbors
            ++neighbouringMineCounts[i - 1];
            ++neighbouringMineCounts[i + 1];
        }
    }
    if (containsMine(lineLength - 1)) {
        // If the last position has a mine, make note of that by incrementing
        // the neighboring mine count of the penultimate position
        ++neighbouringMineCounts[lineLength - 2];
    }
}

bool LineOfMines::containsMine(int position) const {
    // The assignment specifically said to use int for positions,
    // even though that's kinda weird (IMO should be size_t)
    for (int i : mineLocations) {
        // Look through all the positions where we know there is a mine
        if (i == position) {
            // If one of those positions ("i") matches the position we're
            // looking at, return true, since there is a mine there
            return true;
        }
    }
    // If a mine has not been found at that position, return false
    return false;
}

bool LineOfMines::hasHitMine() const {
    return hitMine;
}

void LineOfMines::display() const {
    std::cout << std::left;
    // Each position takes 6 chars in width to display:
    // 5 for the underscores, plus spaces to separate them
    const int position_width_in_chars = 6;
    for (size_t i = 1; i < lineLength; ++i) {
        // For each position, first just display the position number
        std::cout << std::setw(position_width_in_chars) << i;
    }
    std::cout << lineLength << '\n';
    for (size_t i = 0; i < lineLength; ++i) {
        // Below the position number, display the relevant info about each
        // position (e.g. "__*__" or "__2__")
        std::cout << locationDisplays[i] << ' ';
    }
    std::cout << '\n';
}

void LineOfMines::grandReveal() {
    for (const int position : mineLocations) {
        // For each position where there is a mine,
        // change the corresponding display for that position to "__*__"
        // to indicate there is a mine there
        locationDisplays[position] = "__*__";
    }
    display();
}

void LineOfMines::makeSelection(int position) {
    if (containsMine(position)) {
        // If there's a mine, fail the game, and change the display to show
        // that there's a mine there
        hitMine = true;
        locationDisplays[position] = "__*__";
        score = 0;
    } else {
        // If there isn't a mine there, change the display to "__0__" or
        // "__1__" or "__2__" to show how many mines are adjacent
        locationDisplays[position] = "__" + std::to_string(neighbouringMineCounts[position]) + "__";
        ++score;
    }
}

int LineOfMines::getScore() const {
    return score;
}
