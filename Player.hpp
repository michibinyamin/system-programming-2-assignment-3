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

    //DevelopmentCard* Find_in_dec(string card_name);

public:
    Player(string given_name);
    ~Player();

    void set_game(Catan* p) {
        game = p;
    }
    void set_num(int n);  // This will be the players id in the game
    string getname();     // Reterns player name
    void Roll_dice();     // Player rolls dice
    bool Buy_card();      // Player gets a randome card(if he has enogh resources)
    bool Use_card(string card_name);     // Use a card (Victory point)
    bool Use_card(string card_name, string resource1, string resource2);     // Use a card (Year of plenty)
    bool Use_card(string card_name, string resource);     // Use a card (Monopoly)
    bool placeSettelemnt(int position);  // Place a settelment on a position
    bool placeRoad(int road);            // Place a road on a path
    void get_resources(int num);         // Get the resources of the number (from a dice roll)
    int steal_resources(string res);     // For monopoly
    bool achive_resource(string res, int times);    // receive a resource res x times
    void print_resources();              // Print the players resources
    void get_point();       // Receive a point
    void print_points();    // Print the player's points
    void End_turn();        // Player chooses to end hes turn, game waits for next players move
};
#endif  // PLAYER_HPP