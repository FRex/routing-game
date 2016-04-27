#include "RoutingGame.hpp"
#include <SFML/Graphics.hpp>
#include "Tile.hpp"
#include <ctime>

RoutingGame::RoutingGame()
{
    m_win.create(sf::VideoMode(640u, 480u), "game");
    m_renderer.init(m_win);
    newGame(5u, 5u);
    setTitle();
}

void RoutingGame::run()
{
    while(m_win.isOpen())
    {
        update();
        draw();
    }
}

static void moveView(sf::RenderTarget& t, sf::Vector2f m)
{
    sf::View v = t.getView();
    v.move(m);
    t.setView(v);
}

void RoutingGame::update()
{
    sf::Event eve;
    while(m_win.pollEvent(eve))
    {
        if(eve.type == sf::Event::Closed)
            m_win.close();

        if(!m_won && eve.type == sf::Event::MouseButtonPressed && eve.mouseButton.button == sf::Mouse::Left)
        {
            const sf::Vector2f mpos = m_win.mapPixelToCoords(sf::Vector2i(eve.mouseButton.x, eve.mouseButton.y));
            const unsigned x = mpos.x / kTileSize;
            const unsigned y = mpos.y / kTileSize;
            m_map.rotateTileRight(x, y);
            if(m_map.getEnergizedTiles() == m_map.getTotalTiles())
                m_won = true;

            setTitle();
        }
        if(eve.type == sf::Event::KeyPressed)
        {
            switch(eve.key.code)
            {
                case sf::Keyboard::F1:
                    newGame(5u, 5u);
                    break;
                case sf::Keyboard::F2:
                    newGame(10u, 15u);
                    break;
                case sf::Keyboard::F3:
                    newGame(20u, 30u);
                    break;
                case sf::Keyboard::F4:
                    newGame(40u, 60u);
                    break;
                case sf::Keyboard::F5:
                    newGame(50u, 100u);
                    break;
                case sf::Keyboard::W:
                    moveView(m_win, sf::Vector2f(0.f, -75.f));
                    break;
                case sf::Keyboard::S:
                    moveView(m_win, sf::Vector2f(0.f, 75.f));
                    break;
                case sf::Keyboard::A:
                    moveView(m_win, sf::Vector2f(-75.f, 0.f));
                    break;
                case sf::Keyboard::D:
                    moveView(m_win, sf::Vector2f(75.f, 0.f));
                    break;
                case sf::Keyboard::Space:
                    if(!m_won)
                    {
                        m_map.randomlyRotate(static_cast<unsigned>(std::time(NULL)));
                        setTitle();
                    }
                    break;
            }//switch eve key code
        }
        if(eve.type == sf::Event::Resized)
        {
            sf::View v = m_win.getView();
            v.setSize(sf::Vector2f(eve.size.width, eve.size.height));
            m_win.setView(v);
        }
    }//while win poll event eve
}

void RoutingGame::draw()
{
    m_win.clear();
    m_map.render(m_renderer);

    //cursor shadow
    const sf::Vector2f mpos = m_win.mapPixelToCoords(sf::Mouse::getPosition(m_win));
    const unsigned x = mpos.x / kTileSize;
    const unsigned y = mpos.y / kTileSize;
    if(x < m_map.getWidth() && y < m_map.getHeight())
        m_renderer.renderCursorShadow(x, y);

    m_renderer.flush();
    m_win.display();
}

void RoutingGame::setTitle()
{
    char buff[128];
    std::sprintf(buff, "Routing Game: 0x%x %u/%u %s",
            m_map.getSeed(),
            m_map.getEnergizedTiles(),
            m_map.getTotalTiles(),
            m_won?"(solved)":""
            );

    m_win.setTitle(sf::String(buff));
}

void RoutingGame::newGame(unsigned w, unsigned h)
{
    m_won = false;
    m_map.generate(w, h, static_cast<unsigned>(std::time(NULL)));
    sf::View v = m_win.getView();
    v.setCenter(v.getSize() / 2.f);
    m_win.setView(v);
    setTitle();
}
