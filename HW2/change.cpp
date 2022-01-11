#include <iostream>

int main() {
    std::cout << "Enter true cost.\n";
    int dollars = 0;
    int cents   = 0;
    std::cout << "Give the dollars: ";
    std::cin >> dollars;
    std::cout << "Now give the cents: ";
    std::cin >> cents;
    // Round the number of cents to the nearest nickel
    // To do that, add two cents, then divide by 5 and floor, then multiply by 5
    // That's equivalent to adding two cents then truncating any number of cents not divisible by 5
    // You can confirm this rounds down when cents%5<3 and rounds up when cents%5>=3
    cents = (cents + 2) / 5 * 5;
    cents += dollars * 100;

    std::cout << "In cash, the item costs: $" << static_cast<double>(cents) / 100 << ".\n";
    std::cout << "Enter payment details.\n";
    int cents_paid = 0;

    int toonies = 0;
    std::cout << "Number of toonies: ";
    std::cin >> toonies;
    cents_paid += toonies * 200;  // Each toonie is worth 200 cents

    int loonies = 0;
    std::cout << "Number of loonies: ";
    std::cin >> loonies;
    cents_paid += loonies * 100;  // Each loonie is worth 100 cents

    int fifty_cent_pieces = 0;
    std::cout << "Number of fifty cent pieces: ";
    std::cin >> fifty_cent_pieces;
    cents_paid += fifty_cent_pieces * 50;  // Each fifty cent piece is worth 50 cents

    int quarters = 0;
    std::cout << "Number of quarters: ";
    std::cin >> quarters;
    cents_paid += quarters * 25;  // Each quarter is worth 25 cents

    int dimes = 0;
    std::cout << "Number of dimes: ";
    std::cin >> dimes;
    cents_paid += dimes * 10;  // Each dime is worth 10 cents

    int nickels = 0;
    std::cout << "Number of nickels: ";
    std::cin >> nickels;
    cents_paid += nickels * 5;  // Each nickel is worth 5 cents

    std::cout << "You paid "
              << cents_paid / 100 << " dollar(s) and "
              << cents_paid % 100 << " cent(s).\n";
    // Now use the cost minus the amount paid to calculate the change
    cents = cents_paid - cents;
    std::cout << "Your change is: "
              << cents / 100 << " dollar(s) and "
              << cents % 100 << " cent(s). Have a nice day, eh!\n";

    return 0;
}
