#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class Game {
public:
    Game();
    void handleClick(int x, int y);
    void draw(sf::RenderWindow& window);
    void resetGame();

private:
    Board board;
    bool isXTurn;
    bool gameOver;  // track whether the game is over
    char winner;    // store the winner ('X' or 'O')
    sf::Font font;  // font for displaying the winner message
    sf::Text winnerText; // text for displaying the winner message
    void setupWinnerText(); // helper function to setup the winner text
};

#endif
