#include <stdio.h>
#include <stdlib.h>

#include "conio.h"

int height = 30;
int width = 30, gameover, score;

void draw() {
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				printf("#");
			} else {
				printf(" ");
			} 
		}
		printf("\n");
	}
}

int main() {
	draw();

	
	return 0;
}
