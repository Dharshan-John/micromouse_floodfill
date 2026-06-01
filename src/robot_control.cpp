
#include "robot_control.h"
#include "api.h"
#include  "maze.h"

namespace Robot_Control{
    void readAndRecord(int currentX,int currentY, robot::Direction heading){
        if(API::wallFront()) Maze::setWall(currentX,currentY,heading);
    
        if(API::wallLeft()){
            robot::Direction leftdir = static_cast<robot::Direction> ((heading+3)%4);
            Maze::setWall(currentX,currentY,leftdir);
        }

        if(API::wallRight()){
            robot::Direction rightdir = static_cast<robot::Direction> ((heading+1)%4);
            Maze::setWall(currentX,currentY,rightdir);
        }
    }

    void alignHeading(robot::Direction targetHeading,robot::Direction &currentHeading){
        int shift = (targetHeading - currentHeading + 4) % 4;
        switch(shift){
            case 1:
                API::turnRight();
                currentHeading = static_cast<robot::Direction> ((currentHeading+1)%4);
                break;
        
            case 2:
                API::turnRight();
                currentHeading = static_cast<robot::Direction>((currentHeading + 1) % 4);
                API::turnRight();
                currentHeading = static_cast<robot::Direction>((currentHeading + 1) % 4);
                break;
        
            case 3:
                API::turnLeft();
                currentHeading = static_cast<robot::Direction>((currentHeading + 3) % 4);
                break;
            default:
                break;
        }   
    }
}