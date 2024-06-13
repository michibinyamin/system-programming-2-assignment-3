// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Card.hpp"

// Constructor implementation
Card::Card(string card_type) : card_type(card_type) {
}

// Destructor implementation
Card::~Card() {
    cout << "Card of type " << card_type << " destroyed." << endl;
}
