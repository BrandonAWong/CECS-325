#include "Deck.h"
#include <iostream>

Deck::Deck()
	{
	}

Card Deck::deal()
{
	Card top = m_cards[m_cards.begin()]; 
	m_cards.erase(m_cards.begin());
	return top;
}

void Deck::display()
{
	for (Card card : m_cards)
		card.display();
}

void Deck::shuffle()
{
	std::cout << "hi";
}

