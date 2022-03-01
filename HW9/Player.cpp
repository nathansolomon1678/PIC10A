#include "Player.h"

Player::Player(const std::string& _name) : name(_name), bestScore(0) {}

const std::string& Player::getName() const { return name; }

int Player::getMaxScore() const { return bestScore; }

bool Player::checkRecord(int new_score) {
    bool improved = new_score > bestScore;
    if (improved) {
        bestScore = new_score;
    }
    return improved;
}
