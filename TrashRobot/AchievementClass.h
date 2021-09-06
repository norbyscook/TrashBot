#include "TrashBotFunctions.h"
#include <vector>

using std::vector;
using std::istream;
using std::ostream;

class Achievements_cl
{
private:
	struct achieve
	{
		uint32_t score_requirement = 0;
		string file_path = "";
		bool status = false;
	};

	vector<achieve> loaded_achievements;

	// extract a line of the csv file
	vector<achieve> extract_line(istream& in_file)
	{
		vector<achieve> vect;
		string line = { "" };
		getline(in_file, line);
		while (getline(in_file, line))
		{
			extract_cell(line, vect);
		}
		return vect;
	}
	// extract cells of the line and place it into achievement vector
	void extract_cell(std::string line, std::vector<achieve>& vect)
	{
		vector<string> line_elements(3);
		stringstream line_stream(line);
		string cell = { "" };
		for (size_t i = 0; getline(line_stream, cell, ','); i++)
		{
			try { line_elements.at(i) = cell; }
			catch (std::out_of_range oor) { cout << oor.what() << "\n"; }
		}
		vect.push_back({ stoul(line_elements[0]), line_elements[1], bool(stoul(line_elements[2])) });
	}

	// set achievement status if requirement is met
	void set_achievement(achieve&, uint32_t);

	void write_to_file(ostream& out_file);

public:
	// loads achievement from file into vector
	void load(string);
	// update status of achievement in vector
	void update_status(uint32_t score);
	// get obtained achievements
	string get_obtained();
	// write updated achievements to file
	void update_file(string);
};