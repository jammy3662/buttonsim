#include <basic.cpp>
using namespace std;

vector<int> btns;

int main();

double make_btn() {
	double percent;
	int luck = 4; // higher values = lower luck
	double seed = (double) randr(luck, luck * 100) / 100;
	double draw = log10(seed / luck);
	percent = draw * -50;
	return percent;
}

void btn_gen(int num) {
	for (int i = 1; i < num + 1; i += 1) {
		int chance = round(make_btn());
		btns.push_back(chance);
	}
}

void game(double gametime, bool debug) {
	double start = (double) time(NULL);
	int score = 0;
	btns = {};
	btn_gen(10);
	if (debug) {
		btns[0] = 100;
		for (int i = 0; i < btns.size(); i += 1) {
			cout << "Button " << i + 1 << ":  " << btns[i] << " %\n";
		}
		cout << RED << "NOTE: " << END << "Debug is on. To change this, change 'true' in " << GREEN << "game(12, " << BLUE << "true" << GREEN << ")" << END << " to 'false.'\n";
	}
	cout << "Start pressing buttons! You have " << gametime << " seconds.\n";
	while ((double) time(NULL) - start < gametime) {
		int button;
		cin >> button;
		if (button < 1 or button > 10) {
			cin.clear();
			string dump; cin >> dump;
			cout << "Invalid button (choose 1-10)  ";
			continue;
		}
		int chance = btns[button - 1];
		int draw = randr(0,100);
		if (debug) {
			cout << "Selected " << button << " with " << chance << "% chance.";
			cout << " Drew " << draw << "  ";
		}
		if (draw <= chance) {
			score += 1;
			cout << "Green hit! Your score increased to " << score << "!  ";
		} else {
			cout << "Red hit.  ";
		}
	}
	cout << "\nTime's up! Your score was " << score << ".\n";
	cout << "Continue? [y]  ";
	string cont;
	cin >> cont;
	if (cont == "y") { main(); }
}

int main() {
	basic(); // Basic setup
	cout << "Button Simulator\n";
	game(12, true);
	return 0;
}