// Chapter 8 -- Simple Critter
// Demonstrates creating a new type

#include <iostream>
using namespace std;

class Critter
{
public:
	int m_hunger;
	void greet();
};

void Critter::greet()
{
	cout << "Hi. I'm a critter. My hunger level is " << m_hunger << endl;
}

int main()
{
	Critter bob, fred;

	bob.m_hunger = 8;
	cout << "Bob's hunger level is " << bob.m_hunger << endl;

	fred.m_hunger = 3;
	cout << "Fred's hunger level is " << fred.m_hunger << endl;

	bob.greet();
	fred.greet();

	return 0;
}
