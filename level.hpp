#ifndef level_hpp
#define level_hpp

#include <iostream>
struct LevelInfo {
    int sun;
    int flags;
    int map;
};

extern LevelInfo level;

void setSun(int sun);
void setFlags(int flags);
void setMap(int id);
void setMap(const std::string & name);

void readLevel(FILE * fp);
void writeLevel(FILE * fp);

#endif /* level_hpp */
