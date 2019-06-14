// copyfileutil.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Modify the file copy utility to support copying of binary files.Here are some guidelines :
//Use read & write functions of the stream classes instead of getline, operator << or >>.
//Remember, binary files don't have EOF marker, so you'll have to read the file based on its size.
//Take help of the filesystem library to manage paths. (path class, current_path(), is_directory(), etc)
//Handle stream errors appropriately
//Prevent existing files from being overwritten during copy operations.Show a suitable message if a file will be overwritten.
//Here is the link to the documentation of filesystem library : http://en.cppreference.com/w/cpp/header/experimental/filesystem
//


#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <experimental\filesystem>
#include <functional>

using namespace std;
using namespace std::experimental::filesystem;
const unsigned int BUFFER_SIZE = 512;

void Copy(string ins, string outs)
{
	path in(current_path());
	path out = in;

	in /= ins;
	out /= outs;

	ifstream input(in, std::ios::binary | std::ios::in);
	if (!input) {
		throw std::runtime_error("Could not open the source file");
	}

	//ofstream output(out, std::ios::binary | std::ios::out);
	ofstream output(out, std::ios::out | std::ios::binary);
	if (!output) {
		throw std::runtime_error("Could not open the destination file");
	}

	int fileSize = file_size(in);
	char buffer[BUFFER_SIZE]{};

	function<void(int)> copy = [&](int fileSize)
	{
		//Source file is small, so read completely and write into target
		if (!input.read(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during read operation");
		}
		if (!output.write(buffer, fileSize)) {
			throw std::runtime_error("Error occurred during write operation");
		}
	};

	if (fileSize < BUFFER_SIZE)
	{
		copy(fileSize);
	}
	else
	{
		while (fileSize >= BUFFER_SIZE)
		{
			copy(BUFFER_SIZE);

			fileSize -= BUFFER_SIZE;
		}

		if (fileSize)
		{
			copy(fileSize);
		}
	}
	
	std::cout << " Done!" << std::endl;
	input.close();
	output.close();

}

int main()
{
	string input, output;
	cout << "input-file output-file"<< endl;
	cin >> input >> output;
	Copy(input , output);
}
