#include <stdio.h>

long long int n, ans = 0;

int main() {
	scanf("%d", &n);
	long long int a[n];
	long long int sign[201];
	for (int i = 0; i < 201; i++)
		sign[i] = 0;
	for (int i = 0; i < n; i++) {
		scanf(" %lld", &a[i]);
		a[i] = a[i] % 200;
	}
/*
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
*/
	for (int i = 0; i < n; i++) {
		sign[a[i]]++;
	}
/*
	for (int i = 0; i < 201; i++)
		printf("%d ", sign[i]);
	printf("\n");
*/
	for (int i = 0; i < 201; i++) {
		if (sign[i] > 1) {
			ans += (sign[i] - 1) * sign[i] / 2;
			//printf("%d %d %d\n", i, sign[i], ans);
		}
	}
	printf("%lld\n", ans);
}
