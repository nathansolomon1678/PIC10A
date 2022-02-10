#include<string>
#include<stdexcept>
#include<sstream>
#include "Card.h"

/* Definitions of Card constructor and member function */

// Card constructor: sets the suit and face based on the inputs
Card::Card(const std::string &suitType, const std::string &face) : suit(suitType), face(face) {}

// Concatenates the face with the suit in square brackets, returning the result
std::string Card::card_as_string() const { return face + "[" + suit + "]"; }