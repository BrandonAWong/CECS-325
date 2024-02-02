#pragma once

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
