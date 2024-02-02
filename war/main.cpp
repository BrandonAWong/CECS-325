#include <iostream>
#include <string>
#include "Deck.h"

int main()
{
	std::cout << "Enter the name of the first player: ";
	std::string p1 {};
	std::cin >> p1;
	std::cout << "Enter the name of the second player: ";
	std::string p2 {};
	std::cin >> p2;

	Deck deck {};
	std::cout << "\n Original Deck\n";
	deck.display();

	deck.shuffle();
	std::cout << "\n Shuffled Deck\n";
	deck.display();

	const int rounds = 26;
	int pointsP1 {0};
	int pointsP2 {0};
	int ties {0};
	for (std::size_t i {0}; i < rounds; ++i)
	{
		Card cardP1 {deck.deal()};
		Card cardP2 {deck.deal()};

		std::cout << "Game " << i+1 << '\n' << "--------\n\t" << p1 << "=>";
		cardP1.display();
		std::cout << "\n\t" << p2 << "=>";
		cardP2.display();
		std::cout << '\n';

		switch(cardP1.compare(cardP2))
		{
			case(0):
				std::cout << "Tie game\n";
				++ties;
				break;
			case(-1):
				++pointsP2;
				std::cout << p2 << "=> Winner\n";
				break;
			case(1):
				++pointsP1;
				std::cout << p1 << "=> Winner\n";
				break;
		}
	}

	std::cout << "------Final Stats-------\n\t" << p1 << " vs. " << p2 << 
		"\nWins\t" << pointsP1 << '\t' << pointsP2 << "\nLosses\t" <<
		rounds-pointsP1 << '\t' << rounds-pointsP2 << "\nTies\t" <<
		ties << '\t' << ties <<'\n';
}
