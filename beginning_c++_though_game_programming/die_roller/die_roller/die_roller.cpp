// Chapter 2 -- Die Roller
// Demonstrates generating random numbers

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	// Seed random number generator
	srand(static_cast<unsigned int>(time(0)));
	
	// Generate random number
	int random_number = rand();

	// Get a number between 1 and 6
	int die = (random_number % 6) + 1;
	cout << "You rolled a " << die << endl;

	return 0;
}
