#pragma once

#include "stdafx.h"
#include <random>
#include "Hand.h"
#include <iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

Deck::Deck() {};
Deck::Deck(string fileName)
	{
		vector<Card> d;
		if (load(fileName) != 0)
		{
			string s = "The file cannot be found, please check that it is there and try again.";
			throw s;
			cout << "after";
		}
	}

int Deck::load(string file) // TODO figure out how to create try/catch here
	{
		ifstream ifs;
		ifs.open(file);
		if (!ifs.good()) {
			return 1;
		}

		while (!ifs.eof() && ifs.is_open())
		{
			string word;
			getline(ifs, word);

			vector<string> line = split(word);
			vector<Card> holder = generate(line);
			for (unsigned int i = 0; i < holder.size(); i++)
			{
				Card c = holder[i];
				d.push_back(c);
			}
		}
		ifs.close();
		return 0;
	}

void Deck::shuffler()
	{
		random_device rd;
		mt19937 thing(rd());
		shuffle( d.begin(), d.end(), thing);
	}

const int Deck::size()
	{
		return d.size();
	}


ostream& operator<<(ostream& o, const Deck& deck)
{
	for (unsigned int i = 0; i < deck.d.size(); i++)
	{
		Card c = deck.d[i];
		o << Printer(c) << endl;
	}
	return o;
}