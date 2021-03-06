#include "Range.h"

int cardValue(const Card& card) {
    const char face = card.card_as_string()[0];
    if (card.card_as_string() == "A[Spades]") {
        // Ace of spades is worth 12 points
        return 12;
    } else if (face == 'J' or face == 'Q' or face =='K') {
        // All face cards are worth 11 points
        return 11;
    } else if (face == 'A') {
        // All aces other than the ace of spades are worth 1 point
        return 1;
    } else {
        // Cards with numbers instead of letters have value equal to their number
        // e.g. the 5 of clubs is worth 5 points
        return std::stoi(card.card_as_string());
    }
}

Card dealCard(std::vector<Card>& undealt_cards) {
    // The main function in Game.cpp should seed the random number generator
    // before calling any functions that require random numbers
    const size_t random_index = std::rand() % undealt_cards.size();
    // That chooses an index using a random uniform distribution ranging from 0 to
    // undealt_cards.size()-1, so every card has the same chance of being picked
    const Card card_dealt = undealt_cards[random_index];
    // Before returning that card, remove it from the vector of undealt cards
    // That's why the argument has to be a reference -- so we can change the input
    // These next two lines effectively remove the selected element without preserving order
    undealt_cards[random_index] = undealt_cards[undealt_cards.size() - 1];
    undealt_cards.pop_back();
    return card_dealt;
}

void showHand(const std::vector<Card>& hand) {
    std::cout << "Hand is:";
    for (const Card& card : hand) {
        std::cout << ' ' << card.card_as_string();
    }
    std::cout << '\n';
}

bool exceeds(const int max_value_allowed, const int value) {
    return value > max_value_allowed;
}

bool inRange(const int lower_bound, const int upper_bound, const int value) {
    return lower_bound <= value and value <= upper_bound;
}

std::vector<Card> new_deck() {
    // Generates and returns a complete deck
    std::vector<Card> deck = {};
    // Iterate through all 52 possible cards and add them each to the deck
    for (const std::string& face : {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"}) {
        for (const std::string& suit : {"Clubs", "Diamonds", "Hearts", "Spades"}) {
            deck.push_back(Card(suit, face));
        }
    }
    return deck;
}

int hand_value(const std::vector<Card>& hand) {
    int sum = 0;
    // Iterate through cards and add their values to sum to calculate total value
    for (Card card : hand) {
        sum += cardValue(card);
    }
    return sum;
}
