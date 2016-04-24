#include "RoutingGame.hpp"
#include <SFML/Graphics.hpp>
#include "Tile.hpp"

RoutingGame::RoutingGame()
{
    m_win.create(sf::VideoMode(640u, 480u), "Routing Game");
    m_renderer.init(m_win);
    m_map.generate(10u, 10u);
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
    m_map.render(m_renderer);
    m_renderer.flush();
    m_win.display();
}
