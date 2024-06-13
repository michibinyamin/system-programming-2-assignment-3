// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Player.hpp"

#include <iostream>
#include <string>

#include "Catan.hpp"

Player::Player(string given_name) : name(given_name) {
    // game = Catan::getInstance();
}

Player::~Player() {
}

string Player::getname() {
    return name;
}