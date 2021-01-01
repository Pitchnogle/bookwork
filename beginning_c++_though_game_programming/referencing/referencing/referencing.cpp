// Chapter 6 -- Referencing
// Demonstrates using references

#include <iostream>
using namespace std;

int main()
{
	int my_score = 1000;
	int& mikes_score = my_score;

	cout << "my_score is: " << my_score << endl;
	cout << "mikes_score is: " << mikes_score << endl;

	cout << "Adding 500 to my_score\n";
	my_score += 500;

	cout << "my_score is: " << my_score << endl;
	cout << "mikes_score is: " << mikes_score << endl;

	cout << "Adding 500 to mikes_score\n";
	mikes_score += 500;

	cout << "my_score is: " << my_score << endl;
	cout << "mikes_score is: " << mikes_score << endl;

	return 0;
}
