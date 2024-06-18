// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"
#include "Player.hpp"
#include "MonopolyCard.hpp"

MonopolyCard::MonopolyCard(Catan* g) : DevelopmentCard("Monopoly", g) {}

bool MonopolyCard::action(Player* p, string resource) 
{
    if (p->achive_resource(resource, game->monopoly(p, resource)))
    {
        return true;
    }
    return false;
}
void MonopolyCard::print_card() {
    cout << "Card name : " << card_name << "\n";
    cout << "When you play this card, announce 1 type of resource.all other "
            "players must give you all of their resources of that type\n";
}