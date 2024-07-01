// ID - 208768978
// GMAIL - michibinyamin@gmail.com

#include <sstream>  // Include the <sstream> header for stringstream

#define private public
#include "Board.hpp"
#include "Catan.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "doctest.h"
#undef private

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
    CHECK(p2.placeSettelemnt(1) == false);  // Try placing neighboring a settalment!

    CHECK(p2.placeSettelemnt(20) == true);  // place settalment on 20
    CHECK(p2.placeRoad(26) == true);        // place road on 30

    // P3 turn :
    CHECK(p3.placeSettelemnt(30) == true);  // place settalment on 30
    CHECK(p3.placeRoad(41) == true);        // place road on 41

    // P1 trun :
    CHECK(p2.placeSettelemnt(5) == false);  // Not p2's turn
    CHECK(p3.placeSettelemnt(7) == false);  // Not p3's turn
    
    CHECK(p1.placeSettelemnt(2) == true);  
    CHECK(p1.placeRoad(1) == true);

    CHECK(p2.placeSettelemnt(35) == true);
    CHECK(p2.placeRoad(46) == true);

    CHECK(p3.placeSettelemnt(42) == true);
    CHECK(p3.placeRoad(57) == true);

    // Initial round finished
    game->board->print_board();
    p1.print_resources();
    p2.print_resources();
    p3.print_resources();

    // Check that players received the correct resources
    CHECK(p1.forest == 2);
    CHECK(p1.hills == 0);
    CHECK(p1.pastures == 1);
    CHECK(p1.mountains == 0);
    CHECK(p1.fields == 0);

    CHECK(p2.forest == 0);
    CHECK(p2.hills == 1);
    CHECK(p2.pastures == 0);
    CHECK(p2.mountains == 1);
    CHECK(p2.fields == 3);

    CHECK(p3.forest == 1);
    CHECK(p3.hills == 2);
    CHECK(p3.pastures == 2);
    CHECK(p3.mountains == 1);
    CHECK(p3.fields == 0);

    // From now on player ends move only when .endturn() AND he must first roll the dice

    // Usually done like this : p1.Roll_dice();
    game->Dice_roled(5);    // option not available in game, this is a private function, this way i can test a dice roll

    // Check that players received the correct resources AFTER 8 WAS ROLLED
    CHECK(p1.forest == 4);      // Received 2 forest
    CHECK(p1.hills == 0);
    CHECK(p1.pastures == 1);
    CHECK(p1.mountains == 0);
    CHECK(p1.fields == 0);

    CHECK(p2.forest == 0);
    CHECK(p2.hills == 1);
    CHECK(p2.pastures == 0);
    CHECK(p2.mountains == 1);
    CHECK(p2.fields == 3);

    CHECK(p3.forest == 1);
    CHECK(p3.hills == 2);
    CHECK(p3.pastures == 4);    // Received 2 pastures
    CHECK(p3.mountains == 1);
    CHECK(p3.fields == 0);

    game->Dice_roled(7);    // Players with more then 7 will return half

    // Stays the same
    CHECK(p1.forest == 4); 
    CHECK(p1.hills == 0);
    CHECK(p1.pastures == 1);
    CHECK(p1.mountains == 0);
    CHECK(p1.fields == 0);

    // Stays the same
    CHECK(p2.forest == 0);
    CHECK(p2.hills == 1);
    CHECK(p2.pastures == 0);
    CHECK(p2.mountains == 1);
    CHECK(p2.fields == 3);

    // Player 3 losses about half
    CHECK(p3.forest == 1);
    CHECK(p3.hills == 1);
    CHECK(p3.pastures == 2);
    CHECK(p3.mountains == 1);
    CHECK(p3.fields == 0);


    // Placing road
    game->Next_Turn();  
    CHECK(p2.placeRoad(25) == false);   // Must first roll dice
    p2.rolled = true;                   // Set manually
    CHECK(p2.placeRoad(25) == false);   // Do not have enogh resources
    p2.forest++;
    p2.hills++;
    CHECK(p2.placeRoad(25) == true);
    p2.End_turn();

    p3.rolled = true;
    CHECK(p3.Buy_card() == false);  // Not enogh resources
  
    // Now i will manually set each players resources for testing : 
    p1.forest = 8;
    p1.hills = 8;
    p1.pastures = 8;
    p1.mountains = 8;
    p1.fields = 8;

    p2.forest = 8;
    p2.hills = 8;
    p2.pastures = 8;
    p2.mountains = 8;
    p2.fields = 8;

    p3.forest = 8;
    p3.hills = 8;
    p3.pastures = 8;
    p3.mountains = 8;
    p3.fields = 8;

    CHECK(p3.trade(&p2,"forest","hills") == true);  // Legal trade
    // Check if trade succesfully handled
    CHECK(p3.forest == 9);
    CHECK(p3.hills == 7);

    CHECK(p2.forest == 7);
    CHECK(p2.hills == 9);

    // Test the points, there should be 2 from the initial round putting down settalments
    CHECK(p1.points == 2);
    CHECK(p2.points == 2);
    CHECK(p3.points == 2);

    CHECK(p3.placeCity(43) == false);   // no settalment here
    CHECK(p3.placeCity(42) == true);
    CHECK(p3.points == 3);              // points increased by one

    game->Get_Board()->print_board();

    p3.End_turn();

    // Test development cards
    MonopolyCard* m = new MonopolyCard(game);
    VictoryPointCard* v = new VictoryPointCard(game);
    RoadBuilderCard* r = new RoadBuilderCard(game);
    YearOfPlentyCard* y = new YearOfPlentyCard(game);
    KnightCard* k = new KnightCard(game);

    // Monopoly card
    p1.get_develpoment_card(m);
    CHECK(p1.Use_card("Monopoly", "mountains") == true);
    CHECK(p1.mountains == 21);
    CHECK(p3.mountains == 0);
    CHECK(p3.mountains == 0);

    // Victory point
    p2.get_develpoment_card(v);
    CHECK(p2.Use_card("Victory point") == true);
    CHECK(p2.points == 3);
    
    // Road builder
    p3.get_develpoment_card(r);
    CHECK(p3.Use_card("Road builder") == true);
    CHECK(p3.forest == 11);
    CHECK(p3.hills == 9);

    // Year of plenty
    p1.get_develpoment_card(y);
    CHECK(p1.Use_card("Year of plenty", "forest", "mountains") == true);
    CHECK(p1.mountains == 22);
    CHECK(p1.forest == 9);

    // Knight
    KnightCard* k2 = new KnightCard(game);
    KnightCard* k3 = new KnightCard(game);
    p2.get_develpoment_card(k);
    CHECK(p2.points == 3);
    p2.get_develpoment_card(k2);
    p2.get_develpoment_card(k3);
    // Three knights gives the player 2 points
    CHECK(p2.points == 5);

    // Get rid of 
    CHECK(p2.trade(&p1,"forest","Knight") == true);  // Legal trade
    CHECK(p2.points == 3);


    // make player two win
    p2.forest = 15;
    p2.hills = 15;
    p2.pastures = 15;
    p2.mountains = 15;
    p2.fields = 15;

    p2.rolled = true;
    CHECK(p2.placeCity(35) == true);
    CHECK(p2.points == 4);
    CHECK(p2.placeSettelemnt(18) == true);
    CHECK(p2.points == 5);
    CHECK(p2.placeCity(20) == true);
    CHECK(p2.points == 6);
    CHECK(p2.placeCity(18) == true);
    CHECK(p2.points == 7);
    CHECK(p2.trade(&p1,"Knight","forest") == true);  // Legal trade
    CHECK(p2.points == 9);
    CHECK(p2.placeRoad(27) == true);
    CHECK(p2.placeRoad(28) == true);
    CHECK(p2.placeSettelemnt(22) == true);
    CHECK(p2.points == 10);
    CHECK(p2.won_game());
    game->PrintWinner();

}