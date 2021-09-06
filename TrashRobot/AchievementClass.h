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
	vector<achieve> extract_line(istream& in_file);
	// extract cells of the line and place it into achievement vector
	void extract_cell(std::string line, std::vector<achieve>& vect);

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
