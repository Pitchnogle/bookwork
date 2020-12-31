// Chapter 5 -- Yes or No
// Demonstrates return values and parameters

#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
char ask_yes_or_no();
char ask_yes_or_no(string question);

int main()
{
	char answer = ask_yes_or_no();
	cout << "Thanks for answering: " << answer << "\n\n";

	answer = ask_yes_or_no("Do you wish to save your game?");
	cout << "Thanks for answering: " << answer << "\n";

	return 0;
}

char ask_yes_or_no()
{
	char response;
	do
	{
		cout << "Please enter 'y' or 'n': ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

char ask_yes_or_no(string question)
{
	char response;
	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}
