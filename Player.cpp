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

    three_knights = false;
}

Player::~Player() {
    // Free cards
    for (auto C : Development_cards)
    {
        delete C;
    }
}

bool Player::won_game() {
    if (points >= 10) {
        return true;
    }
    return false;
}

void Player::set_num(int n) {
    player_num = n;
}

string Player::getname() {
    return name;
}

bool Player::Roll_dice() {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    if (rolled) {
        cout << "Can't roll twice in one turn\n";
        return false;
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
    return true;
}

void Player::seven_rolled(){
    int sum = forest + hills + pastures + mountains + fields;
    if (sum <= 7){
        return;
    }

    if (forest%2 == 0)
    {
        forest = forest/2;
    }else{
        forest = forest/2 + 1;
    }

    if (hills%2 == 0)
    {
        hills = hills/2;
    }else{
        hills = hills/2 + 1;
    }
    
    if (pastures % 2 == 0) {
        pastures = pastures / 2;
    } else {
        pastures = pastures / 2 + 1;
    }

    if (mountains % 2 == 0) {
        mountains = mountains / 2;
    } else {
        mountains = mountains / 2 + 1;
    }

    if (fields % 2 == 0) {
        fields = fields / 2;
    } else {
        fields = fields / 2 + 1;
    }
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

            cout << name + " placed settalment succesfully on position -  " << p
                 << "\n";
            positions.push_back(position);
            settelment++;
            get_point();
            return true;
        } else {
            cout << "cannot place there a settelment\n";
            return false;
        }
    } else {
        if (!rolled) {
            cout << "You must first roll the dice\n";
            return false;
        }
        if (forest < 1 || hills < 1 || pastures < 1 || fields < 1) {
            cout << "You do not have the required resources to build a "
                    "settelment\n";
            return false;
        }

        if (game->Get_Board()->set_position(p, player_num)) {
            cout << name + " placed settalment succesfully on position -  " << p
                 << "\n";

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

bool Player::placeCity(int p) {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    if (!rolled) {
        cout << "You must first roll the dice\n";
        return false;
    }
    Position* position = game->Get_Board()->get_position(p);
    if (position->get_owner() != player_num) {
        cout << "you do not have a settalment there\n";
        return false;
    }
    if (mountains < 3 || fields < 2) {
        cout << "You do not have the required resources to build a city\n";
        return false;
    }
    mountains = mountains - 3;
    fields = fields - 2;
    position->set_city(player_num);
    cout << "City set on the position\n";
    get_point();
    return true;
}

bool Player::placeRoad(int p) {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    if (roads < 2) {
        if (game->Get_Board()->set_path(p, player_num)) {
            cout << name + " placed road succesfully on - " << p << " \n";
            roads++;
            game->Next_Turn();
            return true;
        } else {
            cout << "cannot place there a road\n";
            return false;
        }
    } else {
        if (!rolled) {
            cout << "You must first roll the dice\n";
            return false;
        }
        if (forest < 1 || hills < 1) {
            cout << "You do not have the required resources to build a road\n";
            return false;
        } else {
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

// Go over all the positions where player has built and receive resources if it
// is the correct number
void Player::get_resources(int result) {
    bool t = false;
    int old_forest = forest;
    int old_hills = hills;
    int old_pastures = pastures;
    int old_mountains = mountains;
    int old_fields = fields;
    for (int i = 0; i < positions.size(); i++) {
        Position* p = positions[i];
        for (int j = 0; j < 3; j++) {
            if (p->get_tiles()[j] != nullptr) {
                if (p->get_tiles()[j]->get_number() == result) {
                    t = true;
                    string land = p->get_tiles()[j]->get_land();
                    if (land == "forest") {
                        forest++;
                        if (p->is_city()) {
                            forest++;
                        }
                    } else if (land == "hills") {
                        hills++;
                        if (p->is_city()) {
                            hills++;
                        }
                    } else if (land == "pastures") {
                        pastures++;
                        if (p->is_city()) {
                            pastures++;
                        }
                    } else if (land == "mountains") {
                        mountains++;
                        if (p->is_city()) {
                            mountains++;
                        }
                    } else if (land == "fields") {
                        fields++;
                        if (p->is_city()) {
                            fields++;
                        }
                    } else {
                        // Do nothing
                    }
                }
            }
        }
    }
    // Print
    if (t) {
        cout << name + " recieved : \n";
        if (old_forest != forest) {
            cout << forest - old_forest << " forest\n";
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
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    if (!rolled) {
        cout << "You must first roll the dice\n";
        return false;
    }
    if (pastures < 1 || fields < 1 || mountains < 1) {
        cout << "You do not have the required resources to buy a development "
                "card\n";
        return false;
    }
    DevelopmentCard* card = game->Get_card();
    Development_cards.push_back(card);
    cout << "you got The card : " << card->Get_name() << "\n";
    return true;
}

// Used for victory point and Road builder
bool Player::Use_card(string card_name) {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards.at(i)->Get_name() == card_name) {
            if (card_name == "Victory point") {
                VictoryPointCard* card = dynamic_cast<VictoryPointCard*>(
                    Development_cards.at(i));  // Downcasting
                card->action(this);
                Development_cards.erase(Development_cards.begin() + i);
                cout << "Succesfully used " << card_name << " card\n";
                cout << name + " ended hes turn\n";
                rolled = false;
                game->Next_Turn();
                return true;
            } else if (card_name == "Road builder") {
                RoadBuilderCard* card = dynamic_cast<RoadBuilderCard*>(
                    Development_cards.at(i));  // Downcasting
                card->action(this);
                Development_cards.erase(Development_cards.begin() + i);
                cout << "Succesfully used " << card_name << " card\n";
                cout << name + " ended hes turn\n";
                rolled = false;
                game->Next_Turn();
                return true;
            } else {
                throw runtime_error("Error with deck \n");
            }
        }
    }
    cout << "You do not have this card!\n";
    return false;
}

// Used for Year of plenty
bool Player::Use_card(string card_name, string resource1, string resource2) {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards.at(i)->Get_name() == card_name) {
            if (card_name == "Year of plenty") {
                YearOfPlentyCard* card = dynamic_cast<YearOfPlentyCard*>(Development_cards.at(i));  // Downcasting
                if (card->action(this, resource1, resource2)) {
                    Development_cards.erase(Development_cards.begin() + i);
                    cout << "Succesfully used " << card_name << " card\n";
                    cout << name + " ended hes turn\n";
                    rolled = false;
                    game->Next_Turn();
                    return true;
                } else {
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

// Used for Monopoly
bool Player::Use_card(string card_name, string resource) {
    if (!My_turn()) {
        cout << "Not your turn, it is " << game->Get_Turn_name() << "'s turn\n";
        return false;
    }
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards.at(i)->Get_name() == card_name) {
            if (card_name == "Monopoly") {
                MonopolyCard* card = dynamic_cast<MonopolyCard*>(
                    Development_cards.at(i));  // Downcasting
                if (card->action(this, resource)) {
                    Development_cards.erase(Development_cards.begin() + i);
                    cout << "Succesfully used " << card_name << " card\n";
                    cout << name + " ended hes turn\n";
                    rolled = false;
                    game->Next_Turn();
                    return true;
                } else {
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

bool Player::has_development_card(string card) {
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards[i]->Get_name() == card) {
            return true;
        }
    }
    return false;
}

bool Player::legal_trade(Player* p, string card, string card2) {
    if ((card == "forest" && p->forest == 0) ||
        (card2 == "forest" && forest == 0)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "hills" && p->hills > 0) ||
               (card2 == "hills" && hills == 0)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "pastures" && p->pastures > 0) ||
               (card2 == "pastures" && pastures == 0)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "mountains" && p->mountains > 0) ||
               (card2 == "mountains" && mountains == 0)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "fields" && p->fields > 0) ||
               (card2 == "fields" && fields == 0)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "knight" && !has_development_card(card)) ||
               (card2 == "knight") && !has_development_card(card2)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "Monopoly" && !has_development_card(card)) ||
               (card2 == "Monopoly") && !has_development_card(card2)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "Road builder" && !has_development_card(card)) ||
               (card2 == "Road builder") && !has_development_card(card2)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "Victory point" && !has_development_card(card)) ||
               (card2 == "Victory point") && !has_development_card(card2)) {
        cout << "player does not have this card\n";
        return false;
    } else if ((card == "Year of plenty" && !has_development_card(card)) ||
               (card2 == "Year of plenty") && !has_development_card(card2)) {
        cout << "player does not have this card\n";
        return false;
    }
    return true;
}

DevelopmentCard* Player::take_development_card(string card) {
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards[i]->Get_name() == card) {
            DevelopmentCard* new_card = Development_cards[i];
            Development_cards.erase(Development_cards.begin() + i);
            return new_card;
        }
    }
    throw runtime_error("No such card");
}

void Player::get_develpoment_card(DevelopmentCard* card) {  
    Development_cards.push_back(card);
    count_knights();
}

bool Player::trade(Player* p, string card, string card2) {
    if (!legal_trade(p, card, card2)) {
        return false;
    }

    if (card == "forest") {
        p->forest--;
        achive_resource("forest", 1);
    } else if (card == "hills") {
        p->hills--;
        achive_resource("hills", 1);
    } else if (card == "pastures") {
        p->pastures--;
        achive_resource("pastures", 1);
    } else if (card == "mountains") {
        p->mountains--;
        achive_resource("mountains", 1);
    } else if (card == "fields") {
        p->fields--;
        achive_resource("fields", 1);
    }

    if (card2 == "forest") {
        forest--;
        p->achive_resource("forest", 1);
    } else if (card2 == "hills") {
        hills--;
        p->achive_resource("hills", 1);
    } else if (card2 == "pastures") {
        pastures--;
        p->achive_resource("pastures", 1);
    } else if (card2 == "mountains") {
        mountains--;
        p->achive_resource("mountains", 1);
    } else if (card2 == "fields") {
        fields--;
        p->achive_resource("fields", 1);
    }

    if (card == "Knight" || card == "Monopoly" || card == "Road builder" ||
             card == "Victioy Point" || card == "Year of plenty") {
        get_develpoment_card(p->take_development_card(card));
    }
    if (card2 == "Knight" || card2 == "Monopoly" ||
               card2 == "Road builder" || card2 == "Victioy Point" ||
               card2 == "Year of plenty") {
        p->get_develpoment_card(take_development_card(card2));
    }
    count_knights();
    return true;
}

bool Player::achive_resource(string res, int times) {
    if (res == "forest") {
        forest += times;
    } else if (res == "hills") {
        hills += times;
    } else if (res == "pastures") {
        pastures += times;
    } else if (res == "mountains") {
        mountains += times;
    } else if (res == "fields") {
        fields += times;
    } else {
        return false;
    }
    return true;
}

int Player::steal_resources(string res) {
    int amount = 0;
    if (res == "forest") {
        while (forest > 0) {
            forest--;
            amount++;
        }
    } else if (res == "hills") {
        while (hills > 0) {
            hills--;
            amount++;
        }
    } else if (res == "pastures") {
        while (pastures > 0) {
            pastures--;
            amount++;
        }
    } else if (res == "mountains") {
        while (mountains > 0) {
            mountains--;
            amount++;
        }
    } else if (res == "fields") {
        while (fields > 0) {
            fields--;
            amount++;
        }
    } else {
        return 0;
    }
    return amount;
}

bool Player::count_knights() {
    int count = 0;
    for (int i = 0; i < Development_cards.size(); i++) {
        if (Development_cards[i]->Get_name() == "Knight") {
            count++;
        }
    }
    if (count == 3) {
        if (!three_knights) {
            three_knights = true;
            points = points + 2;
        }
        return true;
    } else {
        if (three_knights) {
            points = points - 2;
            three_knights = false;
        }
    }
    return false;
}

void Player::get_point() {
    points++;
}

void Player::print_points() {
    cout << name + "'s points: " << points << "\n";
}

void Player::print_resources() {
    cout << "\n" + name + "'s resources:\n";
    cout << "forest: " + to_string(forest) + "\n";
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
    if (!rolled) {
        cout << "You must first roll the dice\n";
        return;
    }
    cout << name + " ended hes turn\n";
    rolled = false;
    game->Next_Turn();
}