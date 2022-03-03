#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

/**
 * @class Player Keeps track of the player's name and highest score
 */
class Player {
public:
    /**
     * Player constructor
     * @param _name the player's chose username
     */
    Player(const std::string& _name);

    /**
     * Getter for name
     * @returns the player's name
     */
    const std::string& getName() const;

    /**
     * Getter for bestScore
     * @returns the player's best score
     */
    int getMaxScore() const;

    /**
     * Compares new_score to the previous best score, then updates bestScore
     * @param new_score the player's latest score
     * @returns whether that's a new high score
     */
    bool checkRecord(int new_score);

private:
    const std::string name;
    int bestScore;
};

#endif  // _PLAYER_H_
