// Chapter 9 -- Friend Critter
// Demonstrates friend functions and operator overloading

#include <iostream>
#include <string>
using namespace std;

class Critter
{
	// Make the following global functions friends of the Critter class
	friend void peek(const Critter& critter);
	friend ostream& operator<<(ostream& os, const Critter& critter);
public:
	Critter(const string& name = "");
private:
	string m_name;
};

Critter::Critter(const string& name) : m_name(name)
{}

void peek(const Critter& critter);
ostream& operator<<(ostream& os, const Critter& critter);

int main()
{
	Critter critter("Poochie");

	cout << "Calling peek() to access the critter's private data member, m_name:\n";
	peek(critter);

	cout << "\nSending critter object to cout with the << operator:\n";
	cout << critter << endl;

	return 0;
}

void peek(const Critter& critter)
{
	cout << critter.m_name << endl;
}

ostream& operator<<(ostream& os, const Critter& critter)
{
	os << "Critter object - ";
	os << "m_name: " << critter.m_name;

	return os;
}
