#include "language.hpp"
#include <iostream>
#include <vector>

int main()
{
	NaturalLanguage* russ = new IndoeuropeanFamilyLanguage(2e7, { "Russia", "Ukraine" });
	NaturalLanguage* deutsch = new IndoeuropeanFamilyLanguage(2e7, { "Deutschland" });
	std::vector < NaturalLanguage*> l{ russ, deutsch };
	std::cout << russ -> getSpeakersNumber() << ' ' << deutsch -> getSpeakersNumber();
	return 0;
}