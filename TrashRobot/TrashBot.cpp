/*
* trash bot app that collect points based on trash collection IRL!
*/

#include "TrashBotFunctions.h"
#include "AchievementClass.h"

int main()
{
	constexpr char trash_art_file_path[] = "Assets/TrashBotArt.txt";
	constexpr char achievement_file_path[] = "Assets/AchievementsLog.csv";
	Achievements_cl achievements;
	achievements.load_achievements(achievement_file_path);
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
			uint32_t new_score = calculate_new_score(stoul(input), score_file_path);
			update_file_score(new_score, score_file_path);
			achievements.update_achievements_status(new_score);
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
			break;
		}
		else
		{
			cout << "please retry input\n";
		}
	}

	achievements.write_achievements_status_to_file(achievement_file_path);
	press_enter_to_end();
	return 0;
}