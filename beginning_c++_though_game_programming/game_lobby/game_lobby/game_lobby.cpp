// Chapter 9 -- Game Lobby
// Simulates a game lobby where players wait

#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	Player(const string& name = "");
	string get_name() const;
	Player* get_next() const;
	void set_next(Player* next);
private:
	string m_name;
	Player* m_next;
};

Player::Player(const string& name) :
	m_name(name), 
	m_next(0)
{}

string Player::get_name() const
{
	return m_name;
}

Player* Player::get_next() const
{
	return m_next;
}

void Player::set_next(Player* next)
{
	m_next = next;
}

class Lobby
{
	friend ostream& operator<<(ostream& os, const Lobby& lobby);
public:
	Lobby();
	~Lobby();
	void add_player();
	void remove_player();
	void clear();
private:
	Player* m_phead;
};

Lobby::Lobby() : m_phead(0)
{}

Lobby::~Lobby()
{
	clear();
}

void Lobby::add_player()
{
	// Create a new player node
	cout << "Please enter the name of the new player: ";
	string name;
	cin >> name;
	Player* p_newplayer = new Player(name);

	// If the list is empty, make new player the head
	if (m_phead == 0)
		m_phead = p_newplayer;
	else
	{
		// Otherwise add to the end of the list
		Player* p_iter = m_phead;
		while (p_iter->get_next() != 0)
			p_iter = p_iter->get_next();
		p_iter->set_next(p_newplayer);
	}
}

void Lobby::remove_player()
{
	if (m_phead == 0)
		cout << "The game lobby is empty. No one to remove!\n";
	else
	{
		Player* p_tmp = m_phead;
		m_phead = m_phead->get_next();
		delete p_tmp;
	}
}

void Lobby::clear()
{
	while (m_phead != 0)
		remove_player();
}

ostream& operator<<(ostream& os, const Lobby& lobby)
{
	Player* p_iter = lobby.m_phead;
	os << "\nHere's who's in the game lobby:\n";
	if (p_iter == 0)
		cout << "The lobby is empty.\n";
	else
		while (p_iter != 0)
		{
			os << p_iter->get_name() << endl;
			p_iter = p_iter->get_next();
		}

	return os;
}

int main()
{
	Lobby lobby;

	int choice;
	do
	{
		cout << lobby;
		cout << "\nGAME LOBBY\n";
		cout << "0 - Exit the program\n";
		cout << "1 - Add a player to the lobby\n";
		cout << "2 - Remove a player from the lobby\n";
		cout << "3 - Clear the lobby\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-bye\n";
			break;
		case 1:
			lobby.add_player();
			break;
		case 2:
			lobby.remove_player();
			break;
		case 3:
			lobby.clear();
			break;
		default:
			cout << "That isn't a valid choice!\n";
		}
	} while (choice != 0);

	return 0;
}
