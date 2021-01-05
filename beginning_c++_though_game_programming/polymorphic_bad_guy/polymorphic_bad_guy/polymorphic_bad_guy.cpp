// Chapter 10 -- Polymorphic Bad Guy
// Demonstrates calling member functions dynamically

#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	virtual ~Enemy();
	void virtual attack() const;
protected:
	int* mp_damage;
};

Enemy::Enemy(int damage)
{
	mp_damage = new int(damage);
}

Enemy::~Enemy()
{
	cout << "In Enemy destructor. Deleting mp_damage.\n";
	delete mp_damage;
	mp_damage = 0;
}

void Enemy::attack() const
{
	cout << "An enemy attacks and inflicts << " << * mp_damage << " damage points.\n";
}

class Boss : public Enemy
{
public:
	Boss(int multiplier = 3);
	virtual ~Boss();
	void virtual attack() const;
protected:
	int* mp_multiplier;
};

Boss::Boss(int multiplier)
{
	mp_multiplier = new int(multiplier);
}

Boss::~Boss()
{
	cout << "In Boss destructor. Deleting mp_multiplier.\n";
	delete mp_multiplier;
	mp_multiplier = 0;
}

void Boss::attack() const
{
	cout << "A boss attacks and inflicts " << (*mp_multiplier * (*mp_damage)) << " damage points.\n";
}

int main()
{
	cout << "Calling attack() on Boss object through pointer to Enemy:\n";
	Enemy* p_bad_guy = new Boss();
	p_bad_guy->attack();

	cout << "\n\nDeleting pointer to Enemy:\n";
	delete p_bad_guy;
	p_bad_guy = 0;

	return 0;
}
