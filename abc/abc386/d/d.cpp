#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	bool out = false;
	cin >> n >> m;
	vector<int> x(m), y(m);
	vector<char> c(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i] >> c[i];
		x[i]--;
		y[i]--;
	}
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < m; i++) {
		if (c[i] == 'W')
			map[x[i]][y[i]] = 1;
	}
	for (int i = 0; i < m && !out; i++) {
		if (c[i] == 'B') {
			if (x[i] == 0) {
				for (int j = 0; j <= y[i]; j++) {
					if (map[0][j] == 1) {
						out = true;
						break;
					}
				}
			}
			else if (y[i] == 0) {
				for (int j = 0; j <= x[i]; j++) {
					if (map[j][0] == 1) {
						out = true;
						break;
					}
				}
			}
			else {
				for (int k = 0; k <= x[i] && !out; k++) {
					for (int l = 0; l <= y[i]; l++) {
						if (map[k][l] == 1) {
							out = true;
							break;
						}
					}
				}
			}
		}
	}
	if (!out)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return (0);
}


