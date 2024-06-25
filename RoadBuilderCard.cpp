// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"
#include "Player.hpp"
#include "RoadBuilderCard.hpp"

RoadBuilderCard::RoadBuilderCard(Catan* g) : DevelopmentCard("Road Builder", g) {
}

void RoadBuilderCard::action(Player* p) {
    p->achive_resource("forest",2);
    p->achive_resource("hills",2);
    
}
void RoadBuilderCard::print_card() {
    cout << "Card name : " << card_name << "\n";
    cout << "Card action : Build Two roads\n";
}
