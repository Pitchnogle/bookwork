// Chapter 5 -- Give Me A Number
// Demonstrates default function arguments

#include <iostream>
#include <string>
using namespace std;

int ask_number(int high, int low = 1);

int main()
{
	int number = ask_number(5);
	cout << "Thanks for entering: " << number << "\n\n";

	number = ask_number(10, 5);
	cout << "Thanks for entering: " << number << "\n\n";

	return 0;
}

int ask_number(int high, int low)
{
	int n;
	do
	{
		cout << "Please enter a number" << " (" << low << " - " << high << "): ";
		cin >> n;
	} while (n > high || n < low);

	return n;
}
