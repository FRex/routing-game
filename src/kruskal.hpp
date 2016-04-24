/* 
 * File:   kruskal.hpp
 * Author: frex
 *
 * Created on April 24, 2016, 9:09 PM
 */

#ifndef KRUSKAL_HPP
#define	KRUSKAL_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>

class XorShifter;

std::vector<sf::Vector2u> kruskal(unsigned x, unsigned y, XorShifter& xshifter);

#endif	/* KRUSKAL_HPP */

