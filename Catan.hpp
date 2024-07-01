// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef CATAN_HPP
#define CATAN_HPP

#include <iostream>
#include <vector>

#include "Board.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "DevelopmentCard.hpp"
#include "VictoryPointCard.hpp"
#include "MonopolyCard.hpp"
#include "YearOfPlentyCard.hpp"
#include "RoadBuilderCard.hpp"
#include "KnightCard.hpp"

class Catan {
private:
    Player* player1;
    Player* player2;
    Player* player3;
    Board* board;
    vector<DevelopmentCard*> DevelopmentCards;
    int turn;

    // Check if the game is finished
    bool Player_won();
    // Set the turn to be the next player
    void Next_Turn();

    // A player roled the dice, players get thyre משאבים
    void Dice_roled(int result);

    // Monopoly
    int monopoly(Player* p, string res);

    // Returns a randome cdevelopment card in the deck
    DevelopmentCard* Get_card();

public:
    // Constructor
    Catan(Player* p1, Player* p2, Player* p3, Tile* new_tiles);

    // Constructor
    Catan();

    // Destructor
    ~Catan();

    // Get the board
    Board* Get_Board();

    // Get turn name
    string Get_Turn_name();

    // Get turn number
    int Get_Turn_number();

    // Print winner
    void PrintWinner();

    friend class Player;
    friend class MonopolyCard;
};

#endif  // CATAN_HPP