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

	// achievements loading functions ----------------------------------------

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

	// update status functions ----------------------------------------

	// set achievement status if requirement is met
	void set_achievement(achieve& element, uint32_t score)
	{
		if (score >= element.score_requirement)
		{
			cout << "\n!!! you have obtained a new achievement !!!\n\n";
			element.status = true;
		}
	}

	// file write functions  ----------------------------------------

	void write_to_file(ostream& out_file)
	{
		out_file << "score, path, status\n";
		for (auto element : loaded_achievements)
		{
			out_file << element.score_requirement << ",";
			out_file << element.file_path << ",";
			out_file << element.status << "\n";
		}
	}

public:
	// loads achievement from file into vector
	void load(string file_path)
	{
		ifstream in_file(file_path);
		if (!in_file) { cout << "I can't find achievement log file! in" << file_path << "\n"; }
		else { loaded_achievements = extract_line(in_file); }
		in_file.close();
	}
	// update status of achievement in vector
	void update_status(uint32_t score)
	{
		for (achieve& element : loaded_achievements)
		{
			if (element.status == false) { set_achievement(element, score); }
		}
	}

	// get obtained achievements
	string get_obtained()
	{
		string obtained = { "" };
		for (auto element : loaded_achievements)
		{
			if (element.status == true)
			{
				obtained += get_ascii_art(element.file_path) + "\n\n";
			}
		}
		if (obtained.size() < 1)
		{
			cout << "no achievement yet! we need more scores!\n\n";
		}
		return obtained;
	}

	// write updated achievements to file
	void update_file(string file_path)
	{
		ofstream out_file(file_path);
		string line = { "" };
		if (!out_file) { cout << "can't find " << file_path << "\n"; }
		else { write_to_file(out_file); }
		out_file.close();
	}


};

