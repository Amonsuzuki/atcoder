#include "am.h"
#include <stdio.h>
#include <math.h>

int main() {
	double a, b;
	int c = 0;
	scanf("%lf %lf", &a, &b);
	c = round(a / b);
	printf("%d\n", c);
}
