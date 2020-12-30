// Chapter 2 -- Guess My Number
// The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	// Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
	
	// Generate a random number between 1 and 100
	int secret_number = rand() % 100 + 1;

	int tries = 0;
	int guess;

	cout << "\tWelcome tp Guess My Number\n\n";

	do
	{
		cout << "Enter a guess: ";
		cin >> guess;
		++tries;

		if (guess > secret_number)
			cout << "Too high!\n\n";
		else if (guess < secret_number)
			cout << "Too low!\n\n";
		else
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
	} while (guess != secret_number);

	return 0;
}
