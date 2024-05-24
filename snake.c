#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "conio.h"

int height = 30, width = 20;
int gameover, score;
int x, y, fruit_x, fruit_y, flag;

// generating fruit
void setup() {
	gameover = 0;
	x = height / 2;
	y = width / 2;

	label1:
		fruit_x = rand() % 20;
		if (fruit_x == 0)
			goto label1;
	label2:
		fruit_y = rand() % 20;
		if (fruit_y == 0)
			goto label2;
		score = 0;
}

// drawing boundaries
void draw() {
	system("clear");
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				printf("#");
			} else {
				if (i == x && j == y)
					printf("0");
				else if (i == fruit_x && j == fruit_y)
					printf("*");
				else
					printf(" ");
			} 
		}
		printf("\n");
	}
	printf("score = %d\n", score);
	printf("press x to quit the game\n");
}

// keybinds

void input() {
	if (kbhit()) {
		switch (getch()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			gameover = 2;
			break;
		}
	}
}

void logic() {
	sleep(0.01);
	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	if (x < 0 || x > height || y < 0 || y < 0 || y > width)
		gameover = 1;

	if (x == fruit_x && y == fruit_y) {
		label3:
			fruit_x = rand() % 20;
			if (fruit_x = 0)
				goto label3;

		label4:
			fruit_y = rand() % 20;
			if (fruit_y == 0)
				goto label4;
			score += 10;
	}
}

int main() {
	int m, n;
	setup();

	while (!gameover) {
		draw();
		input();
		logic();
	}
	
	return 0;
}
