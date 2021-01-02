// Chapter 8 -- Constructor Critter
// Demonstrates constructors

#include <iostream>
using namespace std;

class Critter
{
public:
	int m_hunger;
	Critter(int hunger = 0);
	void greet();
};

//Critter::Critter(int hunger)
//{
//	cout << "A new critter has been born!" << endl;
//	m_hunger = hunger;
//}

// alternatively, a more typical modern constructor would look like:
Critter::Critter(int hunger) : m_hunger(hunger) {}

void Critter::greet()
{
	cout << "Hi. I'm a critter. My hunger level is " << m_hunger << endl;
}

int main()
{
	Critter bob(7), fred;

	bob.greet();
	fred.greet();

	return 0;
}
