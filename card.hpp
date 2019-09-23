#ifndef card_hpp
#define card_hpp

#include <iostream>
struct Card {
    int dummy0[5];
    int cardX, cardY;
    int dummy1[5];
    int CD, totalCD;
    int cardNum;
    int offsetY;
    int ID;
    int imitatorID;
    int zero;
    int minus_one;
    void print() {
        if (imitatorID == -1) {
            std::cout << "card: " << ID << std::endl;
        }else {
            std::cout << "imitator: " << imitatorID << std::endl;
        }
    }
};
extern Card card[10];

void readCard(FILE * fp);
void setCard(int cardpos, int ID);
void setImitatorCard(int cardpos, int imitatorID);
void setCardNum(int n);
void resetCD();
void printCard();
void writeCard(FILE * fp);

#endif /* card_hpp */
