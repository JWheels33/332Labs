#pragma once
#pragma once

#ifndef Card_H
#define Card_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

enum suit { clubs, diamonds, hearts, spades };
enum ranks { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace };

struct Card {
	suit s;
	ranks r;
	bool operator<(const Card & otherCard) const;
};

vector<string> split(string s);
vector<Card> generate(vector<string> v);
int FileReader(vector<Card> & v, char* fileName);
string Printer(Card c);
int printHand(const vector<Card> h);
int UsageMessage();

#endif 
