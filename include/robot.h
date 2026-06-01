

#ifndef ROBOT_H
#define ROBOT_H

namespace robot {
    enum Direction{
        NORTH = 0,
        EAST = 1,
        SOUTH = 2,
        WEST= 3
    };

    struct Coordinates{
        int x;
        int y;
    };
}

#endif