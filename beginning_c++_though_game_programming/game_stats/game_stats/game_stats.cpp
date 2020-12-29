// Chapter 1 -- Game Stats
// Demonstrates declaring and initializing variables

#include <iostream>
using namespace std;

int main()
{
	int score;
	double distance;
	char play_again;
	bool shields_up;
	short lives, aliens_killed;

	score = 0;
	distance = 1200.76;
	play_again = 'y';
	shields_up = true;
	lives = 3;
	aliens_killed = 10;

	double engine_temp = 6572.89;

	cout << "\nscore: " << score << endl;
	cout << "distance: " << distance << endl;
	cout << "play_again: " << play_again << endl;
	cout << "shields_up: " << shields_up << endl; // displays as (0 or 1)
	cout << "lives: " << lives << endl;
	cout << "aliens_killed: " << aliens_killed << endl;
	cout << "engine_temp: " << engine_temp << endl;

	int fuel;
	cout << "\nHow much fuel?" << endl;
	cin >> fuel;
	cout << "fuel: " << fuel << endl;

	typedef unsigned short int ushort;
	ushort bonus = 10;
	cout << "\nbonus: " << bonus << endl;

	return 0;
}
