// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "DevelopmentCard.hpp"
#include "Position.hpp"
#include "VictoryPointCard.hpp"
#include "MonopolyCard.hpp"
#include "YearOfPlentyCard.hpp"
#include "RoadBuilderCard.hpp"

class Catan;

using namespace std;

class Player {
private:
    string name;     // The players name
    int player_num;  // The players id
    int roads;       // How many roads were built
    int settelment;  // How many settelments were built
    int points;      // The amount of points a player has
    bool rolled;    // Markes if player rolled yet in hes turn or not
    int forest, hills, pastures, mountains, fields;  // The resources
    vector<Position*> positions;                    // the positions which the player holds
    vector<DevelopmentCard*> Development_cards;     // The development cards which the player holds

    Catan* game;    // A instance of the game
    bool My_turn(); // Keeps track of whos turn it is

    int steal_resources(string res);                // steal all of type res ,For monopoly card
    DevelopmentCard* take_development_card(string card);    // For trade
    void get_develpoment_card(DevelopmentCard* card);       // For trade
    //bool steal_resource_k(string res);             // steal one of type res ,For knight card
    void get_resources(int num);                    // Get the resources of the number (from a dice roll)
    bool achive_resource(string res, int times);    // receive a resource res x times
    void get_point();                               // Receive a point
    bool count_knights();
    bool three_knights;
    bool has_development_card(string card);
    bool legal_trade(Player* p, string card, string card2); // Checks if this trade is legal
    bool trade_development_card(string dev);                // steal one development card ,for trade
    void seven_rolled();                                    // if there is more then 7 resources then it will remove half
    bool won_game();

public:
    Player(string given_name);
    ~Player();

    void set_game(Catan* p) {
        game = p;
    }
    void set_num(int n);  // This will be the players id in the game
    string getname();     // Reterns player name
    bool Roll_dice();     // Player rolls dice
    bool Buy_card();      // Player gets a randome card(if he has enogh resources)
    bool Use_card(string card_name);     // Use a card (Victory point and Road builder)
    bool Use_card(string card_name, string resource1, string resource2);     // Use a card (Year of plenty)
    bool Use_card(string card_name, string resource);      // Use a card (Monopoly)
    bool trade(Player* p, string card, string card2);      // Trade cards, card = he's card to exchange, card2 = my card
    bool placeSettelemnt(int position);  // Place a settelment on a position
    bool placeCity(int position);        // Place a city on a position
    bool placeRoad(int road);            // Place a road on a path
    void print_resources();              // Print the players resources
    void print_points();    // Print the player's points
    void End_turn();        // Player chooses to end hes turn, game waits for next players move

    friend class Catan;
    friend class DevelopmentCard;
    friend class MonopolyCard;
    friend class YearOfPlentyCard;
    friend class VictoryPointCard;
    friend class RoadBuilderCard;
    friend class KnightCard;

    friend class Test;    // For testing
};
#endif  // PLAYER_HPP