#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    // create a window with a title and dimensions 600x600 pixels
    sf::RenderWindow window(sf::VideoMode(600, 600), "Tic-tac-toe");

    Game game; // an instance of the Game class

    // main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // close window if the close event is triggered
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // handle mouse button press events
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // pass the click coordinates to the Game class
                    game.handleClick(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }

        // clear window with a white color
        window.clear(sf::Color::White);

        // draw the current state of the game
        game.draw(window);

        // display contents of the window
        window.display();
    }

    return 0;
}
