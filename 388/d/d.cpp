#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) 
		cin >> a[i];
	vector<int> c(n), d(n+1);
	for (int i=0; i<n; i++) {
		if (i!=0) {
			c[i] = c[i-1] + d[i];
			a[i] += c[i];
		}
		int range = min(n - i - 1, a[i]);
		a[i] -= range;
		d[i+1]++;
		d[i + range + 1]--;
	}
	for (int i=0; i<n; i++) {
		if (i != n-1)
			cout << a[i] << ' ';
		else
			cout << a[i] << endl;
	}
}
