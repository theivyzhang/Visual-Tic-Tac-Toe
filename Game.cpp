#include "Game.h"
#include <iostream>

Game::Game() : isXTurn(true), gameOver(false), winner(' ') {
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
        exit(1);
    }
    setupWinnerText();
}

void Game::setupWinnerText() {
    winnerText.setFont(font);
    winnerText.setCharacterSize(50); // set the font size
    winnerText.setFillColor(sf::Color::Black);
    winnerText.setPosition(150, 270); // position in the middle of the screen
}

void Game::handleClick(int x, int y) {
    if (gameOver) return; // ignore clicks if the game is over

    board.placeMark(x, y, isXTurn);

    if (board.checkWin()) {
        winner = isXTurn ? 'X' : 'O';
        std::cout << winner << " has won!" << std::endl;
        winnerText.setString(winner + std::string(" has won!"));
        gameOver = true; // stop the game
    } else if (board.checkDraw()) {
        std::cout << "It's a draw!" << std::endl;
        winnerText.setString("It's a draw!");
        gameOver = true; // stop the game on draw
    } else {
        isXTurn = !isXTurn; // switch turns
    }
}

void Game::draw(sf::RenderWindow& window) {
    board.draw(window);
    if (gameOver) {
        window.draw(winnerText); // draw the winner message
    }
}

void Game::resetGame() {
    board = Board(); // reinitialize the board
    isXTurn = true;  // reset the turn to X
    gameOver = false; // reset the game over flag
    winner = ' '; // reset the winner
    winnerText.setString(""); // clear the winner text
}
