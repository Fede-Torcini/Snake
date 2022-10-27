#pragma once

#include <SFML/Graphics.hpp>

#include "Snake.h"

namespace snakegame
{

struct Score
{
    Score();
    sf::Font m_font;
    sf::Text scoreText;
    size_t m_value;
};

using SnakePtr = std::unique_ptr<Snake>;

class Game
{
public:
    Game();
    void initVariables();
    void initWindow();
    void update();
    void render();
    bool running() const;
    void pollEvents();

private:
    
    std::unique_ptr<sf::RenderWindow> m_window;
    sf::Event m_event;
    sf::VideoMode m_videoMode;

    Score m_score;
    SnakePtr m_player = std::make_unique<Snake>();
    RenderShape m_food;
};
} //namespace

