
#include<iostream>
#include "api.h"
#include<string>

namespace API{
    bool wallFront(){
        std::cout<<"wallFront"<<std::endl;
        std::string response;
        std::cin>>response;
        return (response == "true");
    }

    bool wallLeft(){
        std::cout<<"wallLeft"<<std::endl;
        std::string response;
        std::cin>>response;
        return (response == "true");
    }

    bool wallRight(){
        std::cout<<"wallRight"<<std::endl;
        std::string response;
        std::cin>>response;
        return (response == "true");
    }

    void moveForward(){
        std::cout<<"moveForward"<<std::endl;
        std::string response;
        std::cin>>response;
    }

    void turnLeft(){
        std::cout<<"turnLeft"<<std::endl;
        std::string response;
        std::cin>>response;
    }

    void turnRight(){
        std::cout<<"turnRight"<<std::endl;
        std::string response;
        std::cin>>response;
    }

    void setColor(int x,int y, char color){
        std::cout<<"Set Color"<<x<<" "<<y<<" "<<color<<std::endl;
    }

    void setText(int x,int y,const std::string& text){
        std::cout<<"Set Text"<<x<<" "<<y<<" "<<text<<std::endl;
    }
}