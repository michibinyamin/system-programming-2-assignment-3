// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"
#include "Player.hpp"
#include "KnightCard.hpp"

KnightCard::KnightCard(Catan* g) : DevelopmentCard("Knight", g) {
}

bool KnightCard::action(Player* p) {
    p->count_knights(); 
    return false;
}
void KnightCard::print_card() {
    cout << "Card name : " << card_name << "\n";
    cout << "Card action : \n";
}
