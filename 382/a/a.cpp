#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, d, count = 0;
	cin >> n >> d;
	vector<char> s(n);
	rep(i, n) {
		cin >> s[i];
		if (s[i] == '@')
			count++;
	}
	cout << n - count + d;
}

