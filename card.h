#ifndef _CARD_H
#define _CARD_H
class Card {
public:
	enum Suit { Diamonds, Hearts, Clubs, Spades };
	enum Value { NullCard, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
private:
	static const char *snames[4];
	static const char *vnames[14];
	Suit s;
	Value v;
public:Card();
	   Card(Suit newSuit, Value newValue);
	   Suit getSuit();
	   Value getValue();
	   void printSuit();
	   void printValue();
	   void printCard();
};
Card::Suit nextSuit(Card::Suit);
Card::Value nextValue(Card::Value);
#endif