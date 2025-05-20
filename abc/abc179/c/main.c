#include "am.h"
#include <stdio.h>

int main() {
	int n, ans = 0;

	scanf("%d", &n);
	n--;
	for (int i = 1; i * i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if ((i * j) <= n) {
				if (i == j)
					ans++;
				else
					ans += 2;
			}
			//printf("%d %d %d\n", i, j, ans);
		}
	}
	printf("%d\n", ans);
}

