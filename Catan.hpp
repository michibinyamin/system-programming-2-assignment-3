// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef CATAN_HPP
#define CATAN_HPP

#include <iostream>

#include "Board.hpp"
#include "Player.hpp"
#include "Tile.hpp"
class Catan {
private:
    Player* player1;
    Player* player2;
    Player* player3;
    Board* board;

public:
    // Constructor
    Catan(Player* p1, Player* p2, Player* p3, Tile* new_tiles);

    // Constructor
    Catan();

    // Print starting player's name
    void ChooseStartingPlayer();

    // Get the board
    Board* Get_Board();

    // Get turn
    string Turn();

    // Roll the dice
    int RollDice();

    // Print winner
    void PrintWinner();

    // Catan(Player p1, Player p2, Player p3);
    ~Catan();
};

#endif  // CATAN_HPP