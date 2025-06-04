#include <stdio.h>

void dfs(int v, int *seen, int in[][2]) {
	seen[v] = 1;
	for (int i = 0; i < 2; i++) {
		int v2 = in[v][i];
		if (seen[v2])
			continue;
		dfs(v2, seen, in);
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n != m) {
		printf("No\n");
		return (0);
	}
	int in[n + 1][2], seen[n + 1];
	for (int i = 0; i < n + 1; i++) {
		in[i][0] = -1;
		in[i][1] = -1;
		seen[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (in[a][0] == -1)
			in[a][0] = b;
		else if (in[a][1] == -1)
			in[a][1] = b;
		else {
			printf("No\n");
			return (0);
		}
		if (in[b][0] == -1)
			in[b][0] = a;
		else if (in[b][1] == -1)
			in[b][1] = a;
		else {
			printf("No\n");
			return (0);
		}

	}

	dfs(1, seen, in);
	for (int i = 1; i < n + 1; i++) {
		if (!seen[i]) {
			printf("No\n");
			return (0);
		}
	}
	printf("Yes\n");
}

