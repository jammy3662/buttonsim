#include <iostream>
#include <string>

using namespace std;

int randr(int min, int max) { // Random number within range
	int rng = rand();
	int result = (rng % max) + min;
	/*
	cout << rng << " % (";
	cout << max - min << ") + " << min;
	cout << "\n" << rng % (max - min) << " + " << min;
	cout << "\n" << result;
	cout << "\n~~~~~~\n";
	*/
	return result;
}

int randr_test(int trials, int count, int min, int max) {
	for (int i = 0; i < trials; i += 1) {
		for (int i = 0; i < count; i += 1) {
			cout << randr(1,20) << "   ";
		}
		cout << "\n";
	}
	return 0;
}