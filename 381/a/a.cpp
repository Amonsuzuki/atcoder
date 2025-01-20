#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	if (n%2 == 0) {
		cout << "No";
		return (0);
	}
	string s;
	cin >> s;
	if (s[(n+1)/2 - 1] != '/') {
		cout << "No";
		return (0);
	}
	for (int i=0; i<(n+1)/2 - 1; i++) {
		if (s[i] != '1') {
			cout << "No";
			return (0);
		}
	}
	for (int i=(n+1)/2; i<n; i++) {
		if (s[i] != '2') {
			cout << "No";
			return (0);
		}
	}
	cout << "Yes";
}
