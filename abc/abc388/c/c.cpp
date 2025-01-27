#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll total = 0;
	for (ll i = 0; i < n; i++) {
		auto it = lower_bound(a.begin() + i + 1, a.end(), 2 * a[i]);
		total += a.end() - it;
	}
	cout << total;
}

