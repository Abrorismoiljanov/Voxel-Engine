#pragma once
#include "SDL.h"
#include "cmath"

class Chunk {
public:
    static const int SIZE = 32;
    uint8_t blocks[SIZE][SIZE][SIZE];
 
    uint8_t getBlock(int x, int y, int z) const;
    void generate();  
};
