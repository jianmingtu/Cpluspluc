// https://www.codeassess.com/adminctrl/testdetails.aspx?tid=p7afkuF8BcppdgWli7PmlZuAU5siZD7frNsbhmvoaY0mMJX7JG+IrChdmICeu4fHRt1I8Z3LHPW4y5rMWy30CREaF789bkMePLtqLIiVTjs=
// Write a program that takes one integer N and an array of N * N elements(the first line contains the integer N and the next N lines contain N integers each, representing the two dimensional array).Your program should give as output the size of the maximum square array(an array of size M * M) that is a magic square and is a sub - array of the inputted array.A magic square is a square of numbers such that when you pick any set of N cells from that square, each cell from the set doesn't share a row or a column with any other cell from that set, and the sum of those N cells is the same for each such possible set of cells.
//
// Example
//
// Case 1:
//
// For the input provided as follows :
//
// 2
// 23 40
// 9 26
//
// Output of the program will be :
//
// 2
//
// Description :
//
// 	As 23 + 26 is equal to 40 + 9, the inputted array is a magic square, giving us a maximum answer of 2.
//
// 	Case 2 :
//
// 	For the input provided as follows :
//
// 4
// - 41 - 29 2 1
// 28 40 71 2
// 11 23 54 3
// 4 5 6 7 8
//
// Output of the program will be :
//
// 3
//
// Description :
//
// 	As the inputted array is not a magic square, the answer can not be 4. Looking at all the possible square arrays, we can check that the maximum answer is 3 with the following 3 x 3 array :
//
// 	-41 - 29 2
// 	28 40 71
// 	11 23 54

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

int ROWS = 3;
int COLUMNS = 3;
using RowInt = int;
using ColInt = int;

using namespace std;

/// <summary>
/// Create a list of cells for sum up (resursive function)
/// </summary>
///  <param name="rowElems">the list of cells on a row</param>
/// <param name="r">current row</param>
/// <param name="c">current col</param>
/// <param name="elems"> return the list of cells</param>
void getElems(vector<pair<RowInt, ColInt>> rowElems, int r, int c, vector<vector<pair<RowInt, ColInt>>>& elems)
{
	// create  rows from rowElems
	vector<int> rows;
	std::for_each(rowElems.begin(), rowElems.end(), [&rows](pair<int, int>& p) { rows.push_back(p.first); });


	for (int i = 0; i < ROWS; ++i)
	{
		vector<pair<int, int>> newRowElems(rowElems);
		vector<int> newRows = rows;

		if (std::find(rows.begin(), rows.end(), i) == rows.end())
		{

			newRowElems.push_back(make_pair(i, c));

			if (c == COLUMNS - 1)
			{
				elems.push_back(newRowElems);
				return;
			}

			newRows.push_back(i);
			getElems(newRowElems, i, c + 1, elems);
		}
	}
}

bool isMagicSquare(vector<vector<int>>& dynamicArray)
{
	vector<pair<int, int>> rowElems;
	vector<vector<pair<int, int>>> elems;
	bool getSum = false;
	int preSum = 0;

	getElems(rowElems, 0, 0, elems);

	for (auto vs : elems)
	{
		int sum = 0;
		for (auto v : vs)
		{
			sum += dynamicArray[v.first][v.second];
		}

		if (getSum && sum != preSum)
		{
			return false;
		}

		getSum = true;
		preSum = sum;
	}

	return true;
}

int main()
{

	vector<vector<int> > dynamicArray(ROWS, vector<int>(COLUMNS));

	dynamicArray[0] = { -41, -29, 2 };
	dynamicArray[1] = { 28, 40, 71 };
	dynamicArray[2] = { 11, 23, 54 };

	bool b = isMagicSquare(dynamicArray);

	cout << (b ? "True" : "False") << endl;

}

