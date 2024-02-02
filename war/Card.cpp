#include "Card.h"
#include <iostream>

Card::Card(char suit, char rank)
		: m_suit {suit} 
		, m_rank {rank}
{
}

void Card::display()
{
	std::cout << m_rank << m_suit;
}
	
int Card::compare(Card)
{
	// not finished
	std::cout <<"HIIH";
}
