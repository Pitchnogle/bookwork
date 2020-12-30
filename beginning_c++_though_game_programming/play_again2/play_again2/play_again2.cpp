// Chapter 2 -- Play Again 2.0
// Demonstrates the do loop

#include <iostream>
using namespace std;

int main()
{
	char again;
	do
	{
		cout << "\n**Played an exciting game**";
		cout << "\nDo you want to play again? (y/n): ";
		cin >> again;
	} while (again == 'y');
	cout << "\nOK. bye.";

	return 0;
}
