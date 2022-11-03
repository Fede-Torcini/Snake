#include "Game.h"
#include "Constants.h"

namespace snakegame
{

Game::Game()
    :m_food(constants::RAT_TEXTURE_DIRECTORY), m_videoMode({constants::WINDOW_WIDTH,constants::WINDOW_HEIGHT})
{
    this->initVariables();
    this->initWindow();
}


void Game::initVariables()
{
    m_food.setSize(sf::Vector2f(constants::SPRITES_WIDTH, constants::SPRITES_HEIGHT));
    m_food.setPosition(sf::Vector2f(rand() % m_videoMode.width, rand() % m_videoMode.height));
}


void Game::initWindow()
{
    m_window = std::make_unique<sf::RenderWindow>(m_videoMode, constants::WINDOW_NAME);

    m_window->setFramerateLimit(60);
}


void Game::update()
{
    //Event handling
    this->pollEvents();

    //Game Update
    m_player->move();
    if (!m_player->alive())
    {
        m_window->close();
    }
    else if (m_player->intersects(m_food))
    {
        m_player->grow();
        m_food.setPosition(sf::Vector2f(rand() % m_videoMode.width, rand() % m_videoMode.height));
        m_score.m_value++;
        m_score.scoreText.setString(std::to_string(m_score.m_value));
    }
}

/*
 * Cleans window, makes draw calls
 */
void Game::render()
{
    m_window->clear();

    m_window->draw(m_score.scoreText);
    m_window->draw(m_player->draw(), m_player->partCount() * 4, sf::Quads, m_player->getTexture());
    m_window->draw(m_food);

    m_window->display();
}


bool Game::running() const
{
    return m_window->isOpen();
}


void Game::pollEvents()
{
    while (m_window->pollEvent(m_event))
    {
        switch (m_event.type)
        {
        case sf::Event::Closed:
            m_window->close();
            break;
        case sf::Event::KeyPressed:
          
            switch (m_event.key.code)
            {
            //move up
            case sf::Keyboard::W:
                m_player->setVelocity({ 0,-1 });
                break;
            //move down
            case sf::Keyboard::S:
                m_player->setVelocity({ 0,1 });
                break;
            //move left
            case sf::Keyboard::A:
                m_player->setVelocity({ -1,0 });
                break;
            //move right
            case sf::Keyboard::D:
                m_player->setVelocity({ 1,0 });
                break;
            case sf::Keyboard::Escape:
                m_window->close();
                break;
            }
            break;
        } 
    }
}
Score::Score()
    : m_value(0)
{
    //initializing 
    m_font.loadFromFile(constants::TEXT_FONT_DIR);
    scoreText.setPosition({ constants::WINDOW_WIDTH / 2 - constants::SCORE_TEXT_SIZE / 2, constants::WINDOW_HEIGHT / 2 - constants::SCORE_TEXT_SIZE / 2});
    scoreText.setFont(m_font);
    scoreText.setString(std::to_string(m_value));
    scoreText.setCharacterSize(constants::SCORE_TEXT_SIZE); // in pixels, not points!
    scoreText.setFillColor(sf::Color::White);
    scoreText.setStyle(sf::Text::Bold);
}
} //namespace snakegame