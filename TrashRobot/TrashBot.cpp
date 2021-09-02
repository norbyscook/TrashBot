/*
* source code insperations: 
	* https://stackoverflow.com/questions/427477/fastest-way-to-clamp-a-real-fixed-floating-point-value
	* https://www.tutorialspoint.com/cplusplus/cpp_conditional_operator.htm
*/

#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

uint32_t number_input();
uint32_t trash_amount_input();
bool choice_input();
char letter_input();
void override_score_file(const string, uint32_t);
uint32_t file_score_input(const string);
void press_enter_to_end();
uint32_t limited_add(uint32_t, uint32_t);
uint32_t limited_multiply(uint32_t, uint32_t);
uint32_t clamp(uint32_t num, uint32_t upper);

int main()
{
	cout << "Hello! I am trash collector bot!\n"
		<< "Lets build a better future together by eliminating them trashes!\n"
		<< "<insert track collector bot ascii art>\n"
		<< "I will record the number of trash you cleaned up today\n"
		<< "and you get to earn points based on the number of trash you cleaned!\n";

	constexpr char file_path[] = "scores.txt";

	uint32_t trash_amount = { trash_amount_input() };
	uint32_t new_score = { clamp(limited_multiply(trash_amount, 3), 500) };
	uint32_t file_score = { file_score_input(file_path) };
		
	// update score
	cout << "score of " << new_score << " is added!\n";
	new_score = limited_add(new_score, file_score);
	cout << "your total score is now: " << new_score << "\n";

	if (new_score == std::numeric_limits<uint32_t>::max())
	{
		cout << "WOW, you have reached the max amount of points!!\n";
	}

	// update file data
	override_score_file(file_path, new_score);

	// end program 
	cout << "that is all for now! Come again! Thank you! :D" << "\n";
	press_enter_to_end();
}

// create file if empty and override data in file
void override_score_file(const string file_path, uint32_t new_data)
{
	ofstream out_file(file_path);
	if (!out_file) { cout << "I can't create the file!" << "\n"; }
	else { out_file << new_data; }
	out_file.close();
}

uint32_t file_score_input(const string file_path)
{
	uint32_t file_score = 0;
	// read data from file
	ifstream in_file(file_path);
	if (!in_file)
	{
		cout << "I will create a file called: " << file_path << "\n"
			<< "this is where we will keep our scores!\n";
		// initiate file to 0
		override_score_file(file_path, 0);
	}
	else { in_file >> file_score; }
	in_file.close();
	return file_score;
}

void press_enter_to_end()
{
	cout << "press enter to end\n";
	cin.ignore(1000, '\n');
}

uint32_t limited_add(uint32_t addend_one, uint32_t addend_two)
{
	constexpr uint32_t limit = std::numeric_limits<uint32_t>::max();
	return limit - addend_one > addend_two ? addend_one + addend_two : limit;
}

uint32_t limited_multiply(uint32_t multiplicand, uint32_t multiplier)
{
	uint32_t result_32 = { multiplicand * multiplier };
	uint64_t result_64 = { uint64_t(multiplicand) * multiplier };
	return result_32 == result_64 ? result_32 : std::numeric_limits<uint32_t>::max();
}

uint32_t clamp(uint32_t num, uint32_t upper)
{
	return num > upper ? upper : num;
}

// get trash amount from user
uint32_t trash_amount_input()
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