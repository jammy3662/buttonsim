#include <iostream>
#include <string>
#include <ansi.h>
#include <basic.h>
#include <zsdl.h>
#include <unistd.h>
using namespace std;

uint8_t* btns;
uint8_t btn_count;

int main();

double make_btn() {
	double percent;
	int luck = 4; // higher values = lower luck
	double seed = (double) randr(luck, luck * 100) / 100;
	double draw = log10(seed / luck);
	percent = draw * -50;
	if (percent < 1) {percent = 1;}
	return percent;
}

void btn_gen(uint8_t num) {
	btns = (uint8_t*) malloc(num);
	btn_count = num;
	for (uint8_t i = 0; i < num; i += 1) {
		uint8_t chance = (uint8_t) round(make_btn());
		*(btns + i) = chance;
	}
}

void game(double gametime, bool debug, bool verbose) {
	time_t start = time(NULL);
	uint8_t score = 0;
	btn_gen(10);
	if (debug) {
		*(btns) = (uint8_t) 100;
		for (uint8_t i = 0; i < btn_count; i += 1) {
			string post;
			if (i % 2 == 1) {
				post = "%\n";
			} else {
				post = "%    ";
			}
			cout << "Button " << i + 1 << ":  " << (int) *(btns + i) << post;
		}
		cout << RED << "\nNOTE: " << END << "Debug is on. To change this, change 'true' in " << GREEN << "game(12, " << BLUE << "true" << GREEN << ")" << END << " to 'false.'\n";
	}
	cout << "Start pressing buttons! You have " << gametime << " seconds.  ";
	while (timer(start, (time_t) gametime)) {
		char number[2];
		cin >> number;
		int num = atoi(number);
		if (!(num > 0 && num < 11)) {
			cout << "Invalid button (choose 1-10)  ";
			cin.clear();
			continue;
		}
		uint8_t chance = *(btns + (num - 1));
		uint8_t draw = (uint8_t)randr(1,100);
		if (verbose) {
			cout << "Selected " << num << " with " << (int) chance << "% chance.";
			cout << " Drew " << (int) draw << "  ";
		}
		if (draw <= chance) {
			score += 1;
			cout << "Green hit! Your score increased to " << (int) score << "!  ";
		} else {
			cout << "Red hit.  ";
		}
	}
	cout << "\nTime's up! Your score was " << (int) score << ".\n";
	cout << "Continue? [y]  ";
	string cont;
	cin >> cont;
	if (cont == "y") { main(); }
}

sdlwindow display() {
	sdlwindow window;
	return window;
}

int main() {
	srand(time(NULL)); // Seed rng with system clock
	cout << "Button Simulator\nCurrent process id:  " << getpid() << NL;
	game(20, true, false);
	return 0;
}
