#include "card.hpp"
Card card[10];
int offsetX;

int cardX[4][10] = { // 1-7, 8, 9, 10
    {
        85, 144, 203, 262, 321, 380, 439, 498, 557, 616
    },
    {
        81, 135, 189, 243, 297, 351, 405, 459, 513, 567
    },
    {
        80, 132, 184, 236, 288, 340, 392, 444, 496, 548
    },
    {
        79, 130, 181, 232, 283, 334, 385, 436, 487, 538
    },
};

int offset[5] = { // 1-6, 7, 8, 9, 10
    446, 506, 522, 558, 599
};

void readCard(FILE * fp) {
    if (fseek(fp, -1120, SEEK_END) != 0) {
        std::cerr << "error: fseek" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (fread(&offsetX, sizeof(int), 1, fp) != 1) {
        std::cerr << "error: fwrite" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (fseek(fp, -1108, SEEK_END) != 0) {
        std::cerr << "error: fseek" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (fread(card, sizeof(Card), 10, fp) != 10) {
        std::cerr << "error: fread" << std::endl;
        exit(EXIT_FAILURE);
    }
    
}
void setCard(int cardpos, int ID) {
    card[cardpos].ID = ID;
    card[cardpos].imitatorID = -1;
}
void setImitatorCard(int cardpos, int imitatorID) {
    card[cardpos].ID = 48;
    card[cardpos].imitatorID = imitatorID;
}
void setCardNum(int n) {
    if (n <= 0 || n > 10) return;
    card[0].dummy0[2] = n;
    if (n <= 7) {
        for (int i = 0; i < 10; ++i) {
            card[i].cardX = cardX[0][i];
        }
    }else {
        for (int i = 0; i < 10; ++i) {
            card[i].cardX = cardX[n - 7][i];
        }
    }
    if (n <= 6) {
        offsetX = offset[0];
    }else {
        offsetX = offset[n - 6];
    }
    for (int i = n; i < 10; ++i) {
        card[i].ID = -1;
        card[i].imitatorID = -1;
    }
}
void resetCD() {
    for (int i = 0; i < 10; ++i) {
        card[i].CD = card[i].totalCD;
    }
}
void printCard() {
    for (int i = 0; i < 10; ++i) {
        std::cout << i << " ";
        card[i].print();
    }
}
void writeCard(FILE * fp) {
    if (fseek(fp, -1120, SEEK_END) != 0) {
        std::cerr << "error: fseek" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (fwrite(&offsetX, sizeof(int), 1, fp) != 1) {
        std::cerr << "error: fwrite" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (fseek(fp, -1108, SEEK_END) != 0) {
        std::cerr << "error: fseek" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (fwrite(card, sizeof(Card), 10, fp) != 10) {
        std::cerr << "error: fwrite" << std::endl;
        exit(EXIT_FAILURE);
    }
}
