#ifndef plant_hpp
#define plant_hpp

#include <iostream>
#include <fstream>
#include <map>
#include "lawn.hpp"

void loadIDTable();

std::string plantName(int ID);

std::string plantName(const PlantInfo & plant);

int plantID(const std::string & name);

void listPlant();

#endif /* plant_hpp */
