#include "lawn.hpp"
int xoffset_pool[] = {40, 120, 200, 280, 360, 440, 520, 600, 680};
int yoffset_pool[] = {80, 165, 250, 335, 420, 505};

PlantInfo & PlantInfo::setPos(int x, int y) {
    if (x >= 0 && y >= 0 && x < 9 && y < 6)  {
        xpos = x; ypos = y;
        xoffset = xoffset_pool[x];
        yoffset = yoffset_pool[y];
    }
    return *this;
}

PlantInfo & PlantInfo::setXPos(int x) {
    if (x >= 0 && x < 9)  {
        xpos = x;
        xoffset = xoffset_pool[x];
    }
    return *this;
}

PlantInfo & PlantInfo::setYPos(int y) {
    if (y >= 0 && y < 6)  {
        ypos = y;
        yoffset = yoffset_pool[y];
    }
    return *this;
}

PlantInfo plants[200];

SizeInfo sizeinfo;

int start;
int * idata;
int idata_len;

void readPlants(FILE * fp) {
    fseek(fp, 0, SEEK_END);
    size_t len = ftell(fp);
    idata_len = len / 4;
    idata = new int[len / 4];
    fseek(fp, 0, SEEK_SET);
    fread(idata, 4, len / 4, fp);
    start = -1;
    for (int i = int(len / 4 - 4); i >= 0; --i) {
        if (idata[i] == -1 && idata[i + 1] == -1 && idata[i + 2] == -1 && idata[i + 3] == -1) {
            start = i + 13;
            break;
        }
    }
    if (start != -1) {
        memcpy(&sizeinfo, idata + start, sizeof(SizeInfo));
        memcpy(plants, idata + start + 5, sizeof(PlantInfo) * sizeinfo.numplants);
    }
}

void writePlants(FILE * fp) {
    fseek(fp, (start + 5) * sizeof(int), SEEK_SET);
    fwrite(plants, sizeof(PlantInfo), sizeinfo.numplants, fp);
}
