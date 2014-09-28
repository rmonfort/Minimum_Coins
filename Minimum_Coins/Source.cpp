#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

// Calculates the minimum in order to represent the total
// Coin values are 1, 3, and 5
unsigned int minimum_coins(int total)
{
	unsigned int number_of_coins = 0;

	while (total > 0)
	{
		if (total >= 5)
		{
			total -= 5;
			++number_of_coins;
		}
		else if (total >= 3)
		{
			total -= 3;
			++number_of_coins;
		}
		else if (total >= 1)
		{
			total -= 1;
			++number_of_coins;
		}
	}

	return number_of_coins;
}
int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	int total = 0;
	while (ifs >> total)
	{
		// Ignore negative numbers
		if (total < 0)
		{
			continue;
		}
		cout << minimum_coins(total) << endl;
	}

	return 0;
}