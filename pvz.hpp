#ifndef pvz_hpp
#define pvz_hpp

#include <iostream>
#include "plant.hpp"
#include "level.hpp"
#include "lawn.hpp"
#include "card.hpp"

class PVZ {
    FILE * fp; // save file.
public:
    PVZ(const char * path);
    ~PVZ();
};

#endif /* pvz_hpp */
