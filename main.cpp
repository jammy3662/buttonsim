#include <basic.cpp>
using namespace std;

int make_buttons(int num) {
	for (int i = 0; i < num; i += 1) {
		int id = i;
		cout << id << "\n";
	}
	return 0;
}

int main() {
	cout << "Button Simulator\n";
	// make_buttons(1);
	cout << "\n";
	return 0;
}