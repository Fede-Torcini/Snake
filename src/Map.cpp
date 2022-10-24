#include <windows.h>
#include <string>
#include <vector>
#include <iostream>

#include "Map.h"
#include "Vector2.h"

namespace snakegame
{
namespace constants
{
enum class MAP_ELEMENTS : char
{
    WALL = '#',
    EMPTY = ' ',
    PLAYER = 'S'
};

enum class INPUTS : char
{
    UP = 'w',
    DOWN = 's',
    LEFT = 'a',
    RIGHT = 'd'
};
} //namespace constants

Map::Map(int width, int height)
    : m_width(width), m_height(height)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
                m_map[i][j] = constants::MAP_ELEMENTS::WALL;
            else
                m_map[i][j] = constants::MAP_ELEMENTS::EMPTY;
        }
    }
}

void Map::movePlayer(constants::INPUTS input)
{
    switch (input)
    {
    case constants::INPUTS::UP:
        m_player->setVelocity({ 0,-1 });
        break;
    case constants::INPUTS::DOWN:
        m_player->setVelocity({ 0,1 });
        break;
    case constants::INPUTS::LEFT:
        m_player->setVelocity({ -1,0 });
        break;
    case constants::INPUTS::RIGHT:
        m_player->setVelocity({ 1,0 });
        break;
    }
}

static void clearScreen()
{
    COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Map::update()
{
    static  long long unsigned int frameNumber{ 0 };
    while (true)
    {
        std::string output;
        clearScreen();
        if (frameNumber % 5000 == 0)
        {
            m_player->move();
            system("CLS");
        }

        snakegame::Vector2 playerPosition = m_player->getPosition();
        for (int j = 0; j < m_height; j++)
        {
            for (int i = 0; i < m_width; i++)
            {
                if (playerPosition.x() == i && playerPosition.y() == j)
                    output += (static_cast<char>(constants::MAP_ELEMENTS::PLAYER) + std::string(" "));
                else
                    output += (static_cast<char>(m_map[i][j]) + std::string(" "));
            }
            output += "\n";
        }
        std::cout << output;
        frameNumber++;
    }
};
} //namespace snakegame