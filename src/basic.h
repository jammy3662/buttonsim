#include <time.h>
#include <cmath>

bool timer(time_t begin, time_t length) {
	bool running = true;
	running = time(NULL) - begin < length;
	return running;
}

int randr(int min, int max) {
	// Random int in range
	int rng = rand(); // Draw random number
	int result = (rng % max) + min; // Confine to given range
	return result;
}
