#include "Deck.h"
#include <iostream>

Deck::Deck()
{
	std::vector<char> suits {'C', 'S', 'D', 'H'};
	std::vector<char> ranks {'A', '2', '3','4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
	for (char& suit : suits)
	{
		for (char& rank : ranks)
			m_cards.push_back(Card(suit, rank));	
	}
}

Card Deck::deal()
{
	Card top = m_cards[0]; 
	m_cards.erase(m_cards.begin());
	return top;
}

void Deck::display()
{
	for (Card& card : m_cards)
	{
		card.display();
		if (card.m_rank == 'K')
			std::cout << '\n';
		else
			std::cout << ", ";
	}
		
}

void Deck::shuffle()
{
	std::cout << "hi";
}

