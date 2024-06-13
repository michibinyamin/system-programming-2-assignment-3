// ID - 208768978
// Email - michibinyamin@gmail.com

#include "Path.hpp"

#include "Position.hpp"

using namespace std;

// Constructor with number
Path::Path(int num) : number(num), owner(0) {
    positions[0] = nullptr;
    positions[1] = nullptr;
}

// Copy constructor
Path::Path(Path* path) : number(path->number), owner(path->owner) {
}

// Default constructor
Path::Path() : number(0), owner(0) {
    positions[0] = nullptr;
    positions[1] = nullptr;
}

// Getter for number
int Path::get_number() {
    return number;
}

// Getter for owner
int Path::get_player() {
    return owner;
}

// Setter for position
void Path::set_position(Position* p) {
    for (int i = 0; i < 2; ++i) {
        if (positions[i] == nullptr) {  // If not initialized
            positions[i] = p;
            return;  // success
        }
    }
}

// Destructor
Path::~Path() {
}
