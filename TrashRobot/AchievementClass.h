#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "TrashBotFunctions.h"


using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;
using std::cout;
using std::istream;
using std::ostream;
using std::getline;
using std::stringstream;
using std::stoul;

struct achieve
{
	uint32_t score_requirement = 0;
	string file_path = "";
	bool status = false;
};

class Achievements_cl
{
public:
	vector<achieve> achievements;

	// loads achievement into vector
	void load(string);
	// update status of achievement in vector
	void update_status(uint32_t score);
	// write updated achievements to file
	void write_achievements_status_to_file(string);
	// view achievements
	string get_obtained();

private:
	// achievements loading functions ----------------------------------------

	// extract a line of the csv file
	vector<achieve> extract_line(istream&);
	// extract cells of the line and place it into achievement vector
	void extract_cell(std::string, std::vector<achieve>&);

	// file write functions  ----------------------------------------

	void write_to_file(ostream& out_file);
};