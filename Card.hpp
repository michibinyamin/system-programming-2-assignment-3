// ID - 208768978
// Email - michibinyamin@gmail.com
#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

using namespace std;

class Card {
private:
    string card_type;   // Can be resource or development

public:
    Card(string card_type);
    ~Card();
};

#endif