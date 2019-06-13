// https://www.codeassess.com/adminctrl/testdetails.aspx?tid=p7afkuF8BcppdgWli7PmlZuAU5siZD7frNsbhmvoaY0mMJX7JG+IrChdmICeu4fHRt1I8Z3LHPW4y5rMWy30CREaF789bkMePLtqLIiVTjs=

// Write a program that takes L and R as input and displays the number of prime numbers that lie between L and R(L and R inclusive) and can be represented as sum of two consecutive prime numbers + 1.
//
// Example:
//
// Case 1 :
//
// 	For the input provided as follows :
//
// 1 20
//
// Output of the program will be :
//
// 2
//
// Explanation
//
// 13 is a prime number which can be expressed like 5 + 7 + 1.
// 19 is a prime number which can be expressed like 7 + 11 + 1.
// So output is 2.
// Note that 5 and 7 are consecutive primes.Similarly 7 and 11 are consecutive primes.
//
// Case 2:
//
// For the input provided as follows :
//
// 1 10
//
// Output of the program will be :
//
// 0
//
// Explanation
//
// No prime numbers lie between 1 and 10 that can be represented as sum of two consecutive prime numbers + 1, hence 0 is displayed.

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPrime(int v)
{
	for (int i = 2; i < v; ++i)
	{
		if (v % i == 0)
		{
			return false;
		}
	}

	return true;
}

bool isSumOfPrime(int v, vector<int>& vs)
{
	for (auto i = vs.begin(); i != vs.end(); i++)
	{
		int x = *i;
		if ((i + 1) != vs.end())
		{
			int y = *(i + 1);
			if (v == (x + y + 1))
				return true;
		}
	}

	return false;

}

int countPrimes(int L, int R) {
	vector<int> vs;

	int count = 0;
	for (int v = L; v <= R; ++v)
	{
		if (isPrime(v))
			vs.push_back(v);
	}

	for (auto v : vs)
	{
		if (isSumOfPrime(v, vs))
			count++;
	}

	return count;
}


int main() {

	int L, R;
	cin >> L >> R;

	cout << countPrimes(L, R) << endl;

	return 0;
}
