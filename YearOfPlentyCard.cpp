// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"
#include "Player.hpp"
#include "YearOfPlentyCard.hpp"

YearOfPlentyCard::YearOfPlentyCard(Catan* g): DevelopmentCard("Year of plenty", g) {
}

bool YearOfPlentyCard::action(Player* p, string resource1, string resource2) {
    if (resource1 != "forest" || resource1 != "mountains" ||
        resource1 != "hills" || resource1 != "fields" ||
        resource1 != "pasture") {
        return false;
    }
    if (resource2 != "forest" || resource2 != "mountains" ||
        resource2 != "hills" || resource2 != "fields" ||
        resource2 != "pasture") {
        return false;
    }

    p->achive_resource(resource1,1);
    p->achive_resource(resource2,1);

    return true;
}
void YearOfPlentyCard::print_card() {
    cout << "Card name : " << card_name << "\n";
    cout << "Take any 2 resources from the bank. add them to your hand." 
    "They can be 2 of the same resource or 2 diffarent resources\n";
}
