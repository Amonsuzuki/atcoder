#include <stdio.h>
#include <math.h>

long long int ans = 1;
int n, k;

long long int ft_pow(long long int a, long long int b) {
	long long int ans = 1;
	for (long long int i = 0; i < b; i++)
		ans *= a;
	return (ans);
}

int ft_log10(long long int a) {
	int digit = 0;
	while(a > 0) {
		a /= 10;
		digit++;
	}
	return (digit);
}

int main() {
	scanf("%d %d", &n, &k);
	long long int a, y = 1;
	for (int i = 0; i < k; i++)
		y *= 10;
	y--;

	for (int i = 0; i < n; i++) {
		scanf(" %lld", &a);
		if (ans > (y / a))
			ans = 1;
		else
			ans *= a;
		//printf("%lld\n", ans);
	}
	printf("%lld\n", ans);
}

/*
long long int ft_pow(long long int a, long long int b) {
	long long int ans = 1;
	for (long long int i = 0; i < b; i++)
		ans *= a;
	return (ans);
}

int main() {
	scanf("%lld %lld", &n, &k);
	long long int array[n];
	for (long long int i = 0; i < n; i++) {
		scanf(" %lld", &array[i]);
		double tmp_ans = ans;
		long long int increase = round(tmp_ans / ft_pow(10, digit - 1) * array[i]);
		long long int much = 10, count = 0;
		while (increase >= much) {
			count++;
			much *= 10;
		}
		digit += count;
		ans *= array[i];
		if (digit > k) {
			ans = 1;
			digit = 1;
		}

		//printf("%lld %lld\n", ans, digit);
	}
	printf("%lld\n", ans);
}

int main() {
	printf("%lld\n", ft_pow(2, 5));
}*/
