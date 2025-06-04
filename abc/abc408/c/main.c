//#include "am.h"
#include <stdio.h>

int n, m;

typedef struct{
	int l;
	int r;
}set;

int main() {
	scanf("%d %d", &n, &m);
	int wall[n + 1];
	for (int i = 0; i < n + 1; i++)
		wall[i] = 0;
	//	printf("%d ", wall[i]);
	set g[m];
	for (int i = 0; i < m; i++) {
		scanf(" %d %d", &g[i].l, &g[i].r);
		wall[g[i].l]++;
		wall[g[i].r + 1]--;
	}
	int previous = 0, smallest = wall[1], index = 1;
	for (int i = 1; i < n + 1; i++) {
		wall[i] += previous;
		previous = wall[i];
		if (smallest > wall[i]) {
			smallest = wall[i];
			index = i;
		}
	}
	/*
	for (int i = 0; i < n + 1; i++) {
		printf("%d ", wall[i]);
	}
	*/
	printf("%d\n", smallest);
}
