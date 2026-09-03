#include <iostream>
#include "IsPerfect.h"

using namespace std;

int main(int argc, char* argv[]) {
	long int MaxNumber;

	MaxNumber = GetMaxValue(argc, argv);

	for (long int lcv = 1; lcv <= MaxNumber; lcv++) {
		cout << lcv << "\r";

		if (IsPerfect(lcv)) {
			cout << lcv << " Perfect\n";
		}
		else if (IsWeird(lcv)) {
			cout << lcv << " Weird\n";
		}
	}

	cout << "                      \r";

	return 0;
}