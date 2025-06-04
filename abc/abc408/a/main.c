#include "am.h"
#include <stdio.h>

int n, s;

int main() {
	scanf("%d %d", &n, &s);

	int t[n], previous = 0;
	for (int i = 0; i < n; i++) {
		scanf(" %d", &t[i]);
		if (t[i] - previous > s) {
			printf("No\n");
			return (0);
		}
		previous = t[i];
	}
	printf("Yes\n");
}
