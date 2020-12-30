// Chapter 2 -- Play Again
// Demonstrates while loop

#include <iostream>
using namespace std;

int main()
{
	char again = 'y';
	while (again == 'y')
	{
		cout << "\n**Played an exciting game**";
		cout << "\nDo you want to play again? (y/n): ";
		cin >> again;
	}
	cout << "\nOK. bye.";

	return 0;
}
