#pragma once

#include <vector>

#include "Snake.h"

namespace snakegame
{

namespace constants
{
enum class MAP_ELEMENTS : char;
enum class INPUTS : char;
}

using CharMat = std::vector<std::vector<constants::MAP_ELEMENTS>>;
using SnakePtr = std::unique_ptr<Snake>;

class Map
{
public:
    Map(int width = 10, int height = 10);
    void movePlayer(constants::INPUTS input);
    void update();

private:
    int m_width, m_height;
    CharMat m_map{ m_width, std::vector<constants::MAP_ELEMENTS>(m_height) };
    SnakePtr m_player = std::make_unique<Snake>();
};
} //namespace

