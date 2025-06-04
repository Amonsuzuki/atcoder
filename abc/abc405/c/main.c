#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	long long int total = 0, current = 0;
	for (int i = 0; i < n; i++) scanf(" %d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		current += a[i];
		total += current * a[i + 1];
	}
	printf("%lld\n", total);
}
