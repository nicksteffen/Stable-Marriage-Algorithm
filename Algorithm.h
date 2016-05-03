#include "Population.h"



typedef std::map<std::string, std::string> Matches;

class Algorithm {
public:
	void Init();
	int num_people;
	std::deque<Woman> women;
	std::deque<Man> men;
	void Rejection();
	void Proposal();
	Matches current;
	void Procedure(Matches &current);
	void InitialRanks();

	

};