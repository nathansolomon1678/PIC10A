#include "LineOfMines.h"

LineOfMines::LineOfMines(size_t length, size_t mines) :
        lineLength(length),
        numberOfMines(mines),
        score(0),
        locationDisplays(std::vector<std::string>(length, "_____")),
        neighbouringMineCounts(std::vector<int>(length, 0)),
        mineLocations(std::vector<int>(mines, 0)),
        hitMine(false) {
    placeMines();
    setCounts();
}

void LineOfMines::placeMines() {
    size_t mines_placed = 0;
    while (mines_placed < numberOfMines) {
        int new_mine_position = std::rand() % lineLength;
        if (!containsMine(new_mine_position)) {
            mineLocations[mines_placed] = new_mine_position;
            ++mines_placed;
        }
    }
}

void LineOfMines::setCounts() {
    if (containsMine(0)) {
        ++neighbouringMineCounts[1];
    }
    for (size_t i = 1; i < lineLength - 1; ++i) {
        if (containsMine(i)) {
            ++neighbouringMineCounts[i - 1];
            ++neighbouringMineCounts[i + 1];
        }
    }
    if (containsMine(lineLength - 1)) {
        ++neighbouringMineCounts[lineLength - 2];
    }
}

bool LineOfMines::containsMine(int position) const {
    for (int i : mineLocations) {
        if (i == position) {
            return true;
        }
    }
    return false;
}

bool LineOfMines::hasHitMine() const {
    return hitMine;
}

void LineOfMines::display() const {
    std::cout << std::left;
    const int position_width_in_chars = 6;
    for (size_t i = 1; i < lineLength; ++i) {
        std::cout << std::setw(position_width_in_chars) << i;
    }
    std::cout << lineLength << '\n';
    for (size_t i = 0; i < lineLength; ++i) {
        std::cout << locationDisplays[i] << ' ';
    }
    std::cout << '\n';
}

void LineOfMines::grandReveal() {
    for (int position : mineLocations) {
        locationDisplays[position] = "__*__";
    }
    display();
}

void LineOfMines::makeSelection(int position) {
    if (containsMine(position)) {
        hitMine = true;
        locationDisplays[position] = "__*__";
    } else {
        locationDisplays[position] = "__" + std::to_string(neighbouringMineCounts[position]) + "__";
    }
}
