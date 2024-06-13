// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Player.hpp"

#include <iostream>
#include <string>

#include "Catan.hpp"

Player::Player(string given_name) : name(given_name) {
    roads = 0;
    settelment = 0;
}

Player::~Player() {
}

void Player::set_num(int n) {
    player_num = n;
}

string Player::getname() {
    return name;
}

bool Player::placeSettelemnt(int p) {
    if (settelment < 2) {
        if (game->Get_Board()->set_position_initial(p,player_num)) 
        {
            // Todo - receive here cards - position* p = p.get_tiles(0).land...
            cout << "settalment placed succesfully\n";
            settelment++;
            return true;
        }
        else
        {
            cout << "cannot place there a settelment\n";
            return false;
        }
    } else {
        if (game->Get_Board()->set_position(p, player_num)) {  // Todo - add here to check if i have enogh cards to build a sttelment
            cout << "settalment placed succesfully\n";
            settelment++;
            return true;
        }
        cout << "cannot place there a settelment\n";
        return false;
    }
    
}


bool Player::placeRoad(int p) {
    if (roads > 1) {
        // TOdo - Check if you have the cards for that
    }
    if (game->Get_Board()->set_path(p, player_num)) {
        cout << "road placed succesfully\n";
        roads++;
        return true;
    }
    cout << "cannot place there a road\n";
    return false;
}