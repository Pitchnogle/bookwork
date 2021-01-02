// Chapter 8 -- Static Critter
// Demonstrates static member variables and functions

#include <iostream>
using namespace std;

class Critter
{
public:
	static int s_total;

	Critter(int hunger = 0);
	static int get_total();
private:
	int m_hunger;
};

int Critter::s_total = 0; // init the static member

Critter::Critter(int hunger) : m_hunger(hunger)
{
	cout << "A critter has been born!" << endl;
	s_total++;
}

int Critter::get_total()
{
	return s_total;
}

int main()
{
	cout << "The total number of critters is: " << Critter::s_total << endl;
	
	Critter bob, fred, wilma;

	cout << "\nThe total number of critters is: " << Critter::get_total() << endl;
	
	return 0;
}
