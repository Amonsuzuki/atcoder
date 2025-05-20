#include "am.h"
#include <stdio.h>
#include <math.h>

double a, b;
double value;
/*
int main() {
	scanf("%le %le", &a, &b);
	long long value = round(pow((2.0 * b / a), - (2.0 / 3.0)) - 1.0);
	if (value < 0)
		value = 0;
	printf("%f\n", a * pow(1 + value, -0.5) + b * value);
}
*/

#define SIZE 0
long long values[SIZE * 2 + 1];

double cal(long long value) {
	return (a * pow(1 + value, -0.5) + b * value);
}

int main() {
	scanf("%le %le", &a, &b);
	long long value = round(pow((2.0 * b / a), - (2.0 / 3.0)) - 1.0);
	if (value < 0)
		value = 0;


	for (int i = 0; i < SIZE; i++) {
		values[i] = value - (SIZE - i);
		if (values[i] < 0)
			values[i] = 0;
	}
	values[SIZE] = value;
	for (int i = 0; i < SIZE; i++)
		values[SIZE + 1 + i] = value + 1 + i;
	double min = cal(value);
	for (int i = 0; i < SIZE * 2 + 1; i++) {
		if (cal(values[i]) < min)
			min = cal(values[i]);
		//printf("%lld %f\n", values[i], cal(values[i]));
	}

	printf("%f\n", min);
}
