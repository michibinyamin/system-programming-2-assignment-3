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
    int number;  // Indicating which path it is
    int owner;   // Indicates to who the path belongs
    Position* positions[2];

public:
    // Constructors
    Path(int num);
    Path(Path* path);
    Path();

    // Getter methods
    int get_number();
    int get_player();

    // Setter methods
    void set_position(Position* p);

    // Destructor
    ~Path();
};

#endif  // PATH_HPP