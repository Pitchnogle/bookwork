// Chapter 7 -- Pointing
// Demonstrates using pointers

#include <iostream>
using namespace std;

int main()
{
	int score = 1000;
	int *p_score = &score;

	cout << "Assigning &score to p_score\n";
	cout << "&score is: " << &score << endl;
	cout << "p_score is: " << p_score << endl;
	cout << "score is: " << score << endl;
	cout << "*p_score is: " << *p_score << "\n\n";

	cout << "Adding 500 to score\n";
	score += 500;

	cout << "score is: " << score << endl;
	cout << "*p_score is: " << *p_score << "\n\n";

	cout << "Adding 500 to *p_score\n";
	*p_score += 500;

	cout << "score is: " << score << endl;
	cout << "*p_score is: " << *p_score << "\n\n";

	cout << "Assigning &new_score to p_score\n";
	int new_score = 5000;
	p_score = &new_score;
	cout << "&new_score is: " << &new_score << endl;
	cout << "p_score is: " << p_score << endl;
	cout << "new_score is: " << new_score << endl;
	cout << "*p_score is: " << *p_score << "\n\n";

	cout << "Assigning &str to p_str\n";
	string str = "score";
	string* p_str = &str;
	cout << "str is: " << str << endl;
	cout << "*p_str is: " << *p_str << endl;
	cout << "(*p_str).size() is: " << (*p_str).size() << endl;
	cout << "p_str->size() is: " << p_str->size() << endl;

	return 0;
}