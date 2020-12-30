// Chapter 2 -- Designers Network
// Demonstrates logical operators

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string username;
	string password;
	bool success;

	cout << "\tGame Designers Network\n";

	do
	{
		cout << "\nusername: ";
		cin >> username;

		cout << "password: ";
		cin >> password;

		if (username == "S.Meier" && password == "civilization")
		{
			cout << "\nHey, Sid.";
			success = true;
		}
		else if (username == "S.Miyamoto" && password == "mariobros")
		{
			cout << "What's up, Shigeru?";
			success = true;
		}
		else if (username == "W.Wright" && password == "thesims")
		{
			cout << "How goes it, Will?";
			success = true;
		}
		else if (username == "guest" || password == "guest")
		{
			cout << "Welcome, guest.";
			success = true;
		}
		else
		{
			cout << "\nYour login failed.";
			success = false;
		}
	} while (!success);

	return 0;
}
