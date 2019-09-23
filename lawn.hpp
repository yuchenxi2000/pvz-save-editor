#ifndef lawn_hpp
#define lawn_hpp

#include <iostream>
struct PlantInfo {
    int junk1[2];
    int xoffset; // 40 120 200 280 360 440 520 600 680 (pool)
    int yoffset; // 80 165 250 335 420 505 (pool)
    int eighty;
    int eighty2;
    int one;
    int ypos;
    int junk2;
    int ID;
    int xpos;
    int junk3[3];
    int five;
    int zero; // 食人花1，土豆16，仙人掌30，窝瓜7，玉米炮37
    int curhp;
    int maxhp;
    int canshoot;
    int twohundred;
    int zero2;
    int potato_prepare_time; // 土豆，食人花
    int swing_time_shoot_plant;
    int shoot_speed;
    
    int zero_padding[8];
    int neg_padding[2];
    int zero_padding2[49];
    
    int & intOfPos(int i) {
        return *((int *)this + i);
    }
    
    PlantInfo & setHP(int hp) {
        curhp = hp;
        return *this;
    }
    
    PlantInfo & fullHP(int hp) {
        curhp = maxhp;
        return *this;
    }
    
    PlantInfo & ready() { // potato / chomper / cob cannon
        potato_prepare_time = 0;
        return *this;
    }
    
    PlantInfo & setPos(int x, int y);
    
    PlantInfo & setXPos(int x);
    
    PlantInfo & setYPos(int y);
    
    PlantInfo & setPlant(int id) {
        ID = id;
        return *this;
    }
    
    PlantInfo & enableShoot() {
        canshoot = 1;
        return *this;
    }
    
    PlantInfo & disableShoot() {
        canshoot = 0;
        return *this;
    }
    
    PlantInfo & shootSpeed(int speed) {
        if (canshoot == 1)
            shoot_speed = speed;
        return *this;
    }
    
    PlantInfo & uselessChomper() {
        if (ID == 6)
            zero = 0;
        return *this;
    }
    
    PlantInfo & strong() {
        curhp = INT_MAX;
        return *this;
    }
    
    PlantInfo & weak() {
        curhp = 1;
        return *this;
    }
};

struct SizeInfo {
    int junk;
    int nextplant;
    int numplants;
    int numlawn;
    int datasize;
};

extern PlantInfo plants[200];
extern SizeInfo sizeinfo;

void readPlants(FILE * fp);

void writePlants(FILE * fp);

#endif /* lawn_hpp */
