/*
* trash bot app that collect points based on trash collection IRL!
*/

#include "TrashBotFunctions.h"
#include "AchievementClass.h"

int main()
{
	constexpr char trash_art_file_path[] = "Assets/TrashBotArt.txt";
	cout << "Hello! I am trash collector bot!\n"
		<< "Lets build a better future together by eliminating them trashes!\n"
		<< get_ascii_art(trash_art_file_path) << "\n\n"
		<< "every time you recycle or put away a peice of trash in real life, remember to come and log it here!\n"
		<< "you will gain points each time you log it! The more points the better!\n"
		<< "There are two achievements you can get based on the number of scores we got!\n\n";

	constexpr char score_file_path[] = "Assets/Scores.txt";

	constexpr char achievement_file_path[] = "Assets/AchievementsLog.csv";
	Achievements_cl achievements;
	achievements.load(achievement_file_path);

	while (true)
	{
		cout << "enter a number to record the number of trash you put away today\n"
			<< "enter 'score' to display current score\n"
			<< "ender 'a' to view our achievements!\n"
			<< "enter 'e' to end program\n\n";

		string input = string_input();
		if (valid_score_input(input))
		{
			uint32_t new_score = calculate_new_score(stoul(input), score_file_path);
			update_file_score(new_score, score_file_path);
			
			achievements.update_status(new_score);
			achievements.update_file(achievement_file_path);
		}
		else if (input == "score")
		{
			uint32_t score = get_file_score(score_file_path);
			cout << "your current score is: " << score << "\n\n";
		}
		else if (input == "e")
		{
			// end program
			cout << "that is all for now! Come again! Thank you! :D" << "\n";
			break;
		}
		else if (input == "a")
		{
			cout << "here are our achievements so far: \n\n";
			cout << achievements.get_obtained();
		}
		else
		{
			cout << "please retry input\n";
		}
	}

	press_enter_to_end();
	return 0;
}