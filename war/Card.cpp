#include <iostream>
#include "Card.h"

Card::Card(char suit, char rank)
		: m_suit {suit} 
		, m_rank {rank}
{
	switch (m_rank)
	{
	case('A'):
		m_val = 1;
		break;
	case('J'):
		m_val = 11;
		break;
	case('Q'):
		m_val = 12;
		break;
	case('K'):
		m_val = 13;
		break;
	case('T'):
		m_val = 10;
		break;
	default:
		m_val = static_cast<int>(m_rank) - 48;
		break;
	}
}

void Card::display()
{
	if (m_rank == 'T')
		std::cout << "10" << m_suit;
	else
		std::cout << m_rank << m_suit;
}
	
int Card::compare(Card other)
{
	if (m_val == other.m_val)
		return 0;
	return (m_val > other.m_val) ? 1 : -1;
}
