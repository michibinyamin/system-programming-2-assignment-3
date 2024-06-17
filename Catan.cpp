// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Catan.hpp"

#include <iostream>

#include "Board.hpp"

Catan::Catan(Player* p1, Player* p2, Player* p3, Tile* new_tiles) {
    player1 = p1;
    player1->set_num(1);
    player1->set_game(this);

    player2 = p2;
    player2->set_num(2);
    player2->set_game(this);

    player3 = p3;
    player3->set_num(3);
    player3->set_game(this);

    board = new Board(new_tiles);

    for (size_t i = 0; i < 5; i++)
    {
        DevelopmentCards.push_back(new VictoryPointCard(this));
    }
    // Add more!!
    
    turn = 1;  // Player one starts
}

void Catan::Dice_roled(int result){
    player1->get_resources(result);
    player2->get_resources(result);
    player3->get_resources(result);
}

void Catan::Next_Turn() { 
    if(turn == 3){turn = 1;}
    else{turn++;}
    cout << "\n"+Get_Turn() + "'s turn : \n";
}

string Catan::Get_Turn() {
    if (turn == 1)
    {
        return player1->getname();
    }
    else if (turn == 2) {
        return player2->getname();
    }
    else if (turn == 3) {
        return player3->getname();
    }
    else{
        throw runtime_error("error with turn\n");
    }
}

DevelopmentCard* Catan::Get_card(){
    int size = DevelopmentCards.size();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, size-1);
    int num = dis(gen);
    DevelopmentCard* d = DevelopmentCards.at(num);
    DevelopmentCards.erase(DevelopmentCards.begin()+num);
    return d;
}

Board* Catan::Get_Board() {
    return board;
}

Catan::~Catan() {
}
