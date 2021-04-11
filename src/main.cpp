#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansi.h"
#include "basic.h"
#include <unistd.h>

#define reward 5

int* btns;
int btn_count;

int make_btn() {
	double percent;
	int luck = 4; // higher values = lower luck
	double seed = (double) randr(luck, luck * 100) / 100;
	double draw = log10(seed / luck);
	percent = draw * -50;
	if (percent < 1) {percent = 1;}
	return round(percent);
}

void btn_gen(int num) {
	btns = (int*) malloc(num * sizeof(int));
	btn_count = num;
	for (int i = 0; i < num; i++) {
		btns[i] = make_btn();
	}
}

int game(double gametime, bool debug = false) {
	time_t start = time(NULL);
	int score = 0;
	btn_gen(10);
	if (debug) {
		btns[0] = 100;
		for (int i = 0; i < btn_count; i++) {
			printf("Button %i: %i\n", i + 1, btns[i]);
		}
		printf("\nNOTE: Debug is on.\n");
	}
	printf("Start pressing buttons! You have %i seconds.  ", (int)(gametime));
	int valid = true;
	while (timer(start, (time_t) gametime)) {
		char number[3];
		fgets(number, 3, stdin);
		int num = atoi(number);
		if (num < 1 || num > 10) {
			if (valid) printf("Choose 1-%i  ", btn_count);
			valid = false;
			continue;
		}
		valid = true;
		int chance = btns[num - 1];
		int draw = randr(1,100);
		if (draw <= chance) {
			score += reward;
			printf("Green hit! Your score increased to %i!  ", score);
		} else {
			printf("Red hit.  ");
		}
	}
	printf("\nTime's up! Your score was %i.\n", score);
	return score;
}

int main(int argc, char** argv) {
	srand(time(NULL)); // Seed rng with system clock
	printf("Button Simulator\n");
	bool debug = false;
	if (argv[1] != NULL) debug = true;
	return game(12, debug);
}
