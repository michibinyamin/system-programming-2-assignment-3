// ID - 208768978
// Email - michibinyamin@gmail.com

#ifndef PATH_HPP
#define PATH_HPP

#include <iostream>
#include <string>
//#include "Position.hpp"
class Position;  // Forward declaration of position

class Path {
private:
    int number;  // Indicating which path it is representing on the board
    int owner;   // Indicates to who the path belongs
    Position* positions[2];

public:
    // Constructors
    Path(int num);
    Path(Path* path);
    Path();

    // Getter methods
    int get_number();
    int get_owner();
    bool has_position(int p);   // Checks if this path has a position which belongs to p
    bool has_neighbors(int p);  // Return true if this path has neighbor paths which belong to p
    Position* get_position(int p);

    // Setter methods
    void set_position(Position* p);
    void set_owner(int n);

    // Destructor
    ~Path();
};

#endif  // PATH_HPP