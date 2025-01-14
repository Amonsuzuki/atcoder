#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, x, y, count = 0;

	cin >> h >> w >> x >> y;
	vector<vector<char>> map(h, vector<char>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++)
			cin >> map[i][j];
	}
	string t;
	cin >> t;
	x--;
	y--;
	if (map[x][y] == '@') {
		map[x][y] = '.';
		count = 1;
	}
	for (int i = 0; t[i] != '\0'; i++) {
		if (t[i] == 'L' && (y - 1 >= 0) && (map[x][y - 1] != '#')) {
			y--;
			if (map[x][y] == '@') {
				map[x][y] = '.';
				count++;
			}
		}
		else if (t[i] == 'R' && (y + 1 <= w) && (map[x][y + 1] != '#')) {
			y++;
			if (map[x][y] == '@') {
				map[x][y] = '.';
				count++;
			}
		}
		else if (t[i] == 'D' && (x + 1 <= h) && (map[x + 1][y] != '#')) {
			x++;
			if (map[x][y] == '@') {
				map[x][y] = '.';
				count++;
			}
		}
		else if (t[i] == 'U' && (x - 1 >= 0) && (map[x - 1][y] != '#')) {
			x--;
			if (map[x][y] == '@') {
				map[x][y] = '.';
				count++;
			}
		}
	}
	x++;
	y++;
	cout << x << " " << y << " " << count << endl;
	return (0);
}






