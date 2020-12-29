// Chapter 1 -- Game Stats 3.0
// Demonstrates constants

#include <iostream>
using namespace std;

int main()
{
	const int ALIEN_POINTS = 150;
	int aliens_killed = 10;
	int score = aliens_killed * ALIEN_POINTS;
	cout << "score: " << score << endl;

	enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
	difficulty my_difficulty = EASY;

	enum ship_cost {FIGHTER_COST = 25, BOMBER_COST, CRUISER_COST = 50};
	ship_cost my_ship_cost = BOMBER_COST;
	cout << "\nTo upgrade my ship to a cruiser will cost "
	     << (CRUISER_COST - my_ship_cost) << " resource points.";

	return 0;
}
