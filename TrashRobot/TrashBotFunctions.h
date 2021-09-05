#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;
using std::stoul;
using std::getline;

// main score functions ------------------------------

uint32_t calculate_new_score(uint32_t, const char[]);
void update_file_score(uint32_t, const char[]);

// input functions ------------------------------

bool choice_input();
char letter_input();
string string_input();
bool valid_score_input(string);
bool is_intended_score(uint32_t);

// data type check functions ------------------------------

bool is_int_str(string input);

// score file functions ------------------------------

// create file if empty and override data in file
void override_file(const string, uint32_t);
uint32_t get_file_score(const string);

// ascii art functions ------------------------------

string get_ascii_art(const string);

// math functions ------------------------------

uint32_t limited_add(uint32_t, uint32_t);
uint32_t limited_multiply(uint32_t, uint32_t);
uint32_t clamp(uint32_t num, uint32_t upper);

// program end functions ------------------------------

void press_enter_to_end();