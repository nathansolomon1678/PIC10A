#ifndef __RANGE__
#define __RANGE__

#include "Card.h"
#include <iostream>
#include <vector>

/**
Calculates the number of points the given card is worth

@param card the card of interest

@return the number of points the card is worth
*/
int cardValue(const Card& card);

/**
Chooses a random card, removes it from the deck, and returns it

@param undealt_cards the standard 52 card deck minus the cards that have already been dealt

@returns a randomly selected card from the deck
*/
Card dealCard(std::vector<Card>& undealt_cards);

/**
Prints the cards in the users hand, one by one, in the required format

@param hand the list of cards to print
*/
void showHand(const std::vector<Card>& hand);

/**
Returns true iff value is below max_value_allowed

@param max_value_allowed the threshold
@param value the value to be compared to the threshold

@returns true if value > max_value_allowed, otherwise false
*/
bool exceeds(const int max_value_allowed, const int value);

/**
Tells whether a given value is between a lower and upper bound, inclusive

@param lower_bound the lower threshold
@param lower_bound the upper threshold
@param value the value to be tested

@returns true if value is between the bounds, otherwise false
*/
bool inRange(const int lower_bound, const int upper_bound, const int value);

/**
Returns a brand new 52-card deck

@returns a brand new 52-card deck
*/
std::vector<Card> new_deck();

/**
Calculates the total value of a list of cards

@param hand the list of cards

@returns the total value of the cards in hand
*/
int hand_value(const std::vector<Card>& hand);

#endif
