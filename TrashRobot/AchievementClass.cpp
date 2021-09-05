#include "AchievementClass.h"

// achievements loading functions ----------------------------------------

void Achievements_cl::load(string file_path)
{
	ifstream in_file(file_path);
	if (!in_file) { cout << "I can't find achievement log file! in" << file_path << "\n"; }
	else { achievements = extract_line(in_file); }
	in_file.close();
}

vector<achieve> Achievements_cl::extract_line(istream& in_file)
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

void Achievements_cl::extract_cell(std::string line, std::vector<achieve>& vect)
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

// status update functions ----------------------------------------

void Achievements_cl::update_status(uint32_t score)
{
	for (achieve& element : achievements)
	{
		if (element.status == false) { set_achievement(element, score); }
	}
}

void Achievements_cl::set_achievement(achieve& element, uint32_t score)
{
	if (score >= element.score_requirement)
	{
		cout << "\n!!! you have obtained a new achievement !!!\n\n";
		element.status = true;
	}
}

// file write functions  ----------------------------------------

void Achievements_cl::update_file(string file_path)
{
	ofstream out_file(file_path);
	string line = { "" };
	if (!out_file) { cout << "can't find " << file_path << "\n"; }
	else { write_to_file(out_file); }
	out_file.close();
}

void Achievements_cl::write_to_file(ostream& out_file)
{
	out_file << "score, path, status\n";
	for (auto element : achievements)
	{
		out_file << element.score_requirement << ",";
		out_file << element.file_path << ",";
		out_file << element.status << "\n";
	}
}

// view achievement functions ----------------------------------------
string Achievements_cl::get_obtained()
{
	string obtained = { "" };
	for (auto element : achievements)
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