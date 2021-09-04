#include <iostream>
#include <vector>
#include <fstream>

using std::ifstream;
using std::vector;
using std::string;

struct achieve
{
	uint32_t score_requirement = 0;
	string achivement_file_path = "";
	bool obtained = 0;
};

class Achievements_cl
{
public:
	vector<achieve> achievements;

	void load_achievements();
};