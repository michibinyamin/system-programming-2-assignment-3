// ID - 208768978
// GMAIL - michibinyamin@gmail.com

#include <sstream>  // Include the <sstream> header for stringstream

#include "Board.hpp"
#include "Catan.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "doctest.h"

using namespace std;

TEST_CASE("Playing game") {
    Player p1("Michi");
    Player p2("Yehuda");
    Player p3("Eliya");

    // Choose the tiles and how to play with them
    Tile tiles[19] = {
        Tile("forest", 5),   Tile("pastures", 10), Tile("pastures", 8),
        Tile("pastures", 2), Tile("fields", 9),    Tile("mountains", 11),
        Tile("forest", 4),   Tile("forest", 6),    Tile("hills", 4),
        Tile("desert", 0),  // No number
        Tile("fields", 3),   Tile("fields", 11),   Tile("hills", 3),
        Tile("pastures", 5), Tile("mountains", 6), Tile("mountains", 12),
        Tile("fields", 8),   Tile("forest", 10),   Tile("hills", 9)};

    Catan* game = new Catan(&p1, &p2, &p3, tiles);
    //game->Get_Board()->print_board();

    // P1 turn :

    // settelments placed out of bounds
    CHECK(p1.placeSettelemnt(95) == false);
    CHECK(p1.placeSettelemnt(-5) == false);

    // Placing a road which is not connected to a settelment
    CHECK(p1.placeSettelemnt(0) == true);        // Place settalment on 0
    CHECK(p1.placeRoad(12) == false);            // Try to place road on 12
    CHECK(p1.placeRoad(0) == true);              // Place road on 

    // P2 turn :
    CHECK(p1.placeSettelemnt(3) == false);  // Not p1's turn
    CHECK(p3.placeSettelemnt(3) == false);  // Not p3's turn

    CHECK(p2.placeSettelemnt(0) == false);  // Try placing on a settalment
    CHECK(p2.placeSettelemnt(1) == false);  // Try placing neighboring a settalment

    CHECK(p2.placeSettelemnt(20) == true);  // place settalment on 20
    CHECK(p2.placeRoad(26) == true);        // place road on 30

    // P3 turn :
    CHECK(p3.placeSettelemnt(30) == true);  // place settalment on 30
    CHECK(p3.placeRoad(41) == true);        // place road on 41

    // P1 trun :
    CHECK(p2.placeSettelemnt(5) == false);  // Not p2's turn
    CHECK(p3.placeSettelemnt(7) == false);  // Not p3's turn
    
    // Finish Initial round
    CHECK(p1.placeSettelemnt(2) == true);  
    CHECK(p1.placeRoad(1) == true);

    CHECK(p2.placeSettelemnt(35) == true);
    CHECK(p2.placeRoad(46) == true);

    CHECK(p3.placeSettelemnt(42) == true);
    CHECK(p3.placeRoad(57) == true);

    // Check that players received the correct resources


    // From now on player ends move only when .endturn() AND he must first roll the dice

    //check(p1.Roll_dice())
    // Make a friend function?



}

TEST_CASE("Test Board") {
}

TEST_CASE("Test Player") {
}
