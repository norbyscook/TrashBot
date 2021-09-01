#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

uint32_t number_input();
uint32_t clamped_multiply(uint32_t multiplicand, uint32_t multiplier, uint32_t limit);
uint32_t get_trash_amount();
bool choice_input();
char letter_input();
uint32_t clamped_multiply(uint32_t, uint32_t, uint32_t);

int main()
{
	cout << "Hello! I am trash collector bot!" << endl
		<< "Lets build a better future together!" << endl
		<< "<insert track collector bot ascii art>" << endl
		<< "I will record the number of trash you cleaned up today" << endl
		<< "and you get to earn points!" << endl;

	string file_name = "scores.txt";
	while (true)
	{
		uint32_t trash_amount = { get_trash_amount() };
		uint32_t new_score = { clamped_multiply(trash_amount, 3, 500) };

		fstream file(file_name);

		uint32_t old_score = 0;

		file << new_score << endl;
		cout << "score of " << new_score << " is added!" << endl
			<< "your total score is now: ";
		file.close();
	}
}

// multiply that clamps
uint32_t clamped_multiply(uint32_t multiplicand, uint32_t multiplier, uint32_t limit)
{
	while (true)
	{
		uint32_t result_32 = { multiplicand * multiplier };
		if (result_32 < limit)
		{
			return result_32;
		}
		else
		{
			return limit;
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