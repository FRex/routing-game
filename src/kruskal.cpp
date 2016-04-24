#include <algorithm>

#include "kruskal.hpp"
#include "XorShifter.hpp"

static unsigned root(const std::vector<unsigned>& forest, unsigned a)
{
    while(forest[a] != a)
        a = forest[a];

    return a;
}

static void merge(std::vector<unsigned>& forest, unsigned a, unsigned b)
{
    forest[root(forest, b)] = a;
}

std::vector<sf::Vector2u> kruskal(unsigned w, unsigned h, XorShifter& xshifter)
{
    const int off[4][2] = {
        {0, -1},
        {0, 1},

        {1, 0},
        {-1, 0},
    };

    std::vector<sf::Vector2u> edges;
    for(unsigned x = 0u; x < w; ++x)
    {
        for(unsigned y = 0u; y < h; ++y)
        {
            for(int i = 0; i < 4; ++i)
            {
                const unsigned nx = x + off[i][0];
                const unsigned ny = y + off[i][1];
                if(nx < w && ny < h)
                {
                    edges.push_back(sf::Vector2u(x + y * w, nx + ny * w));
                }
            }//for i
        }//for y
    }//for x

    std::random_shuffle(edges.begin(), edges.end(), xshifter);

    std::vector<unsigned> forest;
    for(unsigned i = 0u; i < w * h; ++i)
        forest.push_back(i);

    std::vector<sf::Vector2u> ret;
    {
        unsigned needed = w * h - 1u;
        unsigned total = 0u;
        unsigned i = 0u;
        while(total < needed)
        {
            const unsigned a = edges[i].x;
            const unsigned b = edges[i].y;
            if(root(forest, a) != root(forest, b))
            {
                merge(forest, a, b);
                ++total;
                ret.push_back(edges[i]);
            }
            ++i;
        }
    }
    return ret;
}
