// ID - 208768978
// Email - michibinyamin@gmail.com

#include <iostream>
#include "Board.hpp"

struct position_data
{
    int Dposition_num;
    int Dpaths[3];
    int DTiles[3];
};

position_data positions_data[] = {
    // position, {path1,path2,path3}, {Tile1,Tile2,Tile3}
    {0, {0,6,-1}, {0,-1,-1}},
    {1, {0,1,-1}, {0,-1,-1} },
    {2, {1,2,7},{0,1,-1}},
    {3, {2,3,-1}, {1,-1,-1}},
    {4, {3,4,8}, {1,2,-1}},
    {5, {4,5,-1}, {2,-1,-1}},
    {6, {5,9,-1}, {2,-1,-1}},
    {7, {10,18,-1}, {3,-1,-1}},
    {8, {6,10,11}, {0,3,-1}},
    {9, {11,12,19}, {0,3,4}},
    {10, {7,12,13}, {0,1,4}},
    {11, {13,14,20}, {1,4,5}},
    {12, {8,14,15}, {1,2,5}},
    {13, {15,16,21}, {2,5,6}},
    {14, {9,16,17}, {2,6,-1}},
    {15, {17,22,-1}, {6,-1,-1}},
    {16, {23,33,-1}, {7,-1,-1}},
    {17, {18,23,24}, {3,7,-1}},
    {18, {24,25,34}, {3,7,8}},
    {19, {19,25,26}, {3,4,8}},
    {20, {26,27,35}, {4,8,9}},
    {21, {20,27,28}, {4,5,9}},
    {22, {28,29,36}, {5,9,10}},
    {23, {21,29,30}, {5,6,10}},
    {24, {30,31,37}, {6,10,11}},
    {25, {22,31,32}, {6,11,-1}},
    {26, {32,38,-1}, {11,-1,-1}},
    {27, {33,39,-1}, {7,-1,-1}},
    {28, {39,40,49}, {7,12,-1}},
    {29, {34,40,41}, {7,8,12}},
    {30, {41,42,50}, {8,12,13}},
    {31, {35,42,43}, {8,9,13}},
    {32, {43,44,51}, {9,13,14}},
    {33, {36,44,45}, {9,10,14}},
    {34, {45,46,52}, {10,14,15}},
    {35, {37,46,47}, {10,11,15}},
    {36, {47,48,53}, {11,15,-1}},
    {37, {38,48,-1}, {11,-1,-1}},
    {38, {49,54,-1}, {12,-1,-1}},
    {39, {54,55,62}, {12,16,-1}},
    {40, {50,55,56}, {12,13,16}},
    {41, {56,57,63}, {13,16,17}},
    {42, {51,57,58}, {13,14,17}},
    {43, {58,59,64}, {14,17,18}},
    {44, {52,59,60}, {14,15,18}},
    {45, {60,61,65}, {15,18,-1}},
    {46, {53,61,-1}, {15,-1,-1}},
    {47, {62,66,-1}, {16,-1,-1}},
    {48, {66,67,-1}, {16,-1,-1}},
    {49, {63,67,68}, {16,17,-1}},
    {50, {68,69,-1}, {17,-1,-1}},
    {51, {64,69,70}, {17,18,-1}},
    {52, {70,71,-1}, {18,-1,-1}},
    {53, {65,71,-1}, {18,-1,-1}}
};

Board::Board(Tile new_tile[19])
{
    // Copy elements individually or use std::copy to avoid direct assignment
    for (int i = 0; i < 19; ++i){
        tiles[i] = new_tile[i];
    }
    init_board();
}
Board::~Board() {
}
void Board::init_board()
{
    // Init positions 
    for (int i = 0; i < 54; i++)
    {
        positions[i].set_number(i);
        for (int j = 0; j < 3; j++)
        {
            // Connect Paths to position and connect the corrosponding positions to the paths
            if (positions_data[i].Dpaths[j] != -1)
            {
                int PathIdx = positions_data[i].Dpaths[j];
                positions[i].set_path(paths[PathIdx]);
                paths[PathIdx].set_position(&positions[i]);
            }

            // Connect tiles to the postions
            if (positions_data[i].DTiles[j] != -1)
            {
                int TileIdx = positions_data[i].DTiles[j];
                positions[i].set_tiles(&tiles[TileIdx]);
            }
        }
    }
}

bool Board::set_position(int p, int owner){
    // At least one of them has a path + no neighboring settelment + no
    // settelment in current spot
    if (p < 0 || p > 53)
    {
        return false;
    }
    Position* position = get_position(p);
    if (position->has_path(owner) && position->no_neighbors() && position->get_owner() == 0) 
    {
        position->set_owner(owner);
        return true;
    }
    
    return false;
}

bool Board::set_position_initial(int p, int owner){
    if (p < 0 || p > 53) {
        return false;
    }
    Position* position = get_position(p);
    if (position->get_owner() == 0 && position->no_neighbors()) {
        position->set_owner(owner);
        return true;
    }
    return false;
}

bool Board::set_path(int p, int owner){
    // 
    if (p < 0 || p > 71) {
        return false;
    }
    Path* path = get_path(p);
    if (path->get_owner() == 0 && (path->has_position(owner) || path->has_neighbors(owner)) )
    {
        path->set_owner(owner);
        return true;
    }

    return false;
}

Position* Board::get_position(int p){
    return &positions[p];
}

Path* Board::get_path(int p){
    return &paths[p];
}

void Board::print_board()
{
    cout << "         ";
    for (int i = 0; i < 3; i++)
    {
        
        cout << tiles[i].get_land() <<","<< to_string(tiles[i].get_number());
        cout << "  ";
    }
    cout << "\n";

    cout << "    ";
    for (int i = 3; i < 7; i++)
    {
        cout << tiles[i].get_land() <<","<< to_string(tiles[i].get_number());
        cout << "  ";
    }
    cout << "\n";

    for (int i = 7; i < 12; i++)
    {
        cout << tiles[i].get_land() <<","<< to_string(tiles[i].get_number());
        cout << "  ";
    }
    cout << "\n";

    cout << "    ";
    for (int i = 12; i < 16; i++)
    {
        cout << tiles[i].get_land() <<","<< to_string(tiles[i].get_number());
        cout << "  ";
    }
    cout << "\n";
    cout << "         ";

    for (int i = 16; i < 19; i++)
    {
        cout << tiles[i].get_land() <<","<< to_string(tiles[i].get_number());
        cout << "  ";
    }
    cout<<"\n";


    cout<<"                       -::::           .::::.           :::::                       \n";                    
    cout<<"                    -:      .-:     .-.      .=:     :=.      :-                    \n";             
    cout<<"                 :-             -.-:            .- =.            :-                 \n";             
    cout<<"                 -.             ::-              -.-              +                 \n";             
    cout<<"                 -.             ::-              -.-              +                 \n";         
    cout <<"                     "<< tiles[0].get_land() <<","<< to_string(tiles[0].get_number());      
    cout <<"        "<< tiles[1].get_land() <<","<< to_string(tiles[1].get_number()); 
    cout <<"        "<< tiles[2].get_land() <<","<< to_string(tiles[2].get_number())<<"\n"; 
    cout<<"                 -.             ::-              -.-              +                 \n"; 
    cout<<"                 .-.           :-.:-.           :: -:           .-:                 \n";
    cout<<"                ::  .=.     :-.  -:  :-      --  .=.  -:      =:  ::                \n";
    cout<<"            .:-    -:. .-:-. .:-   .-:. ::::. .:.   ::. .-::: .:-    -:.            \n";
    cout<<"         .::.         .:: ::.         .::. ::.         .:: .::.         .-.         \n";
    cout<<"         .              ...              :-              .-:              ..        \n";
    cout<<"         .              ...              :-              .-:              ..        \n";
    cout <<"            "<< tiles[3].get_land() <<","<< to_string(tiles[3].get_number());      
    cout <<"        "<< tiles[4].get_land() <<","<< to_string(tiles[4].get_number()); 
    cout <<"       "<< tiles[5].get_land() <<","<< to_string(tiles[5].get_number()); 
    cout <<"      "<< tiles[6].get_land() <<","<< to_string(tiles[6].get_number())<<"\n"; 
    cout<<"         .              ...              :-              .-:              ..        \n";
    cout<<"         .              ...              ::.             .::              :.        \n";
    cout<<"        . .::.       ::. . .::       .::. . ::.       .:: . .::.       ::. .        \n";
    cout<<"     .-...:- .:-. -:. :-...-: .:: .-:  -:...-. .-. ::. .-. .:- .:- .-:. ::...-:     \n";
    cout<<" .=.        ::    :-        .=.    -:        .-.   .=.        -:    :-        .=.   \n";
    cout<<"-              =-.             ::=              -.=              +..             .: \n";
    cout<<":              --.             ::-              - -              +..             .. \n";
    cout <<"    "<< tiles[7].get_land() <<","<< to_string(tiles[7].get_number());      
    cout <<"         "<< tiles[8].get_land() <<","<< to_string(tiles[8].get_number()); 
    cout <<"        "<< tiles[9].get_land() <<","<< to_string(tiles[9].get_number()); 
    cout <<"         "<< tiles[10].get_land() <<","<< to_string(tiles[10].get_number()); 
    cout <<"        "<< tiles[11].get_land() <<","<< to_string(tiles[11].get_number())<<"\n"; 
    cout<<":              --.             ::-              - -              +..             .. \n";
    cout<<":              --.             ::-              - -              +..             .. \n";
    cout<<".-:          -:  :=.         .-.  :-          :-. .-.          -:  :=          .=.  \n";
    cout<<"   .-:   .-- .:--:. :-.   .-. .:--:  -:.   :-  .-:-. .-:   .-- .:--:. :-.   .-.     \n";
    cout<<"      .:: .::      ::. .:. .::     .::. ::..::.     .::..:: .::      ::. ::.        \n";
    cout<<"        :.            .:.:.            .:::            .-::.            .-          \n";
    cout<<"        .               ..              :-              .-:              ..         \n";
    cout<<"        .              ...              :-              .-:              ..         \n";
    cout <<"            "<< tiles[12].get_land() <<","<< to_string(tiles[12].get_number());      
    cout <<"         "<< tiles[13].get_land() <<","<< to_string(tiles[13].get_number()); 
    cout <<"       "<< tiles[14].get_land() <<","<< to_string(tiles[14].get_number()); 
    cout <<"     "<< tiles[15].get_land() <<","<< to_string(tiles[15].get_number())<<"\n"; 
    cout<<"        .              ...              :-              .-:              ..         \n";
    cout<<"        ::.           .:.:.           .::.:.           .-.::.          ..:          \n";
    cout<<"          .::.     ::.:::::.::     .::.::::..::     ::.:::::.::.     ::.            \n";
    cout<<"              .--: :-.     .-..:-=..-:      .=..---..=.      :-.:=-:                \n";
    cout<<"                :-            .-.--            :- =.            --                  \n";
    cout<<"                -.             ::-              - -              +                  \n";
    cout<<"                -.             ::-              - -              +                  \n";
    cout <<"                    "<< tiles[16].get_land() <<","<< to_string(tiles[16].get_number());      
    cout <<"        "<< tiles[17].get_land() <<","<< to_string(tiles[17].get_number()); 
    cout <<"        "<< tiles[18].get_land() <<","<< to_string(tiles[18].get_number())<<"\n"; 
    cout<<"                -.             ::-              - -              +                  \n";
    cout<<"                :-            .-.::            :- -.            --                  \n";
    cout<<"                   .-      .=.      --      :=.     .=:      --                     \n";
    cout<<"                      :::-.            :::-.           .-:::                        \n";
    }
