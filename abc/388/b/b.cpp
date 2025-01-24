#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;

	cin >> n >> d;
	vector<int> t(n), l(n);
	for (int i = 0; i < n; i++) 
		cin >> t[i] >> l[i];
	for (int i = 1; i < d + 1; i++) {
		int max = 0;
		for (int j = 0; j < n; j++) {
			if (t[j] * (l[j] + i) > max)
				max = t[j] * (l[j] + i);
		}
		cout << max << endl;
	}
}

