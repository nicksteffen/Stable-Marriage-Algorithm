#include "Population.h"

int RandomNumber() {
	srand(time(NULL));
	return (rand() % 15) + 1;
}

Man::Man(std::string name1)
{
	name = name1;

	std::map<std::string, int> empty_map;
	empty_map.clear();
	preferences = empty_map;

	std::deque<std::string> empty_deque;
	empty_deque.clear();
	offers = empty_deque;
}

Woman::Woman(std::string name1)
{
	name = name1;

	std::map<int, std::string> empty_map;
	empty_map.clear();
	preferences = empty_map;
}



std::deque<Woman> GenerateWomen(int num_people) {
	std::deque<Woman> the_deque;
	for (int i = 1; i <= num_people; i++) {
		Woman woman(to_string(i));
		the_deque.push_back(woman);
	}
	return the_deque;
}

std::deque<Man> GenerateMen(int num_people) {
	std::deque<Man> the_deque;
	for (int i = 1; i <= num_people; i++) {
		Man man(to_string(i + num_people));
		the_deque.push_back(man);
	}
	return the_deque;
}



void WomensPref(std::deque<Woman> &women, std::deque<Man> &men) {
	std::deque<Man> temp = men;
	for (auto &woman : women){
		std::random_shuffle(temp.begin(), temp.end());
		// generate a deque of men to which she will map to 
		std::map<int, std::string> preferences;
		int order = 1;
		for (auto choice : temp) {
			preferences[order]= choice.name;
			order++;
		}
		woman.preferences = preferences;

	}
}

void MensPref(std::deque<Man> &men, std::deque<Woman> &women) {
	std::deque<Woman> temp = women;
	for (auto &man : men){
		std::random_shuffle(temp.begin(), temp.end());
		// generate a deque of men to which she will map to 
		int order = 1;
		for (auto choice : temp) {
			man.preferences.insert(std::pair<std::string, int>(choice.name, order));
			order++;
		}
		
	}
}

