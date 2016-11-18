#pragma once

#ifndef Deck_H
#define Deck_H
#include "Card.h"


using namespace std;
class Hand;
class Deck {

friend ostream& operator<< (ostream& o, const Deck& d);
friend Hand& operator<< ( Hand& h, Deck& deck);

public:
	Deck();
	Deck(string fileName);
	//~Deck();
	int load(string file);
	void shuffler();
	const int size();

private:
	vector <Card> d;
};

ostream& operator<< (ostream& o, const Deck& d);

#endif