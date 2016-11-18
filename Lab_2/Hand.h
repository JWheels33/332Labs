#pragma once

#ifndef Hand_H
#define Hand_H

#include "Card.h"
#include "Deck.h"
using namespace std;

class Hand {

friend ostream& operator<<(ostream &o, const Hand &h);
friend Hand& operator<< (Hand& h, Deck& deck);
friend bool pokerH(Hand& h1, Hand& h2);
private:
	vector<Card> hand;
public:
	Hand();
	Hand(const Hand &h);
	//~Hand();
	Hand& operator=(const Hand &h);
	const int size();
	string TS();
	bool operator==(const Hand &h) const;
	bool operator<(const Hand &h) const;
};

ostream& operator<<(ostream &o, const Hand &h);
Hand& operator<< (Hand& h, Deck& deck);
bool pokerH(Hand& h1, Hand& h2);


#endif