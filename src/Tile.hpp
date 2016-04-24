/* 
 * File:   Tile.hpp
 * Author: frex
 *
 * Created on April 24, 2016, 6:17 PM
 */

#ifndef TILE_HPP
#define	TILE_HPP

const unsigned kTileSize = 50u;
const unsigned kWireSize = 10u;

enum ETILE_FLAGS
{
    ETF_CONNECT_NORTH = 1 << 0,
    ETF_CONNECT_SOUTH = 1 << 1,
    ETF_CONNECT_EAST = 1 << 2,
    ETF_CONNECT_WEST = 1 << 3,

    ETF_ENERGIZED = 1 << 4,
    ETF_ENERGY_SOURCE = 1 << 5,
};

const unsigned kBackgroundColor = 0x5f5f5fff;
const unsigned kBackgroundColorEnergized = 0x9f9f9fff;
const unsigned kWireColor = 0x7f0000ff;
const unsigned kWireColorEnergized = 0x007f00ff;
const unsigned kCursorColor = 0x7f7f7f7f;

#endif	/* TILE_HPP */

