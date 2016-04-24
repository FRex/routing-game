#include "Map.hpp"
#include "Renderer.hpp"

void Map::generate(unsigned w, unsigned h)
{
    m_tiles.assign(w * h, ~0u);
    m_width = w;
    m_height = h;
}

void Map::render(Renderer& renderer)
{
    for(unsigned x = 0u; x < m_width; ++x)
    {
        for(unsigned y = 0u; y < m_height; ++y)
        {
            renderer.renderTile(x, y, m_tiles[x + y * m_width]);
        }
    }
}

unsigned Map::getWidth() const
{
    return m_width;
}

unsigned Map::getHeight() const
{
    return m_height;
}
