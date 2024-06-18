// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"
#include "Player.hpp"
#include "VictoryPointCard.hpp"

VictoryPointCard::VictoryPointCard(Catan* g) : DevelopmentCard("Victory point", g) {}

void VictoryPointCard::action(Player* p) {
    p->get_point();
}
void VictoryPointCard::print_card(){
    cout << "Card name : " << card_name <<"\n";
    cout << "Card action : Reveal this card on your turn if, with it, you "
            "reach the number of points required for victory\n";
}
