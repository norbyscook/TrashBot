/*
* trash bot app that collect points based on trash collection IRL!
*/

#include "TrashBotFunctions.h"
#include "AchievementClass.h"

int main()
{
	constexpr char trash_art_file_path[] = "Assets/TrashBotArt.txt";
			
	Achievements_cl Achievement;
	Achievement.load_achievements();
	cout << "Hello! I am trash collector bot!\n"
		<< "Lets build a better future together by eliminating them trashes!\n"
		<< get_ascii_art(trash_art_file_path)
		<< "every time you recycle or put away a peice of trash in real life, remember to come and log it here!\n"
		<< "you will gain points each time you log it! The more points the better!\n\n";

	constexpr char score_file_path[] = "Assets/Scores.txt";
	while (true)
	{
		cout << "enter a number to record the number of trash you put away today, enter 'score' to display current score\n"
			<< "enter 'e' to end program\n";

		string input = string_input();
		if (valid_score_input(input))
		{
			update_file_score(stoul(input), score_file_path);

		}
		else if (input == "score")
		{
			uint32_t score = get_file_score(score_file_path);
			cout << "your current score is: " << score << "\n";
		}
		else if (input == "e")
		{
			// end program
			cout << "that is all for now! Come again! Thank you! :D" << "\n";
			press_enter_to_end();
			break;
		}
		else
		{
			cout << "please retry input\n";
		}
	}
	return 0;
}