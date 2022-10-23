#include <vector>
#include <iostream>
#include <windows.h>
#include <memory>
#include <thread>

namespace constants
{
    enum class MAP_ELEMENTS : char
    {
        WALL = '#',
        EMPTY = ' ',
        PLAYER = 'S'
    };

    enum class INPUTS :  char
    {
        UP = 'w',
        DOWN = 's',
        LEFT = 'a',
        RIGHT = 'd'
    };
}

using CharMat = std::vector<std::vector<constants::MAP_ELEMENTS>>;

class Vector2
{
    public:
    Vector2() = delete;
    Vector2(double x, double y)
    : m_x (x), m_y(y)
    {}
    double x () {return m_x;}
    double y () {return m_y;}
    Vector2& operator+=(const Vector2& other) {

        this->m_x += other.m_x;
        this->m_y += other.m_y;
        return *this;
    }

    private:
    double m_x, m_y;
};

class Snake
{
public:
    Vector2 getPosition()
    {
        return position;
    }
    void move(Vector2 movement)
    {
        position += movement;
        std::cout << "x : " << position.x() << " y : " << position.y() << "\n";
    }
private:
    Vector2 position{0,0};
};

using SnakePtr = std::unique_ptr<Snake>;

class Map
{

public:
    Map(int width = 10, int height = 10)
        : m_width(width), m_height(height)
    {
        for (int i = 0; i < width; i ++)
        {
            for (int j = 0; j < height; j++)
            {
                if (i == 0 || j == 0 || i == width - 1|| j == height -1)
                    m_map[i][j] = constants::MAP_ELEMENTS::WALL;
                else 
                    m_map[i][j] = constants::MAP_ELEMENTS::EMPTY;
            }
        }
    }

    void movePlayer(constants::INPUTS input)
    {
        switch (input)
        {
        case constants::INPUTS::UP:
            m_player->move({ 0,-1 });
            break;
        case constants::INPUTS::DOWN: 
            m_player->move({ 0,1 });
            break;
        case constants::INPUTS::LEFT: 
            m_player->move({ -1,0 });
            break;
        case constants::INPUTS::RIGHT: 
            m_player->move({ 1,0 });
            break;
        }
    }

    static void clearScreen()
    {	
        COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    }

    void update() {
        static  long long unsigned int frameNumber{ 0 };
        while(true)
        {
            std::string output;
            clearScreen();
            if (frameNumber % 5000 == 0)  
            {
                m_player->move({ 0,1 });
                system("CLS");
            }

            Vector2 playerPosition = m_player->getPosition();
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
    } 

private: 
    int m_width, m_height;
    CharMat m_map {m_width, std::vector<constants::MAP_ELEMENTS>(m_height)};
    SnakePtr m_player = std::make_unique<Snake>();
};


int main ()
{
    Map myMap(10, 10);
    char input;
    std::thread t1 (&Map::update, &myMap);

    while (true)
    {
        std::cin >> input;
        myMap.movePlayer(static_cast<constants::INPUTS>(input));
    }
}