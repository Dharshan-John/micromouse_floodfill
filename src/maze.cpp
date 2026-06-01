
#include<iostream>
#include "maze.h"
#include<cstdint>

namespace Maze{
    static uint8_t walls[16][16];
    static bool visitedCells[16][16];

    void init(){
        walls[16][16] = {0};
        visitedCells[16][16] = {false};

        for(uint8_t x=0;x<16;x++) walls[x][0] |= (1<<robot::SOUTH);     // SOUTH BITMASK 4 
        for(uint8_t x=0;x<16;x++) walls[x][15] |= (1<<robot::NORTH);    // NORTH BITMASK 1
        for(uint8_t y=0;y<16;y++) walls[0][y] |= (1<<robot::WEST);      // WEST BITMASK 8
        for(uint8_t y=0;y<16;y++) walls[15][y] |= (1<<robot::EAST);     // EAST BITMASK 2
        walls[0][0] |= (1<<robot::EAST);
    }

    void setWall(int x,int y,robot::Direction dir){
        if(x<0 || x>15 || y<0 || y>15) return;
        walls[x][y] |= (1<<dir);  // By seeing the walls the bits are turned ON
        
        switch (dir)
        {
        case 0: // NORTH
            if(y+1<16) walls[x][y+1] |= (1<<robot::SOUTH);
            break;
        case 1: // EAST
            if(x+1<16) walls[x+1][y] |= (1<<robot::WEST);
            break;
        case 2: // SOUTH
            if(y-1>=0) walls[x][y-1] |= (1<<robot::NORTH);
            break;
        case 3: // WEST
            if(x-1>=0) walls[x-1][y] |= (1<<robot::EAST);
            break;
        default:
            break;
        }
    }

    bool hasWall(int x,int y, robot::Direction dir){
        if(x<0 || x>15 || y<0 || y>15) return true;
        short flag = (1<<dir);
        if((flag & walls[x][y]) != 0) return true;
        else return false;
    }

    bool markVisited(int x, int y){
        if(x<0 || x>15 || y<0 || y>15) return false;
        bool alreadyVisited = visitedCells[x][y];
        visitedCells[x][y] = 1;
        return alreadyVisited;
    }

    bool isVisited(int x,int y){
        if(x<0 || x>15 || y<0 || y>15) return false;
        return visitedCells[x][y];
    }
}