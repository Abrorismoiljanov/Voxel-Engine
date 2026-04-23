#include "include/world/chunk/chunk.h"
#include <cmath>

void Chunk::generate(){
for (int x = 0; x < SIZE; x++) {
    for (int z = 0; z < SIZE; z++) {

        int height = 18
            + (x % 10)
            - (z % 7);

        for (int y = 0; y < SIZE; y++) {

            if (y < height)
                blocks[x][y][z] = 1;
            else
                blocks[x][y][z] = 0;
        }
    }
}
}

uint8_t Chunk::getBlock(int x, int y, int z) const {

    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || z < 0 || z >= SIZE) {
        return 0; 
    }
    return blocks[x][y][z];
}
