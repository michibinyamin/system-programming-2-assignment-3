// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef VICTORYPOINT_HPP
#define VICTORYPOINT_HPP

#include <string>
#include "DevelopmentCard.hpp"

class Catan;
class Player;

using namespace std;

class VictoryPointCard : public DevelopmentCard{

public:
    VictoryPointCard(Catan* g);
    void action(Player* p);         // Use the card (should be overritten)
    void print_card() override;     // Overides and prints its details
};

#endif
