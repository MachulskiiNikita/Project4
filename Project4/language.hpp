#pragma once
#include <string>
#include <vector>
class NaturalLanguage
{
public:
	NaturalLanguage(int number, const std::vector <std::string>&  territory) : m_number(number), m_territory(territory){}
	virtual int getSpeakersNumber() = 0; 
	virtual std::vector<std::string> getTerritory() = 0;
protected:
	int m_number;
	std::vector<std::string> m_territory;
};
   
class IndoeuropeanFamilyLanguage : public NaturalLanguage
{

public:
	IndoeuropeanFamilyLanguage(int number, const std::vector <std::string>& territory) : NaturalLanguage(number, territory) {};
	int getSpeakersNumber() override
	{
		return m_number;
	}

	std::vector<std::string> getTerritory() override
	{
		return m_territory;
	}
};

