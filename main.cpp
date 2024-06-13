// ID - 208768978
// Email - michibinyamin@gmail.com

#include <iostream>
#include <stdexcept>
#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Tile.hpp"

using namespace std;

int main()
{
    Player p1("michi");
    Player p2("yehuda");
    Player p3("eliya");

    // Choose the tiles and how to play with them
    Tile tiles[19] = {
        Tile("forest",5),
        Tile("pasture",10),
        Tile("pasture",8),
        Tile("pasture",2),
        Tile("fields",9),
        Tile("mountains",11),
        Tile("forest",4),
        Tile("forest",6),
        Tile("hills",4),
        Tile("desert",0),   // No number
        Tile("fields",3),
        Tile("fields",11),
        Tile("hills",3),
        Tile("pasture",5),
        Tile("mountains",6),
        Tile("mountains",12),
        Tile("fields",8),
        Tile("forest",10),
        Tile("hills",9)
    };

    Catan* game = new Catan(&p1,&p2,&p3,tiles);
    game->Get_Board()->print_board();
    
    
}