//#include "am.h"
#include <stdio.h>

int n;

int main() {
	scanf("%d\n", &n);
	long long int a[n], total = 1;
	for (int i = 0; i < n; i++) {
		scanf(" %lld", &a[i]);
		if (a[i] == 0) {
			printf("0\n");
			return (0);
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] > 1000000000000000000 / total) {
			printf("-1\n");
			return (0);
		}
		total *= a[i];
	}
	printf("%lld\n", total);
}
