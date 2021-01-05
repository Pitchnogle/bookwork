﻿// Chapter 10 -- Simple Boss
// Demonstrates inheritance

#include <iostream>
using namespace std;

class Enemy
{
public:
	int m_damage;
	Enemy();
	void attack() const;
};

Enemy::Enemy() : 
	m_damage(10)
{}

void Enemy::attack() const
{
	cout << "Attack inflicts " << m_damage << " damage points!\n";
}

class Boss : public Enemy
{
public:
	int m_damage_multiplier;
	Boss();
	void special_attack() const;
};

Boss::Boss() :
	m_damage_multiplier(3)
{}

void Boss::special_attack() const
{
	cout << "Special attack inflicts " << m_damage_multiplier * m_damage << " damage points!\n";
}

int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy;
	enemy.attack();

	cout << "\nCreating a boss.\n";
	Boss boss;
	boss.attack();
	boss.special_attack();

	return 0;
}
