#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	int count = 0;
	for (int i=0;i<n && count < d; i++) {
		if (s[n - 1 - i] == '@') {
			s[n - 1 - i] = '.';
			count++;
		}
	}
	cout << s;
}

