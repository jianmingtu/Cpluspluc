// binarygap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// https://app.codility.com/demo/results/trainingP3WSG7-2HS/
// A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.
//
// For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps : one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.The number 32 has binary representation 100000 and has no binary gaps.
//
// Write a function :
//
// int solution(int N);
//
// that, given a positive integer N, returns the length of its longest binary gap.The function should return 0 if N doesn't contain a binary gap.
//
// For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.
//
// Write an efficient algorithm for the following assumptions :
//
// N is an integer within the range[1..2, 147, 483, 647].

#include "pch.h"
#include <iostream>
#include <bitset>

using namespace std;

int solution(int N);

int main()
{
	cout << "the largest gap is " << solution(1041) << endl;
}

int solution(int N)
{

	size_t pos = 0;

	std::string str = std::bitset<32>(N).to_string();

	int ggap = 0;

	for (int pos = 0; pos < str.length();)
	{
		std::size_t found = str.find("10", pos);

		if (found != std::string::npos)
		{
			pos = found;
			std::size_t found = str.find("01", pos);

			if (found != std::string::npos)
			{
				int gap = (found - pos);
				pos = found + 1;
				if(gap > ggap)
					ggap = gap;
				continue;
			}
		}

		++pos;
	}

	return ggap;
}

