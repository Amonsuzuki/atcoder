#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> row(n);
	for (int i = 0; i < n; i++) {
		int count = 0;
		string s[m];
		for (int j = 0; j < m; j++) {
			cin >> s[j];
			if (s[i] == 'o')
				count++;
		}
		row[i] = count;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (row[i] == 5)
			ans += n - i - 1;
		if (row[i] == 4)
			ans += 
