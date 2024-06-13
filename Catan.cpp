// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"

#include <iostream>

#include "Board.hpp"

Catan::Catan(Player* p1, Player* p2, Player* p3, Tile* new_tiles) {
    player1 = p1;
    player1->set_game(this);

    player2 = p2;
    player2->set_game(this);

    player3 = p3;
    player3->set_game(this);

    board = new Board(new_tiles);
}

void Catan::ChooseStartingPlayer() {
    std::cout << player1->getname();
}

Board* Catan::Get_Board() {
    return board;
}

Catan::~Catan() {
}
