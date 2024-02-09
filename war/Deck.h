// Brandon Wong
// CECS 325-02
// Prog 1 - War
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck
{
public:
	Deck();
	
	Card deal();

	void display();

	void shuffle();

private:
	std::vector<Card> m_cards;
};

#endif
