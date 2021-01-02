// Chapter 9 -- Critter Farm
// Demonstrates object containment

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Critter
{
public:
	Critter(const string& name = "");
	string get_name() const;
private:
	string m_name;
};

Critter::Critter(const string& name) : m_name(name)
{}

inline string Critter::get_name() const
{
	return m_name;
}

class Farm
{
public:
	Farm(int spaces = 1);
	void add(const Critter& critter);
	void roll_call() const;
private:
	vector<Critter> m_critters;
};

Farm::Farm(int spaces)
{
	m_critters.reserve(spaces);
}

void Farm::add(const Critter& critter)
{
	m_critters.push_back(critter);
}

void Farm::roll_call() const
{
	for (vector<Critter>::const_iterator iter = m_critters.begin(); iter != m_critters.end(); ++iter)
		cout << iter->get_name() << " here.\n";
}

int main()
{
	Critter critter("Poochie");
	cout << "My critter's name is " << critter.get_name() << endl;

	cout << "\nCreating a critter farm\n";
	Farm farm(3);

	cout << "\nAdding three critters to the farm.\n";
	farm.add(Critter("Moe"));
	farm.add(Critter("Larry"));
	farm.add(Critter("Curly"));

	cout << "\nCalling roll...\n";
	farm.roll_call();

	return 0;
}
