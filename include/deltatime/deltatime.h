#include "SDL.h"

class Deltatime{
    Uint64 lastTime;
    float deltatime;

public:
    Deltatime();
    void Update();
    float GetDelta() const;
    float GetFPS() const;
    void Cap(float max);
};
