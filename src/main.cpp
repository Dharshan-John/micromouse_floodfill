
#include "maze.h"
#include "floodFill.h"
#include "robot.h"
#include "api.h"
#include "robot_control.h"

int main(){
    Maze::init();
    FloodFill::runFloodFill();
    int currentX = 0;
    int currentY = 0;
    robot::Direction currentHeading = robot::NORTH;

    while(true){
        Maze::markVisited(currentX,currentY);
        Robot_Control::readAndRecord(currentX,currentY,currentHeading);
        FloodFill::runFloodFill();

        robot::Direction nextHeading = FloodFill::suggestBestDirection(currentX,currentY,currentHeading); 
        Robot_Control::alignHeading(nextHeading, currentHeading);

        API::moveForward();

        if(currentHeading == robot::NORTH) currentY++;
        else if(currentHeading == robot::SOUTH) currentY--;
        else if(currentHeading == robot::EAST) currentX++;
        else if(currentHeading == robot::WEST) currentX--;
    }

    return 0;
}