// Chapter 2 -- Finicky Counter
// Demonstrates break and continue statements

#include <iostream>
using namespace std;

int main()
{
	int count = 0;

	while (true)
	{
		count++;

		if (count > 10)
			break;

		if (count == 5)
			continue;

		cout << count << endl;
	}

	return 0;
}
