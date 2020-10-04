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

int main() {
	basic(); // Basic setup
	cout << "Button Simulator\n";
	btn_gen(10);
	for (int i = 0; i < btns.size(); i += 1) {
		cout << btns[i] << "\n";
	}
	return 0;
}