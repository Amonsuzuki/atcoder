#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ll n, m, x;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	cin >> m;
	vector<int> b(m);
	for (auto &i : b)
		cin >> i;
	cin >> x;
	vector<int> available(x + 1, 1);
	for (int i=0; i<m; i++)
		available[b[i]] = 0;
	dp[0] = 1;
	for (int i=1; i<x + 1; i++) {
		int flg = 0;
		for (int j=0; j<n; j++) {
			if (i - a[j] >= 0 && available[i - a[j]] == 1) {
				flg = 1;
				break;
			}
		}
		if (!flg)
			available[i] = 0;
	}
	if (available[x] == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
		/*
	for (int i=0; i<x + 1; i++)
		cout << available[i] << ' ';
	cout << endl;
	*/
}
