#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0;
	int current = 0;
	for (size_t i =0; i<s.size(); i++) {
		if (s[i] == 'O') {
			current++;
			if (current == k) {
				ans++;
				current = 0;
			}
		}
		if (s[i] == 'X')
			current = 0;
	}
	cout << ans << endl;
}
