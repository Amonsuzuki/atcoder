#include "am.h"
#include <stdio.h>

#define SIZE 100001

ii array[SIZE];

int main() {
	long long int n, ans = 0;
	scanf("%lld", &n);
	for (long long int i = 2; i <= SIZE; i++) {
		long long int x = i * i;
		while(x <= n) {
			insert_ii_unordered(array, x, 1, SIZE);
			x *= i;
			/*
			int count = 0;
			for (int i = 0; i < 100001; i++)
				if (array[i].is_filled == 1)
					count++;
			printf("%d\n", count);
			*/
		}
	}
	for (long long int i = 0; i < SIZE; i++) {
		if (array[i].value == 1)
			ans++;
	}
	printf("%lld\n", n - ans);
}
