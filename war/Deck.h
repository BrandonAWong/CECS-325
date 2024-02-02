#pragma once

#include "Card.h"
#include <vector>

class Deck
{
public:
	Deck();
	
	Card deal();

	void display();

	void shuffle();

private:
	std::vector<Card> m_cards[52];
};

