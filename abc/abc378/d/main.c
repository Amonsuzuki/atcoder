#include "am.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK 10000
/*
typedef struct {
	int x, y;
}Node;

typedef struct {
	Node data[MAX_STACK];
	int top;
} Stack;

void init_stack(Stack *s) {
	s->top = 0;
}

int empty(Stack *s) {
	return s->top == 0;
}

void push(Stack *s, Node value) {
	if (s->top >= MAX_STACK) {
		printf("Stack overflow\n");
		exit(1);
	}
	s->data[s->top++] = value;
}

Node pop(Stack *s) {
	if (empty(s)) {
		printf("Stack overflow\n");
		exit(1);
	}
	return (s->data[--s->top]);
}
*/

int H, W, K, ans = 0;

char map[10][10];
int visited[10][10];

int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};

void dfs(int i, int j, int cnt) {
	if (cnt == K) {
		ans++;
		return;
	}
	visited[i][j] = 1;
	for (int v = 0; v < 4; v++) {
		int ni = i + di[v], nj = j + dj[v];
		if (ni < 0 || nj < 0 || ni >= H || nj >= W)
			continue;
		if (map[ni][nj] == '#' || visited[ni][nj])
			continue;
		dfs(ni, nj, cnt + 1);
	}
	visited[i][j] = 0;
}


int main() {
	scanf("%d %d %d", &H, &W, &K);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) { 
			scanf(" %c", &map[i][j]);
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == '.') {
				dfs(i, j, 0);
			}
		}
	}
	printf("%d\n", ans);
}
/*
				





	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
	printf("\n");
}*/
