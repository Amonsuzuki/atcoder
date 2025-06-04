//#include "am.h"
#include <stdio.h>

int n;

int main() {
	scanf("%d", &n);
	int a[n], b[101] = {0}, size = 0;
	for (int i = 0; i < n; i++)
		scanf(" %d", &a[i]);
	for (int i = 0; i < n; i++) {
		b[a[i]]++;
	}
	for (int i = 0; i < 101; i++) {
		if (b[i] > 0)
			size++;
	}
	printf("%d\n", size);
	for (int i = 0; i < 101; i++) {
		if (b[i] > 0)
			printf("%d ", i);
	}
	printf("\n");
}
