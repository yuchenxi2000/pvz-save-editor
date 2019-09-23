#include "pvz.hpp"
using namespace std;
/*
 * pvz save editer.
 * Mac OS only. pvz version 1.0.40
 */
int main(int argc, const char * argv[]) {
    // your save file path
    // backup your save before modifying to avoid crash...
    const char * path = "/Users/ycx/Library/Application Support/PopCap/PlantsvsZombies/userdata/game2_31.dat";
    // do not change the following line
    PVZ pvz(path);
    
    // edit by yourself!
    setSun(9990);
    resetCD();
    for (int i = 0; i < sizeinfo.numplants; ++i) {
        if (plants[i].ID == 0) {
            plants[i].strong().setPlant(44).shootSpeed(50);
        }
    }
    
    return 0;
}
