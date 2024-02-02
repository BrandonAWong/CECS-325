#include "Card.h"
#include <iostream>

Card::Card(char suit, char rank)
		: m_suit {suit} 
		, m_rank {rank}
{
}

void Card::display()
{
	std::cout << m_suit << m_rank;
}
	
int Card::compare(Card)
{
	return 0;
}
