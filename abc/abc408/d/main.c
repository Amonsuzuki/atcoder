//#include "am.h"
#include <stdio.h>

int t;

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf(" %d", &n);
		char current;
		int previous = 0, currentstreak = 0, maxstreak = 0, total = 0;
		for (int j = 0; j < n; j++) {
			scanf(" %c", &current);
			if (current == '1')
				currentstreak++;
			else {
				if (previous)
					total += currentstreak;
					if (maxstreak < currentstreak)
						maxstreak = currentstreak;
				currentstreak = 0;
			}
			previous = current - '0';
		}
		printf("%d %d\n", total, maxstreak);
	}
};
