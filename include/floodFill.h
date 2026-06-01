

#ifndef FLOODFILL_H
#define FLOODFILL_H
#include "robot.h"

namespace FloodFill
{   
    /**
     * @brief The core mathematical solver. 
     * Resets the cell cost distance array, sets the center 4 target cells to 0, 
     * and "floods" the values outward across all known walls.
     * @note Call this every time a new wall is discovered.
     */
    void runFloodFill();

    /**
     * @brief Inspects the surrounding available cells and returns the best direction.
     * @param currentX Current X coordinate of the robot
     * @param currentY Current Y coordinate of the robot
     * @param currentHeading The physical direction the robot is currently facing
     * @return The Direction (NORTH, EAST, etc.) matching the lowest-cost neighbor tile.
     */
    robot::Direction suggestBestDirection(int currentX, int currentY, robot::Direction currentDir);

    /**
     * @brief Fetches the calculated flood-fill distance/cost value of a specific cell.
     * @note Crucial for printing numbers to the desktop simulator interface!
     */
    int getDistance(int x, int y);
    
}

#endif 