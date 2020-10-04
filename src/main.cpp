#include <basic.cpp>
using namespace std;

vector<int> btns;

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

void game(double gametime) {
	double start = (double) time(NULL);
	int score = 0;
	cout << "Start pressing buttons! You have " << gametime << " seconds.\n";
	while ((double) time(NULL) - start < gametime) {
		int button;
		cin >> button;
		int choice = button % 10;
		int chance = btns[choice];
		int draw = randr(0,100);
		if (draw <= chance) {
			score += 1;
			cout << "Green hit! Your score increased to " << score << "!  ";
		} else {
			cout << "Red hit.  ";
		}
	}
	cout << "Time's up! Your score was " << score << ".\n";
	cout << "Enter to quit";
	cin;
	cout << "\n";
}

int main() {
	basic(); // Basic setup
	cout << "Button Simulator\n";
	btn_gen(10);
	for (int i = 0; i < btns.size(); i += 1) {
		cout << "Button " << i + 1 << ":  " << btns[i] << " %\n";
	}
	game(12);
	return 0;
}