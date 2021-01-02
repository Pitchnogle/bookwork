// Chapter 8 -- Critter Caretaker
// Simulates caring for a virtual pet

#include <iostream>
using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void talk();
	void eat(int food = 4);
	void play(int fun = 4);
private:
	int m_hunger;
	int m_boredom;

	int get_mood() const;
	void pass_time(int time = 1);
};

Critter::Critter(int hunger, int boredom) : m_hunger(hunger), m_boredom(boredom) {}

void Critter::talk()
{
	cout << "I'm a critter and I feel ";
	
	int mood = get_mood();
	if (mood > 15)
		cout << "mad.\n";
	else if (mood > 10)
		cout << "frustrated.\n";
	else if (mood > 5)
		cout << "OK.\n";
	else
		cout << "happy.\n";

	pass_time();
}

void Critter::eat(int food)
{
	cout << "Brruppp.\n";

	m_hunger -= food;
	if (m_hunger < 0) m_hunger = 0;

	pass_time();
}

void Critter::play(int fun)
{
	cout << "Wheee!\n";

	m_boredom -= fun;
	if (m_boredom < 0) m_boredom = 0;

	pass_time();
}

inline int Critter::get_mood() const
{
	return (m_hunger + m_boredom);
}

void Critter::pass_time(int time)
{
	m_hunger += time;
	m_boredom += time;
}

int main()
{
	Critter c;

	c.talk();

	int choice;
	do
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with your critter\n";

		cout << "Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-bye.\n";
			break;

		case 1:
			c.talk();
			break;

		case 2:
			c.eat();
			break;

		case 3:
			c.play();
			break;

		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}
