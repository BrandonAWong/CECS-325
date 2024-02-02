#pragma once

class Card
{
public:
	Card(char suit, char rank);

	void display();

	int compare(Card);

private:
	char m_suit {};
	char m_rank {};
};

