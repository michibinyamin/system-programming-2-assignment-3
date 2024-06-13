// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "Position.hpp"

class Catan;

using namespace std;

class Player {
private:
    string name;
    int player_num;
    int roads;       // how many roads were built
    int settelment;  // how many settelments were built
    Catan* game;

public:
    Player(string given_name);
    ~Player();

    void set_game(Catan* p) {
        game = p;
    }
    void set_num(int n);    // This will be the players id in the game
    string getname();   // Reterns player name
    bool placeSettelemnt(int position); // Place a settelment on a position
    bool placeRoad(int road);       // Place a road on a path
};
#endif  // PLAYER_HPP