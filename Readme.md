# Visual Tic-Tac-Toe

A graphical implementation of the classic Tic-Tac-Toe game using SFML.

## Features

- Graphical user interface using SFML.
- Blue 'X' and red 'O' marks.
- Automatic detection of win and draw conditions.
- Game freezes when a player wins or the game is drawn.

## Requirements

- C++ compiler
- SFML library
- Arial font file (`arial.ttf`)

## Installation

### Step 1: Clone the Repository

`git clone https://github.com/theivyzhang/visual-tic-tac-toe.git `
`cd visual-tic-tac-toe`

### Step 2: Install SFML
1. On Ubuntu: `sudo apt-get install libsfml-dev`
2. On MacOS:   `brew install sfml`
3. On Windows: Download the SFML library from the SFML website and follow the instructions to set it up with your development environment.

### Step 3: Add the Arial Font
Make sure you have the arial.ttf font file in the project directory. If you don't have it, you can download it from various free font websites.

### Step 4: Build the Project
Using CMake
1. Create a CMakeLists.txt file with the following content:
"cmake_minimum_required(VERSION 3.10)
project(VisualTicTacToe)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(VisualTicTacToe main.cpp Board.cpp Game.cpp)

target_link_libraries(VisualTicTacToe sfml-graphics sfml-window sfml-system)"

2. Build the project
`mkdir build`
`cd build`
`cmake ..`
`make`

3. Run the executable:
`./VisualTicTacToe`


