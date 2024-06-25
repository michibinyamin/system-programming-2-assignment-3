// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef KNIGHTCARD_HPP
#define KNIGHTCARD_HPP

#include <string>

#include "DevelopmentCard.hpp"

class Catan;
class Player;

using namespace std;

class KnightCard : public DevelopmentCard {
public:
    KnightCard(Catan* g);
    bool action(Player* p);  // Use the card (check if player has 3 of these)
    void print_card() override;
};

#endif
