#include <iostream>
#include <string>
#include <time.h>
#include <cmath>
#include <fstream>

using namespace std;

void file(int mode, char *title, char *text) {
	if (mode == 0) {
		// write
		ofstream out;
		out.open((char *) title);
		out << text;
		out.close();
	}
	if (mode == 1) {
		// read
	}
	
}

bool timer(time_t begin, time_t length) {
	bool running = true;
	running = time(NULL) - begin < length;
	return running;
}

void basic() {
	// Basic operations
	srand(time(NULL)); // Set the rng seed using the system clock
}

int randr(int min, int max) {
	// Random int in range
	int rng = rand(); // Draw random number
	int result = (rng % max) + min; // Confine to given range
	return result;
}

void randr_test(int row, int col, int min, int max) {
	// Run trials of randr function
	for (int i = 0; i < row; i += 1) {
		for (int i = 0; i < col; i += 1) {
			cout << randr(1,20) << "  ";
		}
		cout << "\n";
	}
}
