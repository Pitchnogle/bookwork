// Chapter 10 -- Overriding Boss
// Demonstrates calling and overriding base member functions

#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	void virtual taunt() const;
	void virtual attack() const;
protected:
	int m_damage;
};

Enemy::Enemy(int damage) :
	m_damage(damage)
{}

void Enemy::taunt() const
{
	cout << "The enemy says he will fight you.\n";
}

void Enemy::attack() const
{
	cout << "Attack! inflicts " << m_damage << " damage points.\n";
}

class Boss : public Enemy
{
public:
	Boss(int damage = 30);
	void virtual taunt() const;
	void virtual attack() const;
};

Boss::Boss(int damage) :
	Enemy(damage)
{}

void Boss::taunt() const
{
	cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::attack() const
{
	Enemy::attack();
	cout << " And laughs heartily at you.\n";
}

int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy;
	enemy.taunt();
	enemy.attack();

	cout << "\nCreating a boss.\n";
	Boss boss;
	boss.taunt();
	boss.attack();

	return 0;
}
