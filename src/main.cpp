#include <thread>
#include <iostream>

#include "Vector2.h"
#include "Map.h"

#include <SFML/Graphics.hpp>

using namespace snakegame;

int main()
{
    /*Map myMap(10, 10);
    char input;
    std::thread t1(&Map::update, &myMap);

    while (true)
    {
        std::cin >> input;
        myMap.movePlayer(static_cast<constants::INPUTS>(input));
    }*/

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}