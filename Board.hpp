// ID - 208768978
// Email - michibinyamin@gmail.com
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>

#include "Path.hpp"
#include "Position.hpp"

class Board {
private:
    // Array of positions on the board
    Position positions[54];
    // Array of paths on the board
    Path paths[72];
    // Array of tiles on the board
    Tile tiles[19];
    // initialize the board
    void init_board();

public:
    // Init the board according to the list
    Board(Tile *new_tile);  // Recieves a list of tiles to initialize and create
                            // the board

    void print_board();

    // Relese the board
    ~Board();
};

#endif  // BOARD_HPP