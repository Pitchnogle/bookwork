// Chapter 3 -- Tic-Tac-Toe Board
// Demonstrates multidimensional arrays

#include <iostream>
using namespace std;

int main()
{
	const int ROWS = 3;
	const int COLS = 3;
	char board[ROWS][COLS] = { {'O', 'X', 'O'},
		                       {' ', 'X', 'X'},
		                       {'X', 'O', 'O'} };

	cout << "Here's the tic-tac-toe board:\n";
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
			cout << board[r][c];
		cout << endl;
	}

	cout << "\n'X' moves to the empty location.\n\n";
	board[1][0] = 'X';

	cout << "Now the tic-tac-toe board is:\n";
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLS; ++c)
			cout << board[r][c];
		cout << endl;
	}

	cout << "\n'X' wins!";

	return 0;
}
