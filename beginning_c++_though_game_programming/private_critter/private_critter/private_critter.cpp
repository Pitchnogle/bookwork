// Chapter 8 -- Private Critter
// Demonstrates setting member access levels

#include <iostream>
using namespace std;

class Critter
{
public:
	Critter(int hunger = 0);
	void set_hunger(int hunger);
	int get_hunger() const;
private:
	int m_hunger;
};

Critter::Critter(int hunger) : m_hunger(hunger) {}

void Critter::set_hunger(int hunger)
{
	if (hunger < 0)
		cout << "You can't set a critter's hunger to a negative number!\n\n";
	else
		m_hunger = hunger;
}

int Critter::get_hunger() const
{
	return m_hunger;
}

int main()
{
	Critter bob(5);

//	cout << "Bob's hunger level is " << bob.m_hunger << endl; // illegal now!
	cout << "Calling get_hunger(): " << bob.get_hunger() << "\n\n";

	cout << "Calling set_hunger() with -1" << endl;
	bob.set_hunger(-1);

	cout << "Calling set_hunger() with 9" << endl;
	bob.set_hunger(9);
	cout << "Calling get_hunger(): " << bob.get_hunger() << "\n\n";

	return 0;
}
