/* 
 * File:   XorShifter.hpp
 * Author: frex
 *
 * Created on April 24, 2016, 7:57 PM
 */

#ifndef XORSHIFTER_HPP
#define	XORSHIFTER_HPP

class XorShifter
{
public:

    XorShifter(unsigned seed)
    {
        x = seed;
        y = seed + 1;
        z = seed + 2;
        w = seed + 3;
    }

    unsigned get(unsigned mod)
    {
        unsigned t = x;
        t ^= t << 11;
        t ^= t >> 8;
        x = y;
        y = z;
        z = w;
        w ^= w >> 19;
        w ^= t;
        return w % mod;
    }

    unsigned operator()(unsigned mod)
    {
        return get(mod);
    }

private:
    unsigned x, y, z, w;
};

#endif	/* XORSHIFTER_HPP */

