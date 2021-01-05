// Chapter 10 -- Abstract Creature
// Demonstrates abstract classes

#include <iostream>
using namespace std;

// Abstract class
class Creature
{
public:
	Creature(int health = 100);
	virtual void greet() const = 0; // pure virtual member function
	virtual void display_health() const;
protected:
	int m_health;
};

Creature::Creature(int health) :
	m_health(health)
{}

void Creature::display_health() const
{
	cout << "Health: " << m_health << endl;
}

class Orc : public Creature
{
public:
	Orc(int health = 120);
	virtual void greet() const;
};

Orc::Orc(int health) :
	Creature(health)
{}

void Orc::greet() const
{
	cout << "The orc grunts hello.\n";
}

int main()
{
	Creature* p_creature = new Orc();
	p_creature->greet();
	p_creature->display_health();

	return 0;
}
