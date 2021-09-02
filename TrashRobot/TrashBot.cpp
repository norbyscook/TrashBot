#include <iostream>
#include <fstream>
#include <algorithm>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::clamp;

uint32_t number_input();
uint32_t clamped_multiply(uint32_t, uint32_t, uint32_t);
uint32_t get_trash_amount();
bool choice_input();
char letter_input();
uint32_t clamped_multiply(uint32_t, uint32_t, uint32_t);
void press_enter_to_end();

int main()
{
	cout << "Hello! I am trash collector bot!\n"
		<< "Lets build a better future together by eliminating them trashes!\n"
		<< "<insert track collector bot ascii art>\n"
		<< "I will record the number of trash you cleaned up today\n"
		<< "and you get to earn points!\n";

	string file_path = "scores.txt";

	uint32_t trash_amount = { get_trash_amount() };
	uint32_t new_score = {  };

	uint32_t file_score = 0;

	// read data from file
	ifstream in_file(file_path);
	if (!in_file)
	{
		cout << "I will create a file called: " << file_path << "\n"
			<< "this is where we will keep our scores!\n";
	}
	else { in_file >> file_score; }
	in_file.close();
		
	// update score
	cout << "score of " << new_score << " is added!\n";
	new_score += file_score;
	cout << "your total score is now: " << new_score << "\n";

	// update file data
	ofstream out_file(file_path);
	if (!out_file) { cout << "I can't create the file!" << "\n"; }
	else { out_file << new_score; }
	out_file.close();

	// end program 
	cout << "that is all for now! Thank you! :D" << "\n";
	press_enter_to_end();
}

void press_enter_to_end()
{
	cout << "press enter to end\n";
	cin.ignore(1000, '\n');
}


// multiply that clamps to score limit
uint32_t clamp(uint32_t num, uint32_t lower, uint32_t upper)
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