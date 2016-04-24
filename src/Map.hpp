/* 
 * File:   Map.hpp
 * Author: frex
 *
 * Created on April 24, 2016, 6:58 PM
 */

#ifndef MAP_HPP
#define	MAP_HPP

#include <vector>

class Renderer;

class Map
{
public:
    void generate(unsigned w, unsigned h);
    void render(Renderer& renderer);

private:
    std::vector<unsigned> m_tiles;
    unsigned m_width;
    unsigned m_height;

};

#endif	/* MAP_HPP */

