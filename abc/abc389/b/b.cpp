#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ll x, ans=0;
	cin >> x;
	for (int i=0; i<21; i++) {
		if (x / (i + 1) != 1)
			x = x / (i + 1);
		else {
			ans = i+1;
			break;
		}
	}
	cout << ans;
}

