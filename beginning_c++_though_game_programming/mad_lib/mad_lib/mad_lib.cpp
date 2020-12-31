// Chapter 5 -- Mad Lib
// Creates a story based on user input

#include <iostream>
#include <string>
using namespace std;

string ask_text(string prompt);
int ask_number(string prompt);
void tell_story(string name, string noun, int number, string body_part, string verb);

int main()
{
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = ask_text("Please enter a name: ");
	string noun = ask_text("Please enter a plural noun: ");
	int number = ask_number("Please enter a number: ");
	string body_part = ask_text("Please enter a body part: ");
	string verb = ask_text("Please enter a verb: ");

	tell_story(name, noun, number, body_part, verb);

	return 0;
}

string ask_text(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int ask_number(string prompt)
{
	int n;
	cout << prompt;
	cin >> n;
	return n;
}

void tell_story(string name, string noun, int number, string body_part, string verb)
{
	cout << "\nHere's your story:\n";
	cout << "The famous explorer " << name;
	cout << " had nearly given up a life-long quest to find\n";
	cout << "the lost city of " << noun;
	cout << " when one day, the " << noun;
	cout << " found the explorer.\n";
	cout << "Surrounded by " << number << " " << noun;
	cout << ", a tear came to " << name << "'s " << body_part << ".\n";
	cout << "After all this time, the quest was finally over. ";
	cout << "And then, the " << noun << "\n" << "promptly devoured ";
	cout << name << ". The moral of the story? Be careful what you ";
	cout << verb << " for.\n";
}
