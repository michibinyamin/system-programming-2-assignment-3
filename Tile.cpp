// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Tile.hpp"

Tile::Tile() : land("sea"), number(0) {
}

Tile::Tile(string Land, int Number) : land(Land), number(Number) {
}

Tile::Tile(Tile* tile) : land(tile->land), number(tile->number) {
}

string Tile::get_land() {
    return land;
}

int Tile::get_number() {
    return number;
}

void Tile::notify() {
    // to-do
}

Tile::~Tile() {
}
