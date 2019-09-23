#include "level.hpp"
#include <map>
#include <string>

std::map<std::string, int> m = {
    {"day", 0},
    {"night", 1},
    {"pool", 2},
    {"fog", 3},
    {"roof", 4},
    {"moon", 5},
    {"garden", 6},
    {"aquarium", 7},
    {"mushroom", 8},
    {"wisdom-tree", 9},
    {"d", 0},
    {"n", 1},
    {"p", 2},
    {"f", 3},
    {"r", 4},
    {"m", 5},
};

void setSun(int sun) {
    level.sun = sun;
}

void setFlags(int flags) {
    level.flags = flags;
}

void setMap(int id) {
    if (id >= 0 && id < 10) {
        level.map = id;
    }else {
        std::cout << "invalid map id\n";
    }
}

void setMap(const std::string & name) {
    auto p = m.find(name);
    if (p != m.end()) {
        level.map = p->second;
    }else {
        std::cout << "map not found\n";
    }
}

LevelInfo level;

void readLevel(FILE * fp) {
    fseek(fp, -0xB0, SEEK_END);
    fread(&level.flags, sizeof(int), 1, fp);
    
    fseek(fp, 0x53fc, SEEK_SET);
    fread(&level.map, sizeof(int), 1, fp);
    
    fseek(fp, 0x5410, SEEK_SET);
    fread(&level.sun, sizeof(int), 1, fp);
}

void writeLevel(FILE * fp) {
    fseek(fp, -0xB0, SEEK_END);
    fwrite(&level.flags, sizeof(int), 1, fp);
    
    fseek(fp, 0x53fc, SEEK_SET);
    fwrite(&level.map, sizeof(int), 1, fp);
    
    fseek(fp, 0x5410, SEEK_SET);
    fwrite(&level.sun, sizeof(int), 1, fp);
}
