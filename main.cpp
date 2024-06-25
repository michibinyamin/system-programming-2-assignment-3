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
    
    p1.placeSettelemnt(23); // Counting 3 first moves, must place first a settelment
    p1.placeRoad(29);

    p2.placeSettelemnt(33);   
    p2.placeRoad(45);

    p3.placeSettelemnt(0);
    p3.placeRoad(0);

    // Second round

    p1.placeSettelemnt(19);
    p1.placeRoad(25);

    p2.placeSettelemnt(43);
    p2.placeRoad(64);

    p3.placeSettelemnt(41);
    p3.placeRoad(56);

    p1.print_resources();
    p2.print_resources();
    p3.print_resources();

    // Initial part finished

    p1.Roll_dice();  
    p1.End_turn();

    p2.Roll_dice();
    p2.End_turn();

    p3.Roll_dice();
    p3.End_turn();

    p1.Roll_dice();
    p1.End_turn();

    p2.Roll_dice();
    p2.End_turn();

    p3.Roll_dice();
    p3.End_turn();

    p1.Roll_dice();
    p1.End_turn();

    p2.Roll_dice();
    p2.End_turn();

    p3.Roll_dice();
    p3.End_turn();

    p1.Roll_dice();
    p1.End_turn();

    p2.Roll_dice();
    p2.End_turn();

    p3.Roll_dice();
    p3.End_turn();


    p1.print_resources();
    p2.print_resources();
    p3.print_resources();

    p1.Roll_dice();
    p1.placeSettelemnt(50);
    p1.placeRoad(51);
    p1.End_turn();

    p2.Roll_dice();
    p2.placeSettelemnt(39);
    p2.placeRoad(41);
    p2.End_turn();

    p3.Roll_dice();
    p3.placeSettelemnt(41);
    p3.placeRoad(56);
    p3.End_turn();

    p1.Roll_dice();
    p1.print_points();
    p1.Buy_card();

    p1.print_resources();
    p2.print_resources();
    p3.print_resources();
    p1.Use_card("Road Builder");
    // p1.print_resources();
    // p2.print_resources();
    // p3.print_resources();

    p1.End_turn();



    // bool switch_turn = true;

    // while (true)
    // {
    //     Player* p;
    //     int turn = game->Get_Turn_number();
    //     if (turn == 1)
    //     {
    //         p = &p1;
    //     }
    //     else if(turn == 2)
    //     {
    //         p = &p2;
    //     }
    //     else
    //     {
    //         p = &p3;
    //     }

    //     if (switch_turn)
    //     {
    //         cout << game->Get_Turn_name() << "'s turn\n";
    //         switch_turn = false;
    //     }
        
    //     cout << "\nOptions : \n"
    //             "Place a settelment - 1\n"
    //             "Place a road - 2\n"
    //             "Roll dice - 3\n"
    //             "Buy card - 4\n"
    //             "Use card - 5\n"
    //             "Print resources - 6\n"
    //             "Print points - 7\n"
    //             "Print board - 8\n"
    //             "End turn - 9\n";
    //     int choice;
    //     cin >> choice;
    //     int x;
    //     string y;
    //     switch (choice)
    //     {
    //     case 1:
    //         cout << "Where do you want to place a settelment? \n";
    //         cin >> x;
    //         p->placeSettelemnt(x);
    //         break;

    //     case 2:
    //         cout << "Where do you want to place a road? \n";
    //         cin >> x;
    //         p->placeRoad(x);
    //         break;

    //     case 3:
    //         p->Roll_dice();
    //         break;

    //     case 4:
    //         p->Buy_card();
    //         break;

    //     case 5:
    //         cout << "Which card do you want to use? li add kyg\n";
    //         cin >> y;
    //         p->Use_card(y);
    //         break;

    //     case 6:
    //         p->print_resources();
    //         break;

    //     case 7:
    //         p->print_points();
    //         break;

    //     case 8:
    //         game->Get_Board()->print_board();
    //         break;

    //     case 9:
    //         p->End_turn();
    //         switch_turn = true;
    //         break;

    //     default:
    //         cout << "incorrect input, try again\n";
    //         break;
    //     }
    // }
}