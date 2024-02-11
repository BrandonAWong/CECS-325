// Brandon Wong
// CECS 325-02
// Prog 1 - War
// Due 02/15/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#ifndef CARD_H
#define CARD_H

class Card
{
public:
	Card(char suit, char rank);

	void display();

	int compare(Card other);

private:
	char m_suit {};
	char m_rank {};
	int m_val {};
};

#endif
