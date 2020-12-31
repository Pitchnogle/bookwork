// Chapter 4 -- Hero's Inventory 3.0
// Demonstrates iterators

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	vector<string>::iterator my_iterator;
	vector<string>::const_iterator iter;

	cout << "\nYour Items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nYou trade your sword for a battle axe.\n";
	my_iterator = inventory.begin();
	*my_iterator = "battle axe";

	cout << "\nYour Items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nThe item name '" << *my_iterator << "' has ";
	cout << (*my_iterator).size() << " letters in it.\n";

	cout << "\nThe item name '" << *my_iterator << "' has ";
	cout << my_iterator->size() << " letters in it.\n";

	cout << "\nYou recover a crossbow from a slain enemy.\n";
	inventory.insert(inventory.begin(), "crossbow");

	cout << "\nYour Items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	cout << "\nYour armor is destroyed in a fierce battle.\n";
	inventory.erase(inventory.begin() + 2);

	cout << "\nYour Items:\n";
	for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		cout << *iter << endl;

	return 0;
}
