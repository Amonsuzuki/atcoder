#include "am.h"
#include <stdio.h>

void digits(long long int input, long long int layer, long long int *digit) {
	long long int amaris[layer];
	long long int cycle, amari, i;
	long long int initial_layer = layer;

	i = 1;
	cycle = input / 5;
	amari = input % 5 - 1;
	if (amari < 0)
		amari = 4;
	amaris[0] = digit[amari];
	while (cycle >= 1) {
		cycle /= 5;
		amari = cycle % 5;
		amaris[i] = digit[amari];
		//cycle /= 5;
		layer++;
		i++;
		printf("%lld, %lld, %lld\n", layer - initial_layer + 1, cycle, digit[amari]);
	}
	for (long long int i = initial_layer - 1; i >= 0; i--)
		printf("%lld", amaris[i]);
}


int main() {
	long long int input, cycle, amari;
	long long int layer = 1;
	long long int answer = 0;
	long long int digit[] = {0, 2, 4, 6, 8};

	scanf("%lld", &input);
	printf("0, %lld\n", input);
	cycle = input / 5;
	amari = input % 5;
	printf("1, %lld\n", cycle);
	while (cycle >= 1) {
		amari = cycle % 5;
		cycle /= 5;
		layer++;
		//printf("%lld, %lld\n", layer, cycle);
	}
	digits(input, layer, digit);
	answer += 0;
	
	printf("\n");
	(void)amari;
}
