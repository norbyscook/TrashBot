#include "AchievementClass.h"

// load achievements into vector
void Achievements_cl::load_achievements()
{
	string file_path = "Assets/AchievementsLog.txt";
	ifstream in_file(file_path);
	if (!in_file)
	{
		cout << "I can't find achievement log file! in" << file_path << "\n";
	}
	else
	{
		achievements = update_achievement_vect(in_file);
	}
	in_file.close();
}

vector<achieve> Achievements_cl::update_achievement_vect(istream& in_file)
{
	vector<string> line_elements(3);
	vector<achieve> vect;
	string line = { "" };
	getline(in_file, line);
	while (getline(in_file, line))
	{
		stringstream line_stream(line);
		string cell = { "" };
		for (size_t i = 0; getline(line_stream, cell, ','); i++)
		{
			try { line_elements.at(i) = cell; }
			catch (std::out_of_range oor) { cout << oor.what() << "\n"; }
		}
		vect.push_back({ stoul(line_elements[0]), line_elements[1], bool(stoul(line_elements[2])) });
	}
	return vect;
}