// Chapter 3 -- Counter
// Demonstrates for loops

#include <iostream>
using namespace std;

int main()
{
	cout << "Counting forward:\n";
	for (int i = 0; i < 10; i++)
		cout << i << " ";

	cout << "\n\nCounting backward:\n";
	for (int i = 9; i >= 0; i--)
		cout << i << " ";

	cout << "\n\nCounting by fives:\n";
	for (int i = 0; i <= 50; i += 5)
		cout << i << " ";
	
	cout << "\n\nCounting with null statements:\n";
	int count = 0;
	for (; count < 10;)
	{
		cout << count << " ";
		++count;
	}

	cout << "\n\nCounting with nested for loops:\n";
	const int ROWS = 5;
	const int COLS = 3;
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
			cout << r << "," << c << " ";
		cout << endl;
	}

	return 0;
}
