#ifndef _LINE_OF_MINES_H_
#define _LINE_OF_MINES_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class LineOfMines {
public:
    LineOfMines(size_t length, size_t mines);
    void display() const;
    void grandReveal();
    bool hasHitMine() const;
    int getScore() const;
    void makeSelection(int position);
private:
    const size_t lineLength;
    const size_t numberOfMines;
    int score;
    std::vector<std::string> locationDisplays;
    std::vector<int> neighbouringMineCounts;
    std::vector<int> mineLocations;
    bool hitMine;
    void placeMines();
    void setCounts();
    bool containsMine(int position) const;
};

#endif  // _LINE_OF_MINES_H_
