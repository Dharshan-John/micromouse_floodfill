

#ifndef MAZE_H
#define MAZE_H
#include "robot.h"

namespace Maze{
    // Resets the entire 16x16 grid, clearing internal walls 
    // and setting up the known outer perimeter boundaries
    void init();

    // Adds a wall to the virtual memory grid based on coordinate and direction
    void setWall(int x, int y, robot::Direction dir);

    // Checks if there is a wall in the specified direction from the given coordinates
    bool hasWall(int x, int y, robot::Direction dir);

    // Marks the cell at the given coordinates as visited
    bool markVisited(int x, int y);

    // Checks if the cell at the given coordinates has been visited
    bool isVisited(int x, int y);
}

#endif