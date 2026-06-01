
#include "maze.h"
#include "floodFill.h"
#include "robot.h"
#include  <queue>
#include  <vector>
#include  <utility>

namespace FloodFill{
    static int dist[16][16];
    static std::vector<std::pair<int,int>> Dir = {{0,1},{1,0},{0,-1},{-1,0}};

    void runFloodFill(){
        std::queue<std::pair<int,int>> target;

        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++)
                dist[i][j] = -1;
        }

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                dist[7+i][7+j] = 0;
                target.push({7+i,7+j});
            }
        }

        while(!target.empty()){
            std::pair<int,int> activeCell = target.front();
            int activeX = activeCell.first;
            int activeY = activeCell.second;
            target.pop();

            int activeDist = dist[activeX][activeY];
            for(int it=0;it<4;it++){
                robot::Direction currentDir = static_cast<robot::Direction> (it);

                int neighborX = activeX + Dir[it].first;
                int neighborY = activeY + Dir[it].second;
                if(neighborX<0 || neighborX>15 ||
                   neighborY<0 || neighborY>15) continue;
                if(Maze::hasWall(activeX,activeY,currentDir)) continue;
                if(dist[neighborX][neighborY] >= activeDist+1 || dist[neighborX][neighborY] == -1){ 
                        dist[neighborX][neighborY] = activeDist + 1;
                        target.push({neighborX,neighborY});
                }
            }           
        }
    }

    robot::Direction suggestBestDirection(int currentX, int currentY, robot::Direction currentHeading){
        int minDist = 1000;
        robot::Direction bestDir = currentHeading;
        for(int it=0;it<4;it++){
            robot::Direction currentDir = static_cast<robot::Direction> (it);
            if(Maze::hasWall(currentX,currentY,currentDir)) continue;

            int neighborX = currentX + Dir[it].first;
            int neighborY = currentY + Dir[it].second;
            if(neighborX<0 || neighborX>15 || neighborY<0 || neighborY>15) continue;
            if(dist[neighborX][neighborY] == -1) continue;

            if(dist[neighborX][neighborY] < minDist){
                minDist = dist[neighborX][neighborY];
                bestDir = currentDir;
            }
            else if(dist[neighborX][neighborY] == minDist){
                bool currentChoiceVisited = Maze::isVisited(neighborX, neighborY);
    
                // Calculate what the bestDir coordinate looks like right now
                int bestX = currentX + Dir[static_cast<int>(bestDir)].first;
                int bestY = currentY + Dir[static_cast<int>(bestDir)].second;
                bool bestChoiceVisited = Maze::isVisited(bestX, bestY);

                // If our previous best choice was already visited, but this alternative path 
                // is unvisited, the unvisited corridor instantly steals the priority!
                if (bestChoiceVisited && !currentChoiceVisited) {
                    bestDir = currentDir;
                }
                // Secondary tie-breaker: If both are unvisited or both are visited,
                // prioritize keeping momentum (going straight ahead)
                else if (currentChoiceVisited == bestChoiceVisited) {
                if (currentDir == currentHeading)
                    bestDir = currentDir;
                }
        }
     }
     return bestDir;
    }

    int getDistance(int x,int y){
        if(x<0 || x>15 || y<0 || y<15) return -1;
        return dist[x][y];
    }
 }