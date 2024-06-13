// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Path.hpp"
#include "Tile.hpp"

using namespace std;

class Position {
private:
    int position_num;  // The number of the vertex on the board
    int owner;  // Indicates who built a settelment on this vertex, 0 - no one
    Path* paths[3];  // Indicates who has a road on a given path, 0 - no one
    Tile* tiles[3];  // The Tiles sarounding the vertex

public:
    Position();
    Position(int position_number);
    ~Position();  //  todo - delete position and tiles

    void set_number(int position_number);
    void set_owner(int player);
    void set_tiles(Tile* t);  // Set a tile
    void set_path(Path& p);   // Set a num
    int get_owner();
    int get_number();
    string get_tiles();
};

#endif  // Position_HPP