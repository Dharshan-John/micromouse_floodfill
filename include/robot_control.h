
#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H
#include "robot.h"

namespace Robot_Control{
    void readAndRecord(int currentX,int currentY, robot::Direction heading);
    void alignHeading(robot::Direction targetHeading,robot::Direction& CurrentHeading);
}

#endif