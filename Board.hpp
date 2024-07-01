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

    // Sets a new owner in position p (if owners road connects)
    bool set_position(int p, int owner);         

    // Sets a new owner in position p (no need for road connecting)
    bool set_position_initial(int p,int owner);  

    // Sets a new owner on path p (if legal)
    bool set_path(int p, int owner);    

    // Get position on p
    Position* get_position(int p);  

    // Get path on p
    Path* get_path(int p);  


public:
    // Init the board according to the list
    Board(Tile *new_tile);  // Recieves a list of tiles to initialize and create
    // Relese the board
    ~Board();
    // Print the board
    void print_board();

    friend class Player;
    friend class Catan;
};

#endif  // BOARD_HPP