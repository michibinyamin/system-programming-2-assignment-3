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
    Player p1("Michi");
    Player p2("Yehuda");
    Player p3("Eliya");

    // Choose the tiles and how to play with them
    Tile tiles[19] = {
        Tile("forest",5),
        Tile("pastures",10),
        Tile("pastures",8),
        Tile("pastures",2),
        Tile("fields",9),
        Tile("mountains",11),
        Tile("forest",4),
        Tile("forest",6),
        Tile("hills",4),
        Tile("desert",0),   // No number
        Tile("fields",3),
        Tile("fields",11),
        Tile("hills",3),
        Tile("pastures",5),
        Tile("mountains",6),
        Tile("mountains",12),
        Tile("fields",8),
        Tile("forest",10),
        Tile("hills",9)
    };
    
    Catan* game = new Catan(&p1,&p2,&p3,tiles);
    game->Get_Board()->print_board();
    
    p1.placeSettelemnt(0); // Counting 3 first moves, must place first a settelment
    p1.placeRoad(6);

    p2.placeSettelemnt(33);   
    p2.placeRoad(45);

    p3.placeSettelemnt(30);
    p3.placeRoad(50);

    // Second round

    p1.placeSettelemnt(39);
    p1.placeRoad(62);

    p2.placeSettelemnt(43);
    p2.placeRoad(64);

    p3.placeSettelemnt(41);
    p3.placeRoad(56);

    p1.print_resources();
    p2.print_resources();
    p3.print_resources();

    // Initial part finished

    p1.Roll_dice();  
    p1.placeSettelemnt(37);
    p1.End_turn();
}