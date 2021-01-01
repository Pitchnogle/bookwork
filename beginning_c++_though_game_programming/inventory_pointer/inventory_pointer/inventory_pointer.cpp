// Chapter 7 -- Inventory Pointer
// Demonstrates returning a pointer

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string* ptr_to_element(vector<string>* inventory, int i);

int main()
{
	vector<string> inventory;
	inventory.push_back("sword");
	inventory.push_back("armor");
	inventory.push_back("shield");

	cout << "Sending the object pointed to by returned pointer to cout:\n";
	cout << *(ptr_to_element(&inventory, 0)) << "\n\n";

	cout << "Assigning the returned pointer to another pointer.\n";
	string *p_str = ptr_to_element(&inventory, 1);
	cout << "Sending the object pointed to by new pointer to cout:\n";
	cout << *p_str << "\n\n";

	cout << "Assigning object pointed to by pointer to a string object.\n";
	string str = *(ptr_to_element(&inventory, 2));
	cout << "Sending the new string object to cout:\n";
	cout << str << "\n\n";

	cout << "Altering an object through a returned pointer.\n";
	*p_str = "Healing potion";
	cout << "Sending the altered object to cout:\n";
	cout << inventory[1] << endl;

	return 0;
}

string* ptr_to_element(vector<string>* inventory, int i)
{
	return &((*inventory)[i]);
}