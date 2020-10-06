#include <basic.cpp>
using namespace std;

int main();

void waitthing() {
	double delay = (double) clock();
	while ((double) clock() - delay < 4) {
		// something
		double curtime = (double) clock();
		string inp;
		//cin >> inp;
	}
	cout << "we waited";
}

int main() {
	basic(); // Basic setup
	cout << "Button Simulator\n";
	waitthing();
	return 0;
}