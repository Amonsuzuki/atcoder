#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> t(n), v(n);
	cin >> t[0] >> v[0];
	int total = v[0];
	for (int i = 1; i < n; i++) {
		cin >> t[i] >> v[i];
		total = total - (t[i] - t[i - 1]);
		if (total < 0)
			total = 0;
		total = total + v[i];
	}
	cout << total;
}

