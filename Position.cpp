// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Position.hpp"

using namespace std;

Position::Position() {
}
Position::Position(int position_number) {
    position_num = position_number;
    for (int i = 0; i < 3; ++i) {
        tiles[i] = nullptr;  // Initialize neighbors with nullptr
        paths[i] = nullptr;  // Initialize neighbors with nullptr
    }
    owner = 0;
    city = false;
}

void Position::set_number(int position_number) {
    position_num = position_number;
}
void Position::set_tiles(Tile* t) {
    for (int i = 0; i < 3; ++i) {
        if (tiles[i] == nullptr)  // If not initialized
        {
            tiles[i] = t;
            return;
        }
    }
}
void Position::set_path(Path& p) {
    for (int i = 0; i < 3; ++i) {
        if (paths[i] == nullptr)  // If not initialized
        {
            paths[i] = &p;
            return;
        }
    }
}

void Position::set_owner(int player) {
    owner = player;
}
bool Position::set_city(int player){
    if (owner == player)
    {
        city = true;
        return true;
    }
    return false;
}



bool Position::has_path(int p) {
    for (int i = 0; i < 3; i++) {
        if (paths[i] != nullptr) {
            if (paths[i]->get_owner() == p) {
                return true;
            }
        }
    }
    return false;
}
bool Position::no_neighbors() {
    for (int i = 0; i < 3; i++) {
        if (paths[i] != nullptr) {
            if (paths[i]->get_position(0)->get_owner() != 0 ||
                paths[i]->get_position(1)->get_owner() != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Position::is_city(){
    return city;
}

Path* Position::get_path(int p) {
    return paths[p];
}

Tile** Position::get_tiles() {
    return tiles;
}

int Position::get_owner() {
    return owner;
}

int Position::get_number() {
    return position_num;
}

string Position::print_tiles() {
    string s = tiles[0]->get_land() + "," + to_string(tiles[0]->get_number());
    if (tiles[1] != nullptr) {
        s = s + "," + tiles[1]->get_land() + "," +
            to_string(tiles[1]->get_number());
    }
    if (tiles[2] != nullptr) {
        s = s + "," + tiles[2]->get_land() + "," +
            to_string(tiles[2]->get_number());
    }
    s = s + "    ";
    return s;
}

Position::~Position() {
}
