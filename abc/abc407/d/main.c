#include "am.h"
#include <stdio.h>

int h, w;

int main() {
	scanf("%d %d", h, w);
	int map[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			scanf(" %d", map[i][j]);
	}

