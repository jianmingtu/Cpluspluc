// LongestWord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Challenge: https://www.coderbyte.com/editor/Longest%20Word:Cpp
//        Have the function LongestWord(sen) take the sen parameter being passed and return the largest word in the string. If there are two or more words that are the same length, return the first word from the string with that length. Ignore punctuation and assume sen will not be empty.
//Sample Test Cases
//        Input:"fun&!! time"
//
//Output:time
//
//
//        Input:"I love dogs"
//
//Output:love


#include "pch.h"
#include <iostream>
#include <string>
#include <deque>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <deque>

using namespace std;

string LongestWord(string sen) {

	// code goes here
	istringstream  sens(sen);
	string s;
	string largestString;
	int maxLength = 0;
	while (getline(sens, s, ' '))
	{
		auto i = std::remove_if(s.begin(), s.end(), [](unsigned char c) { return std::ispunct(c); });
		s.erase(i, s.end());
		if (s.length() > maxLength) {
			maxLength = s.length();
			largestString = s;
		}
	}

	return largestString;

}

int main() {
	string s;
	getline(cin, s);
	cout << LongestWord(s);
	return 0;

}