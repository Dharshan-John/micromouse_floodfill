
#ifndef API_H
#define API_H
#include <string>

namespace API{
    bool wallFront();
    bool wallLeft();
    bool wallRight();

    void moveForward();
    void turnLeft();
    void turnRight();

    void setColor(int x,int y,char color);
    void setText(int x,int y,const std::string& text);
}

#endif