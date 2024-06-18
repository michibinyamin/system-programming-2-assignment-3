// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef YEAROFPLENTYCARD_HPP
#define YEAROFPLENTYCARD_HPP

#include <string>

#include "DevelopmentCard.hpp"

class Catan;
class Player;

using namespace std;

class YearOfPlentyCard : public DevelopmentCard {
public:
    YearOfPlentyCard(Catan* g);
    bool action(Player* p, string resource1, string resource2);      
    void print_card() override;  // Overides and prints its details
};

#endif
