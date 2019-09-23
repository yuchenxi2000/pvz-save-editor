#include "plant.hpp"
std::string plantname[48];
std::map<std::string, int> plantid;

std::string plantName(int ID) {
    if (ID >= 0 && ID < 48) {
        return plantname[ID];
    }else {
        return "unknown";
    }
}

std::string plantName(const PlantInfo & plant) {
    int ID = plant.ID;
    if (ID >= 0 && ID < 48) {
        return plantname[ID];
    }else {
        return "unknown";
    }
}

int plantID(const std::string & name) {
    auto p = plantid.find(name);
    if (p != plantid.end()) return p->second;
    else return -1;
}

void loadIDTable() {
    std::ifstream fi("IDTable.txt");
    for (int i = 0; i < 48; ++i) {
        fi >> plantname[i];
        plantid.insert(make_pair(plantname[i], i));
    }
}

void listPlant() {
    for (int i = 0; i < 48; ++i) {
        std::cout << i << '\t' << plantname[i] << '\n';
    }
}
