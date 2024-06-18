// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef MONOPOLYCARD_HPP
#define MONOPOLYCARD_HPP

#include <string>
#include "DevelopmentCard.hpp"

class Catan;
class Player;

using namespace std;

class MonopolyCard : public DevelopmentCard {
    
public:
    MonopolyCard(Catan* g);
    bool action(Player* p, string resource);  // Use the card (should be overritten)
    void print_card() override;
};

#endif
