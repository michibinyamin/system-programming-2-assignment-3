// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

class Catan;

using namespace std;

class Player {
private:
    string name;
    Catan* game;

public:
    Player(string given_name);
    ~Player();

    void set_game(Catan* p) {
        game = p;
    }
    string getname();
};
#endif  // PLAYER_HPP