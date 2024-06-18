// ID - 208768978
// Email - michibinyamin@gmail.com

#include "DevelopmentCard.hpp"
#include "Catan.hpp"
#include "Player.hpp"

using namespace std;

DevelopmentCard::DevelopmentCard(string name, Catan* g) : card_name(name), game(g){
    // if (name == "Victory point")
    // {
    //     card_action = "Reveal this card on your turn if, with it, you reach the number of points required for victory.\n";
    // }
    // else if (name == "Monopoly")
    // {
    //     card_action =
    //         "When you play this card, announce 1 type of resource. all other "
    //         "players must give you all of their resources of that type\n";
    // }
    // else{
    //     throw runtime_error("There is no such card in the game!\n");
    // }
    // Add one more card !
    
}

string DevelopmentCard::Get_name(){
    return card_name;
}

void DevelopmentCard::print_card() {
    cout << "This is a generic card\n";
}


