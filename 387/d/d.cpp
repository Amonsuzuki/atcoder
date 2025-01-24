#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> map(h, vector<char>(w));
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin >> map[i][j];
			if (map[i][j] == S) {
				goalx = i;
				goaly = j;
			}
		}
	}

