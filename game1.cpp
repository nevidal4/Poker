#include<iostream>
#include<iomanip>
#include<fstream>
#include "game1.h"
using namespace std;
ofstream csis;
Game1::Game1() {
		d.shuffle(100);
}
void Game1::drawHand(){
	for (int i = 0; i < HAND_SIZE; ++i)
		hand[i] = d.getCard();
}
void Game1::recycleHand(){
	for (int i = 0; i < HAND_SIZE; ++i)
		d.addCard(hand[i]);
	d.shuffle(100);
}
bool Game1::hasPair(){
	for (int i = 0; i < HAND_SIZE - 1; ++i) {
		for (int j = i + 1; j < HAND_SIZE; ++j) {
			if (hand[i].getValue() == hand[j].getValue())
				return true;
		}
	}
	return false;
}
bool Game1::hasFlush() {
	for (int i = 0; i < HAND_SIZE - 1; ++i) {
		if (hand[i].getSuit() != hand[i + 1].getSuit())
			return false;
	}
	return true;
}
void Game1::showHand() {
	for (int i = 0; i < HAND_SIZE; ++i) {
		hand[i].printCard();
		cout << endl;
	}
}
int main(void) {
	//Andrews Samuel
	//008559913
	srand((unsigned)time(NULL));
	Game1 g;
	int numPair, numFlush, sumPair=0, sumFlush=0, trial;
	float percentPair, percentFlush;

	csis.open("csis1.txt");
	cout << setiosflags(ios::left)
		<< setw(10) << "Trial" << setw(10) << "Hands" << setw(10) << "Pairs" << setw(10)
		<<"Flushes" << setw(10) << "Pair %" << setw(10) << "Flush %" << endl;
	csis << setiosflags(ios::left)
		<< setw(10) << "Trial" << setw(10) << "Hands" << setw(10) << "Pairs" << setw(10)
		<< "Flushes" << setw(10) << "Pair %" << setw(10) << "Flush %" << endl;

	for (trial = 1; trial <= TRIALS; ++trial) {
		numFlush = 0;
		numPair = 0;
		for (int i = 0; i < DEALS; ++i) {
			g.drawHand();
			//g.showHand();
			if (g.hasFlush()) {
				//cout << "flush" << endl;
				++numFlush;
			}
			if (g.hasPair()) {
				//cout << "pair" << endl;
				++numPair;
			}
			g.recycleHand();
		}
		sumPair += numPair;
		sumFlush += numFlush;
		percentPair = numPair * 100.0 / DEALS;
		percentFlush = numFlush * 100.0 / DEALS;
		//printf("%d %10d %10d %10d %10f %10f\n",trial,deals,numPair,numFlush,percentPair,percentFlush);
		cout << setiosflags(ios::showpoint | ios::fixed | ios::left) << setprecision(2)
			<< setw(10) << trial << setw(10) << DEALS << setw(10) << numPair << setw(10) << numFlush
			<< setw(10) << percentPair << setw(10) << percentFlush << endl;
		csis << setiosflags(ios::showpoint | ios::fixed | ios::left) << setprecision(2)
			<< setw(10) << trial << setw(10) << DEALS << setw(10) << numPair << setw(10) << numFlush
			<< setw(10) << percentPair << setw(10) << percentFlush << endl;
	}

	cout << setiosflags(ios::showpoint | ios::right) << setprecision(2)
		<< setw(30) << "Total average pairs" << setw(30) << "Total average flushes\n"
		<< setw(30) << sumPair * 100.0 / (DEALS* TRIALS) << setw(30) << sumFlush * 100.0 / (DEALS*TRIALS) << endl;
	csis << setiosflags(ios::showpoint | ios::right) << setprecision(2)
		<< setw(30) << "Total average pairs" << setw(30) << "Total average flushes\n"
		<< setw(30) << sumPair * 100.0 /(DEALS* TRIALS) << setw(30) << sumFlush * 100.0 / (DEALS*TRIALS) << endl;
	csis.close();
	return 0;
}