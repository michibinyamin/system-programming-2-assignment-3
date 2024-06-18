// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef DEVELOPMENT_HPP
#define DEVELOPMENT_HPP

#include <iostream>
#include <string>

class Catan;
class Player;

using namespace std;

class DevelopmentCard {
protected:
    string card_name;    // Which card it is
    Catan* game;

public:
    DevelopmentCard(string name, Catan* g);
    string Get_action();         // Returns the description of what the card can do
    string Get_name();           // Returns the name of the card
    virtual void print_card();           // Prints the type and name of card it is and action it does
};

#endif