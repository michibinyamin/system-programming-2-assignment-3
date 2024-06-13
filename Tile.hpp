// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef TILE_HPP
#define TILE_HPP

#include <string>

using namespace std;

class Tile {
private:
    string land;
    int number;

public:
    // Default constructor
    Tile();

    // Parameterized constructor
    Tile(string Land, int Number);

    // Copy constructor (using a pointer to Tile)
    Tile(Tile* tile);

    // Getter for land
    string get_land();

    // Getter for number
    int get_number();

    // Placeholder for notify method
    void notify();

    // Destructor
    ~Tile();
};

#endif  // TYLE_HPP
