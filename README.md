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

# MMS Simulator

## Micromouse Simulator (MMS)

This project is designed to run on the Micromouse Simulator (MMS), a virtual environment for developing and testing maze-solving algorithms without requiring physical hardware.

The simulator provides:

- A configurable 16×16 Micromouse maze environment.
- Sensor APIs for detecting walls in front, left, and right directions.
- Movement APIs for moving the robot and changing its orientation.
- Visualization tools for displaying explored cells, wall information, and debugging data.
- Support for testing maze-solving algorithms such as Flood Fill, BFS, DFS, and shortest-path optimization.

The simulator communicates with the solver through the provided API interface, allowing the algorithm to:
- Read wall information.
- Update the internal maze representation.
- Compute flood-fill distances.
- Determine the next movement.
- Navigate the mouse toward the goal.

## Running the Micromouse Simulator

### Prerequisites

- Micromouse Simulator (MMS)
- C++ compiler (GCC, Clang, or MSVC)
- Git (optional)

### Build the Solver

Compile the source files:

```bash
g++ src/*.cpp -Iinclude -o build_mouse
```

### Start the Simulator

1. Launch the Micromouse Simulator.
2. Load or generate a maze.
3. Configure the simulator to use the compiled solver executable.
4. Start the simulation.

### Running the Solver

Execute the compiled program:

```bash
./build_mouse
```

On Windows:

```cmd
build_mouse.exe
```

The solver will communicate with the simulator through the API interface and begin exploring the maze using the Flood Fill Algorithm.

### Visualization

The simulator provides visualization features for:

- Wall detection
- Cell coloring
- Distance values
- Mouse position and orientation
- Path exploration

These features can be used to debug and analyze the maze-solving process.

For more information about the simulator and its API, refer to the official MMS documentation.
