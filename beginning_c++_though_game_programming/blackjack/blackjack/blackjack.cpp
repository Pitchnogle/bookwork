// Chapter 10 -- Blackjack
// The classic game of blackjack

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Card
{
public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

	// Overload << operator (so we can send Card objects to standard output)
	friend ostream& operator<<(ostream& os, const Card& card);

	Card(rank r = ACE, suit s = SPADES, bool ifu = true);

	// Returns the value of a card 1-11
	int get_value() const;

	// Flips a card -- if face up, becomes face down, and vice versa
	void flip();
private:
	rank m_rank;
	suit m_suit;
	bool m_is_face_up;
};

Card::Card(rank r, suit s, bool ifu) :
	m_rank(r), m_suit(s), m_is_face_up(ifu)
{}

int Card::get_value() const
{
	// If a card is face down, its value is 0
	int value = 0;
	if (m_is_face_up)
	{
		value = m_rank;
		if (value > 10)
			value = 10;
	}
	return value;
}

void Card::flip()
{
	m_is_face_up = !m_is_face_up;
}

class Hand
{
public:
	Hand();
	virtual ~Hand();

	// Adds a card to the hand
	void add(Card* card);

	// Clears hand of all cards
	void clear();

	// Gets the value of hand total (treats aces as 1 or 11)
	int get_total() const;
protected:
	vector<Card*> m_cards;
};

Hand::Hand()
{
	m_cards.reserve(7);
}

Hand::~Hand()
{
	clear();
}

void Hand::add(Card* card)
{
	m_cards.push_back(card);
}

void Hand::clear()
{
	// Iterate through the vector freeing all memory on heap
	for (vector<Card*>::iterator iter = m_cards.begin(); iter != m_cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	m_cards.clear();
}

int Hand::get_total() const
{
	// If no cards in hand, return 0
	if (m_cards.empty())
		return 0;

	// If first card has a value of 0, is face down thus return 0
	if (m_cards[0]->get_value() == 0)
		return 0;

	// Add up card values (treat ace as 1)
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
		total += (*iter)->get_value();

	// Determine if hand contains an ace
	bool has_ace = false;
	for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
	{
		if ((*iter)->get_value() == Card::ACE)
			has_ace = true;
	}

	// If hand has an ace and total is low enough, treat ace as 11
	if (has_ace && total <= 11)
		total += 10; // the 1 has already been added

	return total;
}

class GenericPlayer : public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& player);
public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();

	// Indicates whether or not the generic player wants to keep hitting
	virtual bool is_hitting() const = 0;

	// Returns whether generic player has busted
	bool is_busted() const;

	// Announces that the generic player busts
	void bust() const;
protected:
	string m_name;
};

GenericPlayer::GenericPlayer(const string& name) :
	m_name(name)
{}

GenericPlayer::~GenericPlayer()
{}

bool GenericPlayer::is_busted() const
{
	return (get_total() > 21);
}

void GenericPlayer::bust() const
{
	cout << m_name << " busts.\n";
}

class Player : public GenericPlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();

	// Returns whether or not the player wants another hit
	virtual bool is_hitting() const;

	// Announces that the player wins
	void win() const;

	// Announces that the player loses
	void lose() const;

	// Announces that the player pushes
	void push() const;
};

Player::Player(const string& name) :
	GenericPlayer(name)
{}

Player::~Player()
{}

bool Player::is_hitting() const
{
	cout << m_name << ", do you want a hit? (y/n): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::win() const
{
	cout << m_name << " wins.\n";
}

void Player::lose() const
{
	cout << m_name << " loses.\n";
}

void Player::push() const
{
	cout << m_name << " pushes.\n";
}

class House : public GenericPlayer
{
public:
	House(const string& name = "House");
	virtual ~House();

	// Indicates whether house is hitting (hits always on 16 or less)
	virtual bool is_hitting() const;

	// Flips over first card
	void flip_first_card();
};

House::House(const string& name) :
	GenericPlayer(name)
{}

House::~House()
{}

bool House::is_hitting() const
{
	return (get_total() <= 16);
}

void House::flip_first_card()
{
	if (!m_cards.empty())
		m_cards[0]->flip();
	else
		cout << "No card to flip!\n";
}

class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();

	// Creates a standard deck of 52 cards
	void populate();

	// Shuffles the cards
	void shuffle();

	// Deal one card to a hand
	void deal(Hand& hand);

	// Give additional cards to a generic player
	void additional_cards(GenericPlayer& player);
};

Deck::Deck()
{
	m_cards.reserve(52);
	populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
	clear();

	// Create standard deck
	for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
		for (int r = Card::ACE; r <= Card::KING; ++r)
			add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
}

void Deck::shuffle()
{
	random_shuffle(m_cards.begin(), m_cards.end());
}

void Deck::deal(Hand& hand)
{
	if (!m_cards.empty())
	{
		hand.add(m_cards.back());
		m_cards.pop_back();
	}
	else
	{
		cout << "Out of cards. Unable to deal.";
	}
}

void Deck::additional_cards(GenericPlayer& player)
{
	cout << endl;

	// Continue to deal a card as long as player isn't busted and wants another hit
	while (!player.is_busted() && player.is_hitting())
	{
		deal(player);
		cout << player << endl;

		if (player.is_busted())
			player.bust();
	}
}

class Game
{
public:
	Game(const vector<string>& names);
	~Game();

	// Plays a game of blackjack
	void play();
private:
	Deck m_deck;
	House m_house;
	vector<Player> m_players;
};

Game::Game(const vector<string>& names)
{
	// Creates a vector of players from a vector of names
	for (vector<string>::const_iterator iter = names.begin(); iter != names.end(); ++iter)
		m_players.push_back(Player(*iter));

	// Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
	m_deck.populate();
	m_deck.shuffle();
}

Game::~Game()
{}

void Game::play()
{
	// Deal initial 2 cards to everyone
	vector<Player>::iterator p_player;
	for (int i = 0; i < 2; ++i)
	{
		for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
			m_deck.deal(*p_player);
		m_deck.deal(m_house);
	}

	// Hide the house's first card
	m_house.flip_first_card();

	// Display everyone's hand
	for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
		cout << *p_player << endl;

	cout << m_house << endl;

	// Deal additional cards to the players
	for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
		m_deck.additional_cards(*p_player);

	// Reveal house's first card
	m_house.flip_first_card();
	cout << endl << m_house;

	// Deal additional cards to the house
	m_deck.additional_cards(m_house);

	if (m_house.is_busted())
	{
		// Every still playing wins
		for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
			if (!p_player->is_busted())
				p_player->win();
	}
	else
	{
		// Compare each player still playing to the house
		for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
		{
			if (!p_player->is_busted())
			{
				if (p_player->get_total() > m_house.get_total())
					p_player->win();
				else if (p_player->get_total() < m_house.get_total())
					p_player->lose();
				else
					p_player->push();
			}
		}
	}

	// Remove everyone's cards
	for (p_player = m_players.begin(); p_player != m_players.end(); ++p_player)
		p_player->clear();
	m_house.clear();
}

ostream& operator<<(ostream& os, const Card& card);
ostream& operator<<(ostream& os, const GenericPlayer& player);

int main()
{
	cout << "\t\tWelcome to Blackjack\n\n";
	int num_players = 0;
	while (num_players < 1 || num_players > 7)
	{
		cout << "How many players? (1-7): ";
		cin >> num_players;
	}

	vector<string> names;
	string name;
	for (int i = 0; i < num_players; ++i)
	{
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;

	// The game loop
	Game game(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		game.play();
		cout << "\nDo you want to play again? (y/n): ";
		cin >> again;
	}

	return 0;
}

ostream& operator<<(ostream& os, const Card& card)
{
	const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const string SUITS[] = { "c", "d", "h", "s" };

	if (card.m_is_face_up)
		os << RANKS[card.m_rank] << SUITS[card.m_suit];
	else
		os << "XX";

	return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& player)
{
	os << player.m_name << ":\t";

	vector<Card*>::const_iterator p_card;
	if (!player.m_cards.empty())
	{
		for (p_card = player.m_cards.begin(); p_card != player.m_cards.end(); ++p_card)
			os << *(*p_card) << "\t";

		if (player.get_total() != 0)
			cout << "(" << player.get_total() << ")";
	}
	else
		os << "<empty>";

	return os;
}
