// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Player.hpp"

#include <iostream>
#include <string>

#include "Catan.hpp"

Player::Player(string given_name) : name(given_name) {
    roads = 0;
    settelment = 0;
    points = 0;
    rolled = false;

    forest = 0;
    hills = 0; 
    pastures = 0;
    mountains = 0;
    fields = 0;
}

Player::~Player() {
}

void Player::set_num(int n) {
    player_num = n;
}

string Player::getname() {
    return name;
}

void Player::Roll_dice() {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return;
    }
    if(rolled) {
        cout << "Can't roll twice in one turn\n";
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);
    int dice_one = dis(gen);
    int dice_two = dis(gen);
    int result = dice_one + dice_two;
    cout << name << " threw dice. rolled on: " + to_string(result) + "\n";
    rolled = true;
    game->Dice_roled(result);
}

bool Player::placeSettelemnt(int p) {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }

    Position* position = game->Get_Board()->get_position(p);
    if (settelment < 2) {
        if (game->Get_Board()->set_position_initial(p, player_num)) {

            // Get the position's resources 
            for (int i = 0; i < 3; i++) {
                if (position->get_tiles()[i] != nullptr) {
                    string land = position->get_tiles()[i]->get_land();
                    if (land == "forest") {
                        forest++;
                    } else if (land == "hills") {
                        hills++;
                    } else if (land == "pastures") {
                        pastures++;
                    } else if (land == "mountains") {
                        mountains++;
                    } else if (land == "fields") {
                        fields++;
                    } else {
                        // Do nothing
                    }
                }
            }

            cout << name + " placed settalment succesfully on position -  " << p << "\n";
            positions.push_back(position);
            settelment++;
            get_point();
            return true;
        } else {
            cout << "cannot place there a settelment\n";
            return false;
        }
    } else {
        if (forest < 1 || hills < 1 || pastures < 1 || fields < 1)
        {
            cout << "You do not have the required resources to build a settelment\n";
            return false;
        }
        
        if (game->Get_Board()->set_position(p, player_num)) {  
            // Todo - add here to check if i have enogh cards to build a sttelment
            cout << name + " placed settalment succesfully on position -  " << p << "\n";
            
            forest--;
            hills--;
            pastures--;
            fields--;
            positions.push_back(position);
            settelment++;
            get_point();
            return true;
        }
        cout << "cannot place there a settelment\n";
        return false;
    }
}

bool Player::placeRoad(int p) {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    if (roads <= 2) {
        if (game->Get_Board()->set_path(p, player_num)) {
            cout << name + " placed road succesfully on - " << p << " \n";
            roads++;
            game->Next_Turn();
            return true;
        }else{
            cout << "cannot place there a road\n";
            return false;
        } 
    }
    else{
        if (forest < 1 || hills < 1) {
            cout << "You do not have the required resources to build a road\n";
            return false;
        }
        else{
            if (game->Get_Board()->set_path(p, player_num)) {
                cout << name + " placed road succesfully on - " << p << " \n";
                roads++;
                forest--;
                hills--;
                return true;
            }
        }
    }
    return false;
}

// Go over all the positions where player has built and receive resources if it is the correct number
void Player::get_resources(int result) {
    bool t = false;
    int old_forest = forest;
    int old_hills = hills;
    int old_pastures = pastures;
    int old_mountains = mountains;
    int old_fields = fields;
    for (int i = 0; i < positions.size(); i++)
    {
        Position* p = positions[i];
        for (int j = 0; j < 3; j++) {
            if (p->get_tiles()[j] != nullptr) {
                if (p->get_tiles()[j]->get_number() == result) {
                    t = true;
                    string land = p->get_tiles()[j]->get_land();
                    if (land == "forest") {
                        forest++;
                    } else if (land == "hills") {
                        hills++;
                    } else if (land == "pastures") {
                        pastures++;
                    } else if (land == "mountains") {
                        mountains++;
                    } else if (land == "fields") {
                        fields++;
                    } else {
                        // Do nothing
                    }
                }
            }
        }
    }
    // Print
    if (t)
    {
        cout << name+" recieved : \n";
        if (old_forest != forest)
        {
            cout << forest-old_forest << " forest\n";
        }
        if (old_hills != hills) {
            cout << hills - old_hills << " hills\n";
        }
        if (old_pastures != pastures) {
            cout << pastures - old_pastures << " pastures\n";
        }
        if (old_mountains != mountains) {
            cout << mountains - old_mountains << " mountains\n";
        }
        if (old_fields != fields) {
            cout << fields - old_fields << " fields\n";
        }
    }
}

bool Player::Buy_card() {
    if (pastures < 1 || fields < 1 || mountains < 1)
    {
        cout << "You do not have the required resources to buy a development card\n";
        return false;
    }
    DevelopmentCard* card = game->Get_card();
    Development_cards.push_back(card);
    cout << "you got The card : " << card->Get_name() << "\n";
    return true;
}

// Used for victory point (more can be added to here)
bool Player::Use_card(string card_name) {
    for (int i = 0; i < Development_cards.size(); i++)
    {
        if(Development_cards.at(i)->Get_name() == card_name){
            if (card_name == "Victory point")
            {
                VictoryPointCard* card = dynamic_cast<VictoryPointCard*>(Development_cards.at(i));       // Downcasting
                card->action(this);
                Development_cards.erase(Development_cards.begin()+i);
                cout << "Succesfully used " << card_name << " card\n";
                return true;
            } else {
                throw runtime_error("Error with deck \n");
            }
        }
    }
    cout << "You do not have this card!\n";
    return false;
}

// Used for Year of plenty (more can be added to here)
bool Player::Use_card(string card_name, string resource1, string resource2) {
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards.at(i)->Get_name() == card_name) {
            if (card_name == "Year of plenty") {
                YearOfPlentyCard* card = dynamic_cast<YearOfPlentyCard*>(Development_cards.at(i));  // Downcasting
                if(card->action(this, resource1, resource2)){
                    Development_cards.erase(Development_cards.begin() + i);
                    cout << "Succesfully used " << card_name << " card\n";
                    return true;
                }
                else{
                    return false;
                }
                
                
            } else {
                throw runtime_error("Error with deck");
            }
        }
    }
    cout << "You do not have this card!\n";
    return false;
}

// Used for Monopoly (more can be added to here)
bool Player::Use_card(string card_name, string resource) {
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards.at(i)->Get_name() == card_name) {
            if (card_name == "Monopoly") {
                MonopolyCard* card =
                dynamic_cast<MonopolyCard*>(Development_cards.at(i));  // Downcasting
                if (card->action(this, resource))
                {
                    Development_cards.erase(Development_cards.begin() + i);
                    cout << "Succesfully used " << card_name << " card\n";
                    return true;
                }
                else{
                    return false;
                }
            } else {
                throw runtime_error("Error with deck");
            }
        }
    }
    cout << "You do not have this card!\n";
    return false;
}

bool Player::achive_resource(string res, int times){
    if (res == "forest")
    {
        forest += times;
    }
    else if(res == "hills")
    {
        hills += times;
    }
    else if (res == "pastures")
    {
        pastures += times;
    }
    else if(res == "mountains")
    {
        mountains += times;
    }
    else if(res == "fields")
    {
        fields += times;
    }
    else{
        return false;
    }
    return true;
}

int Player::steal_resources(string res){
    int amount = 0;
    if (res == "forest")
    {
        while (forest > 0)
        {
            forest--;
            amount++;
        }
    }
    else if(res == "hills")
    {
        while (hills > 0)
        {
            hills--;
            amount++;
        }
    }
    else if (res == "pastures")
    {
        while (pastures > 0)
        {
            pastures--;
            amount++;
        }
    }
    else if(res == "mountains")
    {
        while (mountains > 0)
        {
            mountains--;
            amount++;
        }
    }
    else if(res == "fields")
    {
        while (fields > 0)
        {
            fields--;
            amount++;
        }
    }
    else{
        return 0;
    }
    return amount;
}

void Player::get_point(){
    points++;
}

void Player::print_points(){
    cout << name + "'s points: " << points << "\n";
}

void Player::print_resources(){
    cout << "\n" + name + "'s resources:\n";
    cout << "forest: " + to_string(forest)+"\n";
    cout << "hills: " + to_string(hills) + "\n";
    cout << "pastures: " + to_string(pastures) + "\n";
    cout << "mountains: " + to_string(mountains) + "\n";
    cout << "fields: " + to_string(fields) + "\n\n";
}

bool Player::My_turn() {
    return game->Get_Turn_name() == name;
}

void Player::End_turn() {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return;
    }
    cout << name + " ended hes turn\n";
    rolled = false;
    game->Next_Turn();
}