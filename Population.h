#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef std::map<std::string, std::map<int, std::string>> PreferenceMap;
// I chose a map here over unordered map because the algorithm relies more on 
// iterating through the map than on accessing individual members


class Woman {
public:
	Woman(std::string);
	std::string name;
	std::map<int, std::string> preferences;
	bool matched = false;
	bool operator==(const Woman &r) const {
		return name == r.name;
	}
};

class Man {
public:
	Man(std::string);
	std::string name;
	std::map<std::string, int> preferences;
	std::deque<std::string> offers;
	bool operator==(const Man &r) const {
		return name == r.name;
	}

};

int RandomNumber(); // limited to 15 people
std::deque<Woman> GenerateWomen(int num_people);
std::deque<Man> GenerateMen(int num_people);
void WomensPref(std::deque<Woman> &women, std::deque<Man> &men);
void MensPref(std::deque<Man> &men, std::deque<Woman> &women);
