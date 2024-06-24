#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>

class Board{
    public:
        Board();
        void draw(sf::RenderWindow& window);
        void placeMark(int x, int y, bool isX);
        bool checkWin();
        bool checkDraw();

    private:
        sf::RectangleShape grid[3][3];
        char board[3][3];
        sf::Font font;
};

#endif