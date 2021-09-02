#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string file_path = "out.txt";
	
	int num = 12;

	ifstream in_file(file_path);
	// read in and update dog
	if (in_file.is_open())
	{
		int file_data = 0;
		in_file >> file_data;
		cout << "file data: " << file_data << endl;
		num += file_data;
		cout << "new number: " << num << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}
	in_file.close();
	
	ofstream out_file(file_path);
	// write and update file
	if (out_file.is_open())
	{
		out_file << num;
	}
	else
	{
		cout << "ERROR" << endl;
	}

	out_file.close();
}