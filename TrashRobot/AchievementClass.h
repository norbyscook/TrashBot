#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::istream;
using std::getline;
using std::stringstream;
using std::stoul;

struct achieve
{
	uint32_t score_requirement = 0;
	string file_path = "";
	bool obtained = false;
};

class Achievements_cl
{
public:
	vector<achieve> achievements;
	void load_achievements();

private:
	vector<achieve> update_achievement_vect(istream&);
};