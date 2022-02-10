#ifndef _CARD_
#define _CARD_

#include<string>
#include<cstddef>

/**
@class Card represents a card from
a standard deck of 52
*/
class Card{
public:
	/**
	Constructor: takes two inputs to create a Card object. The first input is a string, one of "Clubs", "Diamonds", "Hearts", or "Spades".
	The second input is the face as a string: "A" for Ace, "2", "3", ... "9", "10", "J" for Jack, "Q" for Queen, and "K" for King.

	@param suitType the suit, "Clubs", "Diamonds", "Hearts", or "Spades"
	@param face the face of the card, "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
	*/
	Card(const std::string &suitType, const std::string &face);

	/**
	This function returns the string representation of the card in the format "FACE[SUIT]". For example, "10[Diamonds]"

	@return the string representation of the card in the format described above
	*/
	std::string card_as_string() const;

private:
	std::string suit, face;

};

#endif