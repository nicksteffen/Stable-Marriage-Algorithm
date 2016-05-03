#include "Algorithm.h"
#include <iostream>


int main(void) {
	cout << "Starting \n";
	Algorithm ex;
	ex.Init();
	for (auto each : ex.current) {
		cout << each.first << " : " << each.second << endl;
	}
	cout << "Done" << endl;

	return 0;
}