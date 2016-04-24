/* 
 * File:   RoutingGame.hpp
 * Author: frex
 *
 * Created on April 24, 2016, 5:36 PM
 */

#ifndef ROUTINGGAME_HPP
#define	ROUTINGGAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class RoutingGame
{
public:
    RoutingGame();
    void run();

private:
    void update();
    void draw();
    
    sf::RenderWindow m_win;

};

#endif	/* ROUTINGGAME_HPP */

