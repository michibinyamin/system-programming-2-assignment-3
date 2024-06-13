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
int Path::get_owner() {
    return owner;
}

Position* Path::get_position(int p) {
    return positions[p];
}

bool Path::has_position(int p) {
    if (positions[0]->get_owner() == p || positions[1]->get_owner() == p) {
        return true;
    }
    return false;
}

bool Path::has_neighbors(int p){
    if (positions[0]->has_path(p) || positions[1]->has_path(p))
    {
        return true;
    }
    return false;
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
void Path::set_owner(int n) {
    owner = n;
}

// Destructor
Path::~Path() {
}
