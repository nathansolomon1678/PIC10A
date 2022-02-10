#ifndef __RANGE__
#define __RANGE__

#include "Card.h"
#include <iostream>
#include <vector>

int cardValue(Card card);

Card dealCard(std::vector<Card>& undealt_cards);

void showHand(std::vector<Card> hand);

bool exceeds(int max_value_allowed, int value);

bool inRange(int lower_bound, int upper_bound, int value);

std::vector<Card> new_deck();

int hand_value(std::vector<Card> hand);

#endif
