// Card.cpp : Defines the entry point for the console application.
//
#pragma once 
#include "stdafx.h"
#include "Card.h"

using namespace std;


int FileReader(vector<Card> &v, char* fileName)
{
	ifstream ifs;
	ifs.open(fileName);
	if (!ifs.good()) {
		cout << "The file cannot be found, please check that it is there and try again." << endl;
		return 1; // make sure the file can be found
	}

	while (!ifs.eof() && ifs.is_open())
	{
		Card c;
		string word;
		getline(ifs, word);

		vector<string> line = split(word);
		vector<Card> holder = generate(line);
		if (holder.size() == 5)
		{
			//sort(holder.begin(), holder.end());
			//printHand(holder);
			for (int i = 0; i < holder.size(); i++)
			{
				Card c = holder[i];
				v.push_back(c);
			}
		}
	}
	ifs.close();
	return 0;
}

string Printer(Card c)
{
		suit pcs = c.s;
		ranks pcr = c.r;
		string out = "";

		switch (pcr) {
		case two:
			out += "2"; break;
		case three:
			out += "3"; break;
		case four:
			out += "4"; break;
		case five:
			out += "5"; break;
		case six:
			out += "6"; break;
		case seven:
			out += "7"; break;
		case eight:
			out += "8"; break;
		case nine:
			out += "9"; break;
		case ten:
			out += "10"; break;
		case jack:
			out += "J"; break;
		case queen:
			out += "Q"; break;
		case king:
			out += "K"; break;
		case ace:
			out += "A"; break;
		default: break;
			//do nothing 
		}

		switch (pcs) {
		case clubs:
			out += "C"; break;
		case diamonds:
			out += "D"; break;
		case hearts:
			out += "H"; break;
		case spades:
			out += "S"; break;
		}
		return out;
}


bool Card::operator< (const Card & c) const {
	if (this->r == c.r) {
		if (this->s < c.s) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
			if (this->r < c.r) {
				return true;
			}
			else {
				return false;
			}
	}
}

vector<string> split(string s)
{
	vector<string> result;
	istringstream iss(s);
	string word;

	while (iss >> word)
	{
		result.push_back(word);
	}
	return result;
}

vector<Card> generate(vector<string> v)
{
	vector<Card> hand;
	for (int i = 0; i < v.size(); i++)
	{
		// cout << "Enters generate loop"; cout <<  i << endl;
		Card c;
		string word = v[i];
		if (word == "//")
		{
			break;
		}
		else if (word.length() == 2 || word.length() == 3)
		{
			char en = word.at(word.length() - 1);
			switch (en) {
			case 'c':
				c.s = clubs; break;
			case 'C':
				c.s = clubs; break;
			case 'd':
				c.s = diamonds;	break;
			case 'D':
				c.s = diamonds;	break;
			case 'h':
				c.s = hearts;	break;
			case 'H':
				c.s = hearts;	break;
			case 's':
				c.s = spades;	break;
			case 'S':
				c.s = spades;	break;
			default: continue;
				break;
				// do nothing
			}

			const char  ch = word[0];
			switch (ch) {
			case '2':
				c.r = two; break;
			case '3':
				c.r = three; break;
			case '4':
				c.r = four; break;
			case '5':
				c.r = five; break;
			case '6':
				c.r = six; break;
			case '7':
				c.r = seven; break;
			case '8':
				c.r = eight; break;
			case '9':
				c.r = nine; break;
			case '1':
				if (word.at(1) == '0')
				{
					c.r = ten; break;
				}
				break;

			case 'j':
				c.r = jack; break;
			case 'q':
				c.r = queen; break;
			case 'k':
				c.r = king; break;
			case 'a':
				c.r = ace; break;
			case 'J':
				c.r = jack; break;
			case 'Q':
				c.r = queen; break;
			case 'K':
				c.r = king; break;
			case 'A':
				c.r = ace; break;
			default:  continue;
				break;
			}
		}
		else
		{
			continue;
		}
		hand.push_back(c);
	}
	return hand;
}

int printHand(const vector<Card> h)
{
	int hRank = 0;
	bool sameSuit = true;
	bool trip = false;
	bool four = false;
	bool pair = false;
	int pair1 = 0;
	bool pair2 = false;
	bool straight = false;
	// check to see if all cards in the hand have the same suit
	for (int i = 1; i < h.size(); i++)
	{
		Card card = h[i];
		if (card.s != h[i - 1].s)
		{
			sameSuit = false;
		}
	}

	// check to see whether we have pairs or trips in the hand
	vector<int> rs = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < h.size(); i++)
	{
		++rs[h[i].r];
	}
	for (int i = 0; i < rs.size(); i++)
	{
		if (rs[i] == 3)
			trip = true;
		else if (rs[i] == 4)
		{
			four = true;
		}
		else if (rs[i] == 2)
		{
			pair = true;
			for (int n = i + 1; n < rs.size(); n++)
			{
				if (rs[n] == 2)
				{
					pair2 = true;
				}
			}
		}

	}
	// check for the straight

	if (h[1].r - 1 == h[0].r && h[2].r - 2 == h[0].r &&
		h[3].r - 3 == h[0].r && h[4].r - 4 == h[0].r)
	{
		straight = true;
	}

	if (trip && pair)
		hRank = 6; // full house
	else if (trip)
		hRank = 3; // Trips
	else if (pair && pair2)
		hRank = 2; //2 pair
	else if (pair)
		hRank = 1; // 1 pair
	else if (straight && sameSuit)
		hRank =8; // straight flush
	else if (straight)
		hRank = 4; // straight
	else if (four)
		hRank = 7; // Fours
	else if (sameSuit)
		hRank = 5; // Flush
	else
		hRank = 0; 
	
	return hRank;
}

