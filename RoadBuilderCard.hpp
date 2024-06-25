// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef ROADBUILDER_HPP
#define ROADBUILDER_HPP

#include <string>

#include "DevelopmentCard.hpp"

class Catan;
class Player;

using namespace std;

class RoadBuilderCard : public DevelopmentCard {
public:
    RoadBuilderCard(Catan* g);
    void action(Player* p);      // Use the card
    void print_card() override;  // Overides and prints its details
};

#endif
