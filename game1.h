#ifndef _GAME1_H
#define _GAME1_H
#include "card.h"
#include "deck.h"
#include "stdlib.h"
#include "time.h"
const int HAND_SIZE = 5, DEALS = 10000, TRIALS = 10;
class Game1 {
private: 
	Deck d;
	Card hand[HAND_SIZE];
public:
	Game1();
	bool hasPair();
	bool hasFlush();
	void drawHand();
	void recycleHand();
	void showHand();
};
#endif