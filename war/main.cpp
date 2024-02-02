#include "Deck.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Enter the name of the first player: ";
	std::string p1 {};
	std::cin >> p1;
	std::cout << "Enter the name of the second player: ";
	std::string p2 {};
	std::cin >> p2;

	Deck deck {};
	deck.display();
}

