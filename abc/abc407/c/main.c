#include "am.h"
#include <stdio.h>
#include <stdlib.h>

int ans = 0;

int main() {
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	nread = getline(&line, &len, stdin);
	nread -= 2;
	int total = 0;
	for (int i = nread; i >= 0; i--) {
		int diff = line[i] - '0';
		ans += diff + 1;
		total += diff;
		if (i != 0) {
			line[i - 1] -= total % 10;
			if (line[i - 1] < 48)
				line[i - 1] += 10;
		}

		/*
		for (int j = 0; j < i; j++) {
			line[j] -= diff;
			if (line[j] < 48)
				line[j] += 10;
		}*/
		//printf("%d %d %d\n", i, diff, ans);
		//printf("%s\n", line);
	}
	printf("%d\n", ans);
		
	free(line);
}
