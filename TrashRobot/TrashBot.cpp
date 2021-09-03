/*
* source code insperations: 
	* https://stackoverflow.com/questions/427477/fastest-way-to-clamp-a-real-fixed-floating-point-value
	* https://www.tutorialspoint.com/cplusplus/cpp_conditional_operator.htm
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::stoul;
using std::getline;

// main score functions
void update_file_score(uint32_t, const char[]);
// input functions
bool choice_input();
char letter_input();
string string_input();
bool valid_score_input(string);
bool is_intended_score(uint32_t);
// data type check functions
bool is_int_str(string input);
// file functions
void override_file(const string, uint32_t);
uint32_t get_file_score(const string);
string get_ascii_art(const string);
// math functions
uint32_t limited_add(uint32_t, uint32_t);
uint32_t limited_multiply(uint32_t, uint32_t);
uint32_t clamp(uint32_t num, uint32_t upper);
// program end functions
void press_enter_to_end();

int main()
{
	constexpr char trash_art_file_path[] = "TrashBotArt.txt";
	cout << "Hello! I am trash collector bot!\n"
		<< "Lets build a better future together by eliminating them trashes!\n"
		<< get_ascii_art(trash_art_file_path)
		<< "I will record the number of trash you cleaned up today\n"
		<< "and you get to earn points based on the number of trash you cleaned!\n\n";

	constexpr char score_file_path[] = "scores.txt";
	while (true)
	{
		cout << "enter a number to record trash, enter 'score' to display current score\n"
			<< "enter 'e' to end program\n";

		string input = string_input();
		if (valid_score_input(input))
		{
			update_file_score(stoul(input), score_file_path);
		}
		else if (input == "score")
		{
			uint32_t score = get_file_score(score_file_path);
			cout << "your current score is: " << score << "\n";
		}
		else if (input == "e")
		{
			// end program 
			cout << "that is all for now! Come again! Thank you! :D" << "\n";
			break;
		}
		else
		{
			cout << "please retry input\n";
		}
	}
	press_enter_to_end();
	return 0;
}

// main score functions ------------------------

void update_file_score(uint32_t input, const char file_path[])
{
	uint32_t trash_amount = { input };
	uint32_t new_score = { clamp(limited_multiply(trash_amount, 3), 500) };
	uint32_t file_score = { get_file_score(file_path) };

	// update score
	cout << "score of " << new_score << " is added!\n";
	new_score = limited_add(new_score, file_score);
	cout << "your total score is now: " << new_score << "\n";

	if (new_score == std::numeric_limits<uint32_t>::max())
	{
		cout << "WOW, you have reached the max amount of scores!!\n";
	}

	// update file data
	override_file(file_path, new_score);
}

// input functions ------------------------

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

string string_input()
{
	string input = { "" };
	while (!(cin >> input))
	{
		cout << "invalid string input\n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	cin.ignore(1000, '\n');
	return input;
}

bool valid_score_input(string input)
{
	if (is_int_str(input))
	{
		return is_intended_score(stoul(input));
	}
	else
	{
		return false;
	}
}

bool is_intended_score(uint32_t input)
{
	cout << "did you input: " << input << "?\n"
		<< "press y for yes, n for no.\n";
	return  choice_input();
}

// data type check functions ------------------------

bool is_int_str(string input)
{
	stringstream chk_stream(input);
	uint32_t num = 0;
	return bool(chk_stream >> num);
}


// file functions ------------------------

// create file if empty and override data in file
void override_file(const string file_path, uint32_t new_data)
{
	ofstream out_file(file_path);
	if (!out_file) { cout << "I can't create the file!" << "\n"; }
	else { out_file << new_data; }
	out_file.close();
}

uint32_t get_file_score(const string file_path)
{
	uint32_t file_score = 0;
	// read data from file
	ifstream in_file(file_path);
	if (!in_file)
	{
		cout << "I will create a file called: " << file_path << "\n"
			<< "this is where we will keep our scores!\n";
		// initiate file to 0
		override_file(file_path, 0);
	}
	else { in_file >> file_score; }
	in_file.close();
	return file_score;
}

string get_ascii_art(const string file_path)
{
	ifstream in_file(file_path);
	string output = "";
	if (!in_file)
	{
		cout << "file not found\n";
		override_file(file_path, 0);
	}
	else
	{
		
		string line = "";
		while (getline(in_file, line))
		{
			output += line + "\n";
		}
	}
	return output;
	in_file.close();
}

// math functions ------------------------

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

// program end functions ------------------------

void press_enter_to_end()
{
	cout << "press enter to end\n";
	cin.ignore(1000, '\n');
}
