#include "RoutingGame.hpp"
#include <SFML/Graphics.hpp>
#include "Tile.hpp"

RoutingGame::RoutingGame()
{
    m_win.create(sf::VideoMode(640u, 480u), "Routing Game");
    m_renderer.init(m_win);
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
    m_renderer.renderTile(0u, 0u, ETF_CONNECT_NORTH);
    m_renderer.renderTile(1u, 0u, ETF_CONNECT_SOUTH);
    m_renderer.renderTile(2u, 0u, ETF_CONNECT_EAST);
    m_renderer.renderTile(3u, 0u, ETF_CONNECT_WEST);
    m_renderer.renderTile(5u, 0u, ~0);

    m_renderer.draw();
    m_win.display();
}
