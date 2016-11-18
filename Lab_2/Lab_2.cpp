#pragma once

// Lab_2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <string>
#include <algorithm>
#include <vector>
#include "Hand.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

void UsageMessage(string s, string n);
bool pokerH(Hand& h1, Hand& h2);

Deck newDeck;
int main(int argc, char* argv[])
{
	string a = argv[0], b, c;

	if (argc == 1)
	{
		string s = "Please use up to two arguments, the name of a text file \n";
		s = s + "containing valid card declarations, and an optional '-shuffle' argument";
		UsageMessage(a, s);
		return 1;
	}
	else if (argc > 3)
	{
		string s = "Please use no more than two arguments, the name of a text file \n";
		s = s + "containing valid card declarations, and an optional '-shuffle' argument"+
			"if you want the deck shuffled.";
		UsageMessage(a, s);
		return 2;
	}
	else if (argc == 3)
	{
		b = argv[1], c = argv[2];
		if (!(b == "-shuffle" || c == "-shuffle"))
		{
			string s = "Please make one argument the name of a text file containing valid \n";
			s = s + "card declarations, and the second a '-shuffle' argument \n" +
				"if you want the deck shuffled.";
			UsageMessage(a, s);
			return 3;
		}
	}
	else if (argc == 2)
	{
		b = argv[1];
		if (b == "-shuffle")
		{
			string s = "PLease include the name of a text file containing valid \n";
			s = s +	"valid card declarations. The '-shuffle' argument must be the other.";
			UsageMessage(a, s);
			return 4;
		}
		try
		{
			 newDeck = Deck(b);
		}
		catch (string e)
		{
			cout << e << endl;
			return 6;
		}
	}
	
	if (b == "-shuffle")
	{
		try
		{
			 newDeck = Deck(c);

		}
		catch (string e)
		{
			cout << e << endl;
			return 6;
		}
	}
	else
	{
		try
		{
			 newDeck = Deck(b);
		}
		catch (string e)
		{
			cout << e;
			return 6;
		}
	}

	cout << "Number of cards read in = " << newDeck.size() << endl;
	
	// Check for the shuffle
	if (b == "-shuffle" || c == "-shuffle")
	{
		newDeck.shuffler();
	}
	
	vector<Hand> holder;
	int k = 0;
	while (k < 9) // push back 9 hands
	{
		holder.push_back(Hand());
		k++;
	}
	
	if (newDeck.size() < 45) // check that there are enough cards to fill all the hands;
	{
		cout << "Not enough cards to fill 9 hands: exiting the program" << endl;
		return 8;
	}

	int i = 9;
	while (holder.back().size() < 5 && newDeck.size() != 0 ) // put cards in hands
	{
		int c = i%9;
		holder[c] << newDeck;
		++i;
	}
	
	sort(holder.begin(), holder.end());
	cout << endl;
	cout << "Sorted Lexically " << endl;

	for (unsigned int i = 0; i < holder.size(); ++i)
	{
		cout << holder[i];
	}
	
	cout << endl;
	cout << "Sorted by rank" << endl;
	sort(holder.begin(), holder.end(), pokerH);

	for (unsigned int i = 0; i < holder.size(); ++i)
	{
		cout << holder[i];
	}
	
    return 0;
}

void UsageMessage(string s, string n)
{
	cout << s + "," << endl;
	cout << n << endl;
}

bool pokerH(Hand & h1, Hand & h2)
{
	int a = printHand(h1.hand);
	if (printHand(h1.hand) < printHand(h2.hand))
	{
		return true;
	}
	else if (printHand(h1.hand) == printHand(h2.hand))
	{
		
		vector<int> r1 = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		vector<int> r2 = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < h1.size(); i++) // fill holder array
		{
			++r1[h1.hand[i].r];
			++r2[h2.hand[i].r];
		}
		if (a == 8 || a == 4) // straight flush check or straight
		{
			return h1.hand.back().r < h2.hand.back().r;
		}
		if (a == 7) // four of a kind check
		{
			int c1 = 0, c2 = 0;
			for (int i = 0; i < r1.size(); i++)
			{
				if (r1[i] == 4)
				{
					c1 = i;
				}
				if (r2[i] == 4)
				{
					c2 = i;
				}
			}
			return c1 < c2;
		}
		if (a == 6) // full house check
		{
			int c1 = 0, c2 = 0;
			for (int i = 0; i < r1.size(); i++)
			{
				if (r1[i] == 3)
				{
					c1 = i;
				}
				if (r2[i] == 3)
				{
					c2 = i;
				}
			}
			if (c1 != c2) // just in case the trips are shared
			{
				return c1 < c2;
			}
			else
			{
				int c1 = 0, c2 = 0;
				for (int i = 0; i < r1.size(); i++)
				{
					if (r1[i] == 2)
					{
						c1 = i;
					}
					if (r2[i] == 2)
					{
						c2 = i;
					}
				}
				return c1 < c2;
			}
		}
		if (a == 3) //  trips check
		{
			int c1 = 0, c2 = 0;
			for (int i = 0; i < r1.size(); i++)
			{
				if (r1[i] == 3)
				{
					c1 = i;
				}
				if (r2[i] == 3)
				{
					c2 = i;
				}
			}
			return c1 < c2;
		}
		if (a == 2) // two pair check
		{
			int c11 = -1, c12 = -1, c13 = -1, c21 = -1, c22 = -1, c23 = -1;
			for (int i = 0; i < r1.size(); i++)
			{
				if (r1[i] == 2)
				{
					if (c11 == c12)
						c11 = i;
					else
						c12 = i;
				}
				if (r2[i] == 2)
				{
					if (c21 == c22)
						c21 = i;
					else
						c22 = 1;
				}
				if (r1[i] == 1)
				{
					c13 = i;
				}
				if (r2[i] == 1)
				{
					c23 = i;
				}
			}
			if (c11 != c21)
			{
				return c11 < c21;
			}
			else if (c12 != c22)
			{
				return c12 < c22;
			}
			else
			{
				return c13 < c23;
			}
		}
		if (a == 1) // one pair check
		{
			int c1 = 0, c2 = 0;
			for (int i = 0; i < r1.size(); i++)
			{
				if (r1[i] == 2)
				{
					c1 = i;
				}
				if (r2[i] == 2)
				{
					c2 = i;
				}
			}
			if (c1 != c2)
			{
				return c1 < c2;
			}
			else
			{
				for (int i = r1.size(); i >= 0; i--)
				{
					if (r1[i] != r2[i])
						return r1[i] < r2[i];
				}
			}
		}
		if (a == 0 || a == 5) // unranked check
		{
			for (int i = h1.size() - 1; i >= 0; --i)
			{
				if (h1.hand[i].r != h2.hand[i].r)
					return h1.hand[i].r < h2.hand[i].r;
			}
		}

	}

	return false;
	
}


