#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

class Player {
public:
    Player(const std::string& _name);
    const std::string& getName() const;
    int getMaxScore() const;
    bool checkRecord(int new_score);
private:
    const std::string name;
    int bestScore;
};

#endif  // _PLAYER_H_
