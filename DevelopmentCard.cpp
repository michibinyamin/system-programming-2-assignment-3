// ID - 208768978
// Email - michibinyamin@gmail.com

#include "DevelopmentCard.hpp"
#include "Catan.hpp"
#include "Player.hpp"

using namespace std;

DevelopmentCard::DevelopmentCard(string name, Catan* g) : card_name(name), game(g){
    
}

string DevelopmentCard::Get_name(){
    return card_name;
}

void DevelopmentCard::print_card() {
    cout << "This is a generic card\n";
}


