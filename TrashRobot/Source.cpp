#include <iostream>

using std::cin;
using std::cout;

uint32_t number_input();
uint32_t get_trash_amount();
bool get_choice();
char letter_input();
uint32_t uint32_t_multiply(uint32_t, uint32_t);

int main()
{
	cout << "Hello! I am trash collector bot! <insert track collector bot ascii art>\n"
		<< "I will record the number of trash you cleaned up today!\n";

	uint32_t trash_amount = { get_trash_amount() };
	uint32_t score = { 0 };

	return 0;
}



uint32_t uint32_t_multiply(uint32_t multiplicand, uint32_t multiplier)
{

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
		correct = { get_choice() };
	} while (!correct);

	return trash_number;
}

bool get_choice()
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