#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::stoul;

bool is_int(string);

int main()
{
	string input = "429496.7295";
	if (is_int(input))
	{
		cout << stoul(input) << "\n";
	}
	else
	{
		cout << "not a valid number\n";
	}
	return 0;
}

bool is_int(string input)
{
	stringstream chk_stream(input);
	uint32_t num = 0;
	return bool(chk_stream >> num);
}

