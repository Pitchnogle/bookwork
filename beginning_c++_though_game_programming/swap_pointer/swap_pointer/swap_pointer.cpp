// Chapter 7 -- Swap Pointer
// Demonstrates passing constant pointers to alter argument variables

#include <iostream>
using namespace std;

void bad_swap(int x, int y);
void good_swap(int* const x, int* const y);

int main()
{
	int my_score = 150;
	int ur_score = 1000;

	cout << "Orginal values\n";
	cout << "my_score: " << my_score << endl;
	cout << "ur_score: " << ur_score << endl;

	cout << "Calling bad_swap()\n";
	bad_swap(my_score, ur_score);
	cout << "my_score: " << my_score << endl;
	cout << "ur_score: " << ur_score << endl;

	cout << "Calling good_swap()\n";
	good_swap(&my_score, &ur_score);
	cout << "my_score: " << my_score << endl;
	cout << "ur_score: " << ur_score << endl;

	return 0;
}

void bad_swap(int x, int y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void good_swap(int* const px, int* const py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}