#include "Algorithm.h"


void Algorithm::Init() {
	num_people = RandomNumber();
	women = GenerateWomen(num_people);
	men = GenerateMen(num_people);
	WomensPref(women, men);
	MensPref(men, women);
	InitialRanks();
	Procedure(current);
}


void Algorithm::InitialRanks() {
	cout << "Our Initial Rankings" << endl;
		cout << "Women" << endl;
	for (const auto woman : women) {
		cout << woman.name << ": ";
		for (const auto man : woman.preferences) {
			cout << "Rank " << man.first << ": " << man.second << ", ";
		}
		cout << endl; 
	}
	cout << " ---------------------------------------------------------" << endl;
	cout << "Men" << endl;
	for (const auto man : men) {
		cout << man.name << ": ";
		for (const auto woman : man.preferences) {
			cout << "Rank " << woman.second  << ": " << woman.first << ", ";
		}
		cout << endl;
	}
	cout << " ---------------------------------------------------------" << endl;


}

void Algorithm::Proposal() {
	
	for (auto &woman : women) {
		cout << woman.name;
		// Add our woman to her top choice's offers list
		// only if she is unmatched
		if (woman.matched) {
			cout << " is matched" << endl;
			continue;
		}
		for (auto each : woman.preferences) {
			cout << ": rank " << each.first << ": "<< each.second << ", ";
		}
		cout << endl;

		auto it = std::find(men.begin(), men.end(),woman.preferences.begin()->second);
		if (it != men.end()) {
			it->offers.push_back(woman.name);
		}
		//Remove the top choice from the list so the woman doesn't repropose
		woman.preferences.erase(woman.preferences.begin());
	}

}

void Algorithm::Rejection() {
	// Iterate through each man checking his offers
	for (auto &man : men) {
		if (man.offers.empty()) {
			continue;
		}
		std::string pick;
		int best = women.size() + 1;
		for (auto &woman : man.offers) {
			// Each woman is unmatched as of right now
			auto it = std::find(women.begin(), women.end(), woman);
			if (it != women.end()) {
				it->matched = false;
			}
			auto preference = man.preferences.find(woman);
			if (preference != man.preferences.end()) {
				if (preference->second < best) {
					best = preference->second;
					pick = preference->first;
				}
			}
		}

		// Empty our Man's choices and re-populate with only his top choice
		man.offers.clear();
		man.offers.push_back(pick);
		// Let the woman know she has a match
		auto it = std::find(women.begin(), women.end(), pick);
		if (it != women.end()) {
			it->matched = true;
		}
	}
}


void Algorithm::Procedure(Matches &current) {
	bool all_stable = false;
	while (!all_stable) {
		all_stable = true;
		Proposal();
		Rejection();
		for (auto each : men) {
			if (!each.offers.empty()) {
				cout << each.name << " matches with " << each.offers.front() << endl;
				current[each.name] = each.offers.front();
			}
			else {
				cout << each.name << " has no matches" << endl;
			}
		}
		for (auto each : women) {
			if (each.matched == false) {
				all_stable = false;
			}
		}
		cout << "---------------End of round------------" << endl;
		cout << "Ready?" << endl;
		int x;
		cin >> x;
	}

}