#include "am.h"
#include <stdio.h>

int a, b, c, d;

int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (a > c) {
		printf("Yes\n");
		return (0);
	}
	if (a < c) {
		printf("No\n");
		return (0);
	}
	else {
		if (b > d) {
			printf("Yes\n");
			return (0);
		}
		if (b < d) {
			printf("No\n");
			return (0);
		}
	}
}

