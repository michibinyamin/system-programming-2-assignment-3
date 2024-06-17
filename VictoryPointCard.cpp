// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"
#include "Player.hpp"
#include "VictoryPointCard.hpp"

VictoryPointCard::VictoryPointCard(Catan* g) : DevelopmentCard("Victory point", g) {}

void VictoryPointCard::action(Player* p) {
    p->get_point();
}
