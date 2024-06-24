#include "Board.h"
#include <iostream> // Include this for std::cout

Board::Board() {
    // initialize the grid and board array
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = sf::RectangleShape(sf::Vector2f(200, 200));
            grid[i][j].setPosition(j * 200, i * 200); 
            grid[i][j].setOutlineColor(sf::Color::Black);
            grid[i][j].setOutlineThickness(5);
            board[i][j] = ' ';
        }
    }
    // load a font (you will need a .ttf file in the project directory)
    if (!font.loadFromFile("arial.ttf")) {
        // handle error
        std::cerr << "Error loading font" << std::endl;
    }
}

void Board::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            window.draw(grid[i][j]);
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                sf::Text mark;
                mark.setFont(font);
                mark.setString(board[i][j]);
                mark.setCharacterSize(200); // ensure the font size is large enough

                // set the color based on the mark
                if (board[i][j] == 'X') {
                    mark.setFillColor(sf::Color::Blue);
                } else if (board[i][j] == 'O') {
                    mark.setFillColor(sf::Color::Red);
                }

                // center the text in the cell
                sf::FloatRect textRect = mark.getLocalBounds();
                mark.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
                mark.setPosition(j * 200 + 100, i * 200 + 100);

                window.draw(mark);
            }
        }
    }
}



void Board::placeMark(int x, int y, bool isX) {
    int row = y / 200; 
    int col = x / 200;
    if (board[row][col] == ' ') {
        board[row][col] = isX ? 'X' : 'O';
        std::cout << "Placed " << (isX ? 'X' : 'O') << " at (" << row << ", " << col << ")" << std::endl;
    } else {
        std::cout << "Cell (" << row << ", " << col << ") is already occupied" << std::endl;
    }
}

bool Board::checkWin() {
    // check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return true;
    }

    return false;
}

bool Board::checkDraw() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;  // there is at least one empty cell
            }
        }
    }

    if (checkWin()) {
        return false;  // there is a winner, so it cannot be a draw
    }

    return true;  // all cells are filled and there is no winner
}
