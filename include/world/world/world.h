#include "world/chunk/chunk.h"
#include "SDL.h"
#include "unordered_map"

class World {
public:
    Chunk chunk;  
    
    uint8_t getBlock(int x, int y, int z);  
    void setBlock(int x, int y, int z, uint8_t type);
};
