#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<double> a(n);
	double mlti;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		if (i == 0)
			mlti = a[i+1] / a[i];
		if (i != 0 && a[i] != a[i-1] * mlti) {
			cout << "No" << endl;
			return (0);
		}
	}
	cout << "Yes" << endl;
}
