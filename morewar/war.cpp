// Brandon Wong
// CECS 325-02
// Prog 2 - More War
// Due 02/27/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Card
{
public:
    Card(char suit, char rank)
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
            m_val = 13; break;
        case('T'): 
            m_val = 10;
            break;
        default:
            m_val = static_cast<int>(m_rank) - 48;
            break;
        }
    }

    void display()
    {
        if (m_rank == 'T')
            std::cout << "10" << m_suit;
        else
            std::cout << m_rank << m_suit;
    }

    int compare(Card other)
    {
        if (m_val == other.m_val)
            return 0;
        return (m_val > other.m_val) ? 1 : -1;
    }

private:
    int m_val {};
    char m_suit {}; 
    char m_rank {};
};

class Deck
{
public:
    Deck()
    {
        for (char suit : {'C', 'S', 'D', 'H'})
        {
            for (char rank : {'A', '2', '3','4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'})
                m_cards.push_back(Card(suit, rank));	
        }
    }

    Card deal()
    {
        Card top = m_cards[0]; 
        m_cards.erase(m_cards.begin());
        return top;
    }

    void display()
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

    void shuffle()
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

    bool isEmpty()
    {
        return m_cards.empty();
    }

private:
    std::vector<Card> m_cards {};
};

int main()
{
    std::cout << "Enter the name of the first player: ";
    std::string p1 {};
    std::getline(std::cin >> std::ws, p1); std::cout << "Enter the name of the second player: "; std::string p2 {}; std::getline(std::cin >> std::ws, p2); int rounds {};
    std::cout << "How many gimes will they play? ";
    std::cin >> rounds;

	Deck deck {};
	std::cout << "\n Original Deck\n";
	deck.display();

	deck.shuffle();
	std::cout << "\n Shuffled Deck\n";
	deck.display();
    
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
