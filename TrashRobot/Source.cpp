#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

uint32_t number_input();
uint32_t get_trash_amount();
bool choice_input();
char letter_input();
uint32_t uint32_t_multiply(uint32_t, uint32_t);

int main()
{
	cout << "Hello! I am trash collector bot! <insert track collector bot ascii art>\n"
		<< "I will record the number of trash you cleaned up today!" << endl;
	string file_name = "scores.txt";
	while (true)
	{
		uint32_t trash_amount = { get_trash_amount() };
		uint32_t score = { uint32_t_multiply(trash_amount, 3) };

		fstream file(file_name);
		file << score << endl;
		cout << "score of " << score << "added!" << endl
			<< "your total score is now: ";
		file.close();
	}
}

// multiply that checks for overflow
uint32_t uint32_t_multiply(uint32_t multiplicand, uint32_t multiplier)
{
	while (true)
	{
		uint32_t result_32 = { multiplicand * multiplier };
		uint64_t result_64 = { uint64_t(multiplicand) * multiplier };
		if (result_32 == result_64)
		{
			return result_32;
		}
		else
		{
			return std::numeric_limits<uint32_t>::max();
		}
	}
}

uint32_t get_trash_amount()
{
	bool correct = { false };
	uint32_t trash_number = { 0 };
	do
	{
		cout << "enter your number: ";
		trash_number = { number_input() };

		cout << "did you input: " << trash_number << "?\n"
			<< "press y for yes, n for no.\n";
		correct = { choice_input() };
	} while (!correct);

	return trash_number;
}

bool choice_input()
{
	char choice = { letter_input() };
	while (true)
	{
		switch (choice)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "please enter y for yes, n for no.\n";
			break;
		}
	}
}

char letter_input()
{
	char character = { 0 };
	while (!(cin >> character))
	{
		cout << "invalid letter input\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return character;
}

uint32_t number_input()
{
	uint32_t number = { 0 };
	while (!(cin >> number))
	{
		cout << "invalid number input\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return number;
}