#pragma once

#include "stdafx.h"
#include "Hand.h"
#include "Card.h"
#include "Deck.h"
#include <string>
#include <algorithm>


Hand::Hand()
	{
		vector<Card> hand;
	}

Hand::Hand(const Hand &h): hand (h.hand)
	{
			
	}

const int Hand::size()
	{
		return hand.size();
	}
	
Hand& Hand::operator=(const Hand & h)
	{
		if ( !(*this == h) )
		{
			hand.clear();
			for (unsigned int i = 0; i < h.hand.size(); i++)
			{
				hand.push_back(h.hand[i]);
			}
		}
		return *this;
	}

bool Hand::operator==(const Hand& h) const
	{
		bool re = true;
		for (unsigned int i = 0; i < hand.size(); i++)
		{
			string a = Printer(hand[i]);
			string b = Printer(h.hand[i]);
			if (a != b)
			{
				re = false;
			}
		}
		return re;
	}

bool Hand::operator<(const Hand & h) const
{
	for (unsigned int i = 0; i < hand.size(); i++)
		{
			if ( Printer(hand[i]) != Printer(h.hand[i]) )
			{
				return  hand[i] < h.hand[i];
			}

		}
}

string Hand::TS()
	{
		string str;
		for (unsigned int i = 0; i < hand.size(); i++)
		{
			str = (str + Printer(hand[i]) + " ");
		}
		return str;
	}


ostream& operator<<(ostream &o, const Hand &h)
{
	for (unsigned int i = 0; i < h.hand.size(); i++)
	{
		o << Printer(h.hand[i]) << " ";
	}
	o << endl;
	return o;
}

Hand& operator<< (Hand& h, Deck& deck)
{
	h.hand.push_back(deck.d.back());
	deck.d.pop_back();

	sort(h.hand.begin(), h.hand.end());
	return h;
}
