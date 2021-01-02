// Chapter 9 -- Heap Data Member
// Demonstrates an object with dynamically allocated data member

#include <iostream>
#include <string>
using namespace std;

class Critter
{
public:
	Critter(const string& name = "", int age = 10);
	~Critter();
	Critter(const Critter& critter);
	Critter& Critter::operator=(const Critter& critter);
	void greet() const;
private:
	string* m_name;
	int m_age;
};

Critter::Critter(const string& name, int age)
{
	cout << "Constructor called\n";
	m_name = new string(name);
	m_age = age;
}

Critter::~Critter()
{
	cout << "Destructor called\n";
	delete m_name;
}

Critter::Critter(const Critter& critter)
{
	cout << "Copy constructor called\n";
	m_name = new string(*(critter.m_name));
	m_age = critter.m_age;
}

Critter& Critter::operator=(const Critter& critter)
{
	cout << "Overloaded assignment operator called\n";
	if (this != &critter)
	{
		delete m_name;
		m_name = new string(*(critter.m_name));
		m_age = critter.m_age;
	}
	return *this;
}

void Critter::greet() const
{
	cout << "I'm " << *m_name << " and I'm " << m_age << " years old. ";
	cout << "&m_name: " << &m_name << endl;
}

void test_destructor();
void test_copy_constructor(Critter copy);
void test_assignment_operator();

int main()
{
	test_destructor();
	cout << endl;

	Critter critter("Poochie", 5);
	critter.greet();
	test_copy_constructor(critter);
	critter.greet();
	cout << endl;

	test_assignment_operator();

	return 0;
}

void test_destructor()
{
	Critter to_die("Rover", 3);
	to_die.greet();
}

void test_copy_constructor(Critter copy)
{
	copy.greet();
}

void test_assignment_operator()
{
	Critter bob("Bob", 4);
	Critter pete("Pete", 9);

	bob = pete;
	bob.greet();
	pete.greet();
	cout << endl;

	Critter wilma("Wilma", 2);
	wilma = wilma;
	wilma.greet();
}
