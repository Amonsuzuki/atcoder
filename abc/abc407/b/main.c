#include "am.h"
#include <stdio.h>

long double mother = 36.0;
int ans = 0;

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			if ((i + j) >= x)
				ans++;
		}
	}

	for (int i = 1; i < 7; i++) {
		for (int j = i; j < 7; j++) {
			if ((i + j) < x) {
				if ((j - i) >= y) {
					if (i == j)
						ans++;
					else
						ans += 2;
				}
			}
		}
	}
	printf("%.20Lf\n", ans / mother);
}

