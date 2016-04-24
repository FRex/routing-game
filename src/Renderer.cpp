#include "Renderer.hpp"
#include <SFML/Graphics.hpp>
#include "Tile.hpp"

void Renderer::init(sf::RenderTarget& target)
{
    m_target = &target;
}

void Renderer::renderTile(unsigned x, unsigned y, unsigned flags)
{
    const float fx = x * kTileSize;
    const float fy = y * kTileSize;
    const float ts = kTileSize;
    const float ws = kWireSize;
    const float off = (ts - ws) / 2.f;
    const unsigned backcol = (flags & ETF_ENERGIZED)?kBackgroundColorEnergized:kBackgroundColor;
    const unsigned wirecol = (flags & ETF_ENERGIZED)?kWireColorEnergized:kWireColor;

    renderQuad(fx, fy, ts, ts, backcol);
    if(flags & ETF_CONNECT_NORTH)
        renderQuad(fx + off, fy, ws, ws + off, wirecol);

    if(flags & ETF_CONNECT_SOUTH)
        renderQuad(fx + off, fy + off, ws, ws + off, wirecol);

    if(flags & ETF_CONNECT_EAST)
        renderQuad(fx + off, fy + off, ws + off, ws, wirecol);

    if(flags & ETF_CONNECT_WEST)
        renderQuad(fx, fy + off, ws + off, ws, wirecol);

}

void Renderer::renderQuad(float x, float y, float w, float h, unsigned c)
{
    sf::Vertex vert[4];
    vert[0].position = sf::Vector2f(x, y);
    vert[1].position = sf::Vector2f(x, y + h);
    vert[2].position = sf::Vector2f(x + w, y + h);
    vert[3].position = sf::Vector2f(x + w, y);
    for(int i = 0; i < 4; ++i)
    {
        vert[i].color = sf::Color(c);
        m_vertices.push_back(vert[i]);
    }
}

void Renderer::flush()
{
    if(m_vertices.empty())
        return;

    m_target->draw(&m_vertices[0], m_vertices.size(), sf::Quads);
    m_vertices.clear();
}

void Renderer::renderCursorShadow(unsigned x, unsigned y)
{
    renderQuad(kTileSize * x, kTileSize * y, kTileSize, kTileSize, kCursorColor);
}
