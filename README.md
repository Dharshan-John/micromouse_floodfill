# Micromouse Maze Solver using Flood Fill Algorithm

## Introduction

This repository contains a Micromouse maze-solving implementation based on the Flood Fill Algorithm.

The project is organized into two main directories:

## Project Structure
``` text
.
├── include/
│   ├── api.h
│   ├── floodFill.h
│   ├── maze.h
│   ├── robot.h
│   └── robot_control.h
├── src/
│   ├── api.cpp
│   ├── floodFill.cpp
│   ├── main.cpp
│   ├── maze.cpp
│   └── robot_control.cpp
└── README.md
```

### include/
Contains the header files that define function declarations, class and structure definitions, constants, and shared interfaces used throughout the project.

### src/
Contains the source files that implement the project logic, including maze initialization, flood fill computation, wall detection and mapping, path planning, and communication with the simulator to control the robot's movements.