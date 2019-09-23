#include "pvz.hpp"

PVZ::PVZ(const char * path) { // open file and read level, plant, card info.
    loadIDTable();
    fp = fopen(path, "r+");
    if (fp == 0) {
        std::cout << "file not found\n";
        exit(-1);
    }
    readLevel(fp);
    readCard(fp);
    readPlants(fp);
}
PVZ::~PVZ() { // write back.
    writeLevel(fp);
    writeCard(fp);
    writePlants(fp);
    fclose(fp);
}
