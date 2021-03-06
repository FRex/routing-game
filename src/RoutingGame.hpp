/* 
 * File:   RoutingGame.hpp
 * Author: frex
 *
 * Created on April 24, 2016, 5:36 PM
 */

#ifndef ROUTINGGAME_HPP
#define	ROUTINGGAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "Renderer.hpp"
#include "Map.hpp"

class RoutingGame
{
public:
    RoutingGame();
    void run();

private:
    void update();
    void draw();
    void setTitle();
    void newGame(unsigned w, unsigned h);

    sf::RenderWindow m_win;
    Renderer m_renderer;
    Map m_map;
    bool m_won;

};

#endif	/* ROUTINGGAME_HPP */

