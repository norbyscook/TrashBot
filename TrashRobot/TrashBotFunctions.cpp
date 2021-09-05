#include "TrashBotFunctions.h"

// main score functions ------------------------------------------

// calculate score based on trash amount
uint32_t calculate_new_score(uint32_t trash_amount, const char file_path[])
{
	uint32_t new_score = { clamp(limited_multiply(trash_amount, 3), 500) };

	cout << "score of " << new_score << " is added!\n";
	// add file score to new score
	uint32_t file_score = { get_file_score(file_path) };
	new_score = limited_add(new_score, file_score);
	cout << "your total score is now: " << new_score << "\n";

	return new_score;
}

void update_file_score(uint32_t new_score, const char file_path[])
{
	if (new_score == std::numeric_limits<uint32_t>::max())
	{
		cout << "WOW, you have reached the max amount of scores!!\n";
	}

	// update file data
	override_file(file_path, new_score);
}

// input functions ------------------------------------------

bool choice_input()
{
	char choice = { 0 };
	while (true)
	{
		choice = { letter_input() };
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

// data type check functions ------------------------------------------

bool is_int_str(string input)
{
	stringstream chk_stream(input);
	uint32_t num = 0;
	return bool(chk_stream >> num);
}

// score file functions ------------------------------------------

void override_file(const string file_path, uint32_t new_data)
{
	ofstream out_file(file_path);
	if (!out_file) { cout << "I can't create and write the file! at " << file_path << "\n"; }
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
		// initiate file to 0
		override_file(file_path, 0);
	}
	else { in_file >> file_score; }
	in_file.close();
	return file_score;
}

// ascii art functions ------------------------------------------

string get_ascii_art(const string file_path)
{
	ifstream in_file(file_path);
	string output = "";
	if (!in_file)
	{
		cout << "I can't find ascii art file! in" << file_path << "\n";
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

// math functions ------------------------------------

uint32_t limited_add(uint32_t addend_one, uint32_t addend_two)
{
	constexpr uint32_t limit = std::numeric_limits<uint32_t>::max();
	if (limit - addend_one > addend_two) { return addend_one + addend_two; }
	else { return limit; }
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

// program end functions ------------------------------------------

void press_enter_to_end()
{
	cout << "press enter to end\n";
	cin.ignore(1000, '\n');
}