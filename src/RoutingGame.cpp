#include "RoutingGame.hpp"
#include <SFML/Graphics.hpp>

RoutingGame::RoutingGame()
{
    m_win.create(sf::VideoMode(640u, 480u), "Routing Game");
}

void RoutingGame::run()
{
    while(m_win.isOpen())
    {
        update();
        draw();
    }
}

void RoutingGame::update()
{
    sf::Event eve;
    while(m_win.pollEvent(eve))
    {
        if(eve.type == sf::Event::Closed)
            m_win.close();
    }
}

void RoutingGame::draw()
{
    m_win.clear();

    m_win.display();
}
