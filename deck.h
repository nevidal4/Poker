#ifndef _DECK_H
#define _DECK_H
#include"Card.h"
const int DECKSIZE = 52;
class Deck {
private:
	Card inDeck[DECKSIZE];
	int nextCard;
public:
	Deck();
	void shuffle(int);
	Card getCard();
	void addCard(Card);
	int totalCards();
};
#endif