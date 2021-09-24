#include <iostream>
#include <stdlib.h>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::strtoul;
using std::stoul;

bool is_int(char[]);

int main()
{
	char input[] = "4294967300";
	if (is_int(input))
	{
		cout << uint32_t(stoul(input)) << "\n";
	}
	else
	{
		cout << "not a valid number\n";
	}
	return 0;
}

bool is_int(char input[])
{
	char* endptr = 0;
	strtoul(input, &endptr, 10);
	return (*endptr == '\0' && input[0] != '\0');
}

