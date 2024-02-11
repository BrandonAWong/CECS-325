// Brandon Wong
// CECS 325-02
// Prog 1 - War
// Due 02/15/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Deck.h"

Deck::Deck()
{
	for (char suit : {'C', 'S', 'D', 'H'})
	{
		for (char rank : {'A', '2', '3','4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'})
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
	for (std::size_t i {0}; i < m_cards.size(); ++i)
	{
		m_cards[i].display();
		if (i % 13)
			std::cout << ", ";
		else
			std::cout << '\n';
	}
}

void Deck::shuffle()
{
	std::srand(std::time(0));
	int j {};
	for (std::size_t i {0}; i < m_cards.size(); ++i)
	{
		j = std::rand() % m_cards.size();
		Card temp {m_cards[j]};
		m_cards[j] = m_cards[i];
		m_cards[i] = temp;
	}
}
