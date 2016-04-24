/* 
 * File:   Renderer.hpp
 * Author: frex
 *
 * Created on April 24, 2016, 6:15 PM
 */

#ifndef RENDERER_HPP
#define	RENDERER_HPP

#include <vector>
#include <SFML/Graphics/Vertex.hpp>

namespace sf {
class RenderTarget;
}//sf

class Renderer
{
public:
    void init(sf::RenderTarget& target);
    void renderTile(unsigned x, unsigned y, unsigned flags);
    void renderCursorShadow(unsigned x, unsigned y);
    void renderPowerSource(unsigned x, unsigned y);
    void flush();

private:
    void renderQuad(float x, float y, float w, float h, unsigned c);

    sf::RenderTarget * m_target;
    std::vector<sf::Vertex> m_vertices;

};

#endif	/* RENDERER_HPP */

