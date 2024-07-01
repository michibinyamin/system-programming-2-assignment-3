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
    cout<<"\n";


    cout<<"                       .:"<<positions[1].get_owner()<<"::           .:"<<positions[3].get_owner()<<"::.           ::"<<positions[5].get_owner()<<"::                       \n";                    
    cout<<"                    :"<<paths[0].get_owner()<<"      ."<<paths[1].get_owner()<<":     ."<<paths[2].get_owner()<<".      ."<<paths[3].get_owner()<<":     :"<<paths[4].get_owner()<<".      :"<<paths[5].get_owner()<<"                    \n";             
    cout<<"                  "<<positions[0].get_owner()<<"             ."<<positions[2].get_owner()<<".:            .."<<positions[4].get_owner()<<" .            :"<<positions[6].get_owner()<<"                 \n";             
    cout<<"                 ..             ::.              ...              .                 \n";             
    cout<<"                 ..             ::.              ...              .                 \n";         
    cout <<"                  "<<paths[6].get_owner()<<"  "<< tiles[0].get_land() <<","<< to_string(tiles[0].get_number());      
    cout <<"    "<<paths[7].get_owner()<<"   "<< tiles[1].get_land() <<","<< to_string(tiles[1].get_number()); 
    cout <<"  "<<paths[8].get_owner()<<"   "<< tiles[2].get_land() <<","<< to_string(tiles[2].get_number())<<"  "<<paths[9].get_owner()<<"\n"; 
    cout<<"                 ..             ::.              ...              .                 \n"; 
    cout<<"                 ...           :..:..           :: .:           ..:                 \n";
    cout<<"                ::"<<positions[8].get_owner()<<" ...     :..  "<<positions[10].get_owner()<<":  :.      ..  ."<<positions[12].get_owner()<<".  .:      .:  "<<positions[14].get_owner()<<":                \n";
    cout<<"            .:"<<paths[10].get_owner()<<"    .:."<<paths[11].get_owner()<<" ..:.. "<<paths[12].get_owner()<<"..   ."<<paths[13].get_owner()<<":. ::::."<<paths[14].get_owner()<<".:.   :"<<paths[15].get_owner()<<". ..:::"<<paths[16].get_owner()<<".:.    "<<paths[17].get_owner()<<":.            \n";
    cout<<"         "<<positions[7].get_owner()<<"::.         .::"<<positions[9].get_owner()<<"::.         .::"<<positions[11].get_owner()<<" ::.         .::"<<positions[13].get_owner()<<".::.         .."<<positions[15].get_owner()<<"         \n";
    cout<<"         .              ...              :.              ..:              ..        \n";
    cout<<"         .              ...              :.              ..:              ..        \n";
    cout <<"         "<<paths[18].get_owner()<<"  "<< tiles[3].get_land() <<","<< to_string(tiles[3].get_number());      
    cout <<"   "<<paths[19].get_owner()<<"   "<< tiles[4].get_land() <<","<< to_string(tiles[4].get_number()); 
    cout <<"    "<<paths[20].get_owner()<<"  "<< tiles[5].get_land() <<","<< to_string(tiles[5].get_number()); 
    cout <<"  "<<paths[21].get_owner()<<"    "<< tiles[6].get_land() <<","<< to_string(tiles[6].get_number())<<"   "<<paths[22].get_owner()<<"\n"; 
    cout<<"         .              ...              :.              ..:              ..        \n";
    cout<<"         .              ...              ::.             .::              :.        \n";
    cout<<"        ."<<positions[17].get_owner()<<".::.       ::. "<<positions[19].get_owner()<<" .::       .::."<<positions[21].get_owner()<<"  ::.       .:: "<<positions[23].get_owner()<<" .::.       ::."<<positions[25].get_owner()<<".        \n";
    cout<<"     "<<paths[23].get_owner()<<"....:. "<<paths[24].get_owner()<<":.. .:."<<paths[25].get_owner()<<":....."<<paths[26].get_owner()<<" .:: ..:"<<paths[27].get_owner()<<" .:...."<<paths[28].get_owner()<<" ... ::."<<paths[29].get_owner()<<"... .: "<<paths[30].get_owner()<<".:. ..:"<<paths[31].get_owner()<<" ::...."<<paths[32].get_owner()<<"     \n";
    cout<<positions[16].get_owner()<<"...        ::  "<<positions[18].get_owner()<<" :.        ... "<<positions[20].get_owner()<<"  .:        ... "<<positions[22].get_owner()<<" ...        .:  "<<positions[24].get_owner()<<" :.        ... "<<positions[26].get_owner()<<"  \n";
    cout<<".              ...             ::.              ...              ...             .: \n";
    cout<<":              ...             ::.              . .              ...             .. \n";
    cout<<paths[33].get_owner()<<"   "<< tiles[7].get_land() <<","<< to_string(tiles[7].get_number());      
    cout <<"    "<<paths[34].get_owner()<<"    "<< tiles[8].get_land() <<","<< to_string(tiles[8].get_number()); 
    cout <<"    "<<paths[35].get_owner()<<"   "<< tiles[9].get_land() <<","<< to_string(tiles[9].get_number()); 
    cout <<"     "<<paths[36].get_owner()<<"   "<< tiles[10].get_land() <<","<< to_string(tiles[10].get_number()); 
    cout <<"     "<<paths[37].get_owner()<<"  "<< tiles[11].get_land() <<","<< to_string(tiles[11].get_number())<<"    "<<paths[38].get_owner()<<"\n"; 
    cout<<":              ...             ::.              . .              ...             .. \n";
    cout<<":              ...             ::.              . .              ...             .. \n";
    cout<<positions[27].get_owner()<<".:          .: "<<positions[29].get_owner()<<":..         ..."<<positions[31].get_owner()<<" :.          :.."<<positions[33].get_owner()<<"...          .: "<<positions[35].get_owner()<<":.          ..."<<positions[37].get_owner()<<" \n";
    cout<<"   ."<<paths[39].get_owner()<<":   ..."<<paths[40].get_owner()<<".:..:. "<<paths[41].get_owner()<<"..   ..."<<paths[42].get_owner()<<".:..: "<<paths[43].get_owner()<<".:.   :."<<paths[44].get_owner()<<" ..:.. "<<paths[45].get_owner()<<".:   ..."<<paths[46].get_owner()<<".:..:. "<<paths[47].get_owner()<<"..   .."<<paths[48].get_owner()<<"     \n";
    cout<<"      .:"<<positions[28].get_owner()<<" .::      ::. ."<<positions[30].get_owner()<<". .::     .::. "<<positions[32].get_owner()<<":..::.     .::.."<<positions[34].get_owner()<<": .::      ::. :"<<positions[36].get_owner()<<".        \n";
    cout<<"        :.            .:.:.            .:::            ..::.            ..          \n";
    cout<<"        .              ...              :.              ..:              ..         \n";
    cout <<"        "<<paths[49].get_owner()<<"   "<< tiles[12].get_land() <<","<< to_string(tiles[12].get_number());      
    cout <<"     "<<paths[50].get_owner()<<"   "<< tiles[13].get_land() <<","<< to_string(tiles[13].get_number()); 
    cout <<"  "<<paths[51].get_owner()<<"   "<< tiles[14].get_land() <<","<< to_string(tiles[14].get_number()); 
    cout <<"  "<<paths[52].get_owner()<<"  "<< tiles[15].get_land() <<","<< to_string(tiles[15].get_number())<<"  "<<paths[53].get_owner()<<"\n"; 
    cout<<"        .               ..              :.              ..:              ..         \n";
    cout<<"        .              ...              :.              ..:              ..         \n";
    cout<<"        "<<positions[38].get_owner()<<":.           .:"<<positions[40].get_owner()<<":.           .:"<<positions[42].get_owner()<<".:.           .."<<positions[44].get_owner()<<"::.          ..:"<<positions[46].get_owner()<<"         \n";
    cout<<"          .:"<<paths[54].get_owner()<<"..     "<<paths[55].get_owner()<<"..:::::"<<paths[56].get_owner()<<".:     "<<paths[57].get_owner()<<".:.::::"<<paths[58].get_owner()<<".::     "<<paths[59].get_owner()<<"..:::::"<<paths[60].get_owner()<<".:.    "<<paths[61].get_owner()<<"..            \n";
    cout<<"              .."<<positions[39].get_owner()<<": :..     ....:"<<positions[41].get_owner()<<"....:      ....."<<positions[43].get_owner()<<".....      :..:"<<positions[45].get_owner()<<".:                \n";
    cout<<"                :.            .....            :. ..            ..                  \n";
    cout<<"                ..             ::.              . .              .                  \n";
    cout <<"                "<<paths[62].get_owner()<<"   "<< tiles[16].get_land() <<","<< to_string(tiles[16].get_number());      
    cout <<"    "<<paths[63].get_owner()<<"   "<< tiles[17].get_land() <<","<< to_string(tiles[17].get_number()); 
    cout <<"    "<<paths[64].get_owner()<<"    "<< tiles[18].get_land() <<","<< to_string(tiles[18].get_number())<<"    "<<paths[65].get_owner()<<"\n"; 
    cout<<"                ..             ::.              . .              .                  \n";
    cout<<"                ..             ::.              . .              .                  \n";
    cout<<"                "<<positions[47].get_owner()<<".            .."<<positions[49].get_owner()<<"::            :."<<positions[51].get_owner()<<"..            ."<<positions[53].get_owner()<<"                  \n";
    cout<<"                   "<<paths[66].get_owner()<<".      .."<<paths[67].get_owner()<<"      "<<paths[68].get_owner()<<".      :"<<paths[69].get_owner()<<".     ."<<paths[70].get_owner()<<":      ."<<paths[71].get_owner()<<"                     \n";
    cout<<"                      :."<<positions[48].get_owner()<<".:            :"<<positions[50].get_owner()<<":..           .."<<positions[52].get_owner()<<"::                        \n";
    }
